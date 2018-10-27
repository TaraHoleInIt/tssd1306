/**
 * Copyright (c) 2018 Tara Keeling
 *
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include <string.h>
#include <stdlib.h>
#include <alloca.h>
#include <avr/pgmspace.h>
#include "ssd1306.h"
#include "glcd_font.h"

#define NullCheckAndAssign( ptr, value ) { \
    if ( ptr != NULL ) { \
        *ptr = value; \
    } \
}

static void SSD1306_WriteDataPGM( const uint8_t* Data, size_t Length );
static void SSD1306_WriteDataEEPROM( const uint8_t* Address, size_t Length );
static void SSD1306_WriteDataLocal( const uint8_t* Data, size_t Length );

static uint8_t GlyphReadEEPROM( const uint16_t Offset );
static uint8_t GlyphReadPROGMEM( const uint8_t* Address );
static uint8_t GlyphReadByte( const uint32_t Offset );

static int GetGlyphInfo( const char c, int* OutGlyphWidth, uint16_t* OutGlyphOffset );

static const GLCD_FontDef* CurrentFont = NULL;
const I2CProcs* I2C = NULL;

static SSD_COLOR PrintColor = SSD_COLOR_WHITE;
static int PrintX = 0;
static int PrintY = 0;

#if defined HAS_DEBUG
    __attribute__( ( weak ) ) void DebugPrintString( const char* Text, ... ) {
    }
#endif

#if defined PatternBufferSize
static uint8_t PatternBuffer[ PatternBufferSize ];
#endif

void SSD1306_WriteData( DataSource Source, const uint8_t* Data, size_t Length ) {
    switch ( Source ) {
        case DataSource_Local: {
            SSD1306_WriteDataLocal( Data, Length );
            break;
        }
        case DataSource_Progmem: {
            SSD1306_WriteDataPGM( Data, Length );
            break;
        }
        case DataSource_EEPROM: {
            SSD1306_WriteDataEEPROM( Data, Length );
            break;
        }
        default: return;
    };
}

static void SSD1306_WriteDataLocal( const uint8_t* Data, size_t Length ) {
    const uint8_t WriteIsData = SSD1306_I2C_Data;
    int MaxBytesToWrite = I2C->TXBufferLen - 1;
    int BytesToWrite = 0;

    while ( Length > 0 ) {
        BytesToWrite = ( Length > MaxBytesToWrite ) ? MaxBytesToWrite : Length;

        I2C->StartTransmission( DisplayAddress );
            I2C->Write( &WriteIsData, sizeof( const uint8_t ) );
            I2C->Write( Data, BytesToWrite );
        I2C->EndTransmission( );

        Length-= BytesToWrite;
        Data+= Length;
    }
}

static void SSD1306_WriteDataPGM( const uint8_t* Data, size_t Length ) {
#if ! defined PatternBufferSize
    while ( Length > 0 ) {
        SSD1306_WriteDataByte( pgm_read_byte( Data ) );

        Length--;
        Data++;
    }
#else
    int BytesToWrite = 0;

    while ( Length > 0 ) {
        BytesToWrite = ( Length > PatternBufferSize ) ? PatternBufferSize : Length;

        memcpy_P( PatternBuffer, Data, BytesToWrite );
        SSD1306_WriteData( 0, PatternBuffer, BytesToWrite );

        Length-= BytesToWrite;
        Data+= BytesToWrite;
    }
#endif
}

static void SSD1306_WriteDataEEPROM( const uint8_t* Address, size_t Length ) {
#if ! defined PatternBufferSize
    size_t i = 0;

    for ( i = 0; i < Length; i++ ) {
        SSD1306_WriteDataByte( I2C->EEPROMReadByte( ( ( uint16_t ) Address ) + i ) );
    }
#else
    int BytesToWrite = 0;

    while ( Length > 0 ) {
        BytesToWrite = ( Length > PatternBufferSize ) ? PatternBufferSize : Length;

        I2C->EEPROMRead( ( const uint16_t ) Address, PatternBuffer, BytesToWrite );
        SSD1306_WriteData( DataSource_Local, PatternBuffer, BytesToWrite );

        Length-= BytesToWrite;
        Address+= BytesToWrite;
    }
#endif
}

void SSD1306_WriteDataByte( const uint8_t Data ) {
    const uint8_t WriteIsData = SSD1306_I2C_Data;

    I2C->StartTransmission( DisplayAddress );
        I2C->Write( &WriteIsData, sizeof( const uint8_t ) );
        I2C->Write( &Data, sizeof( const uint8_t ) );
    I2C->EndTransmission( );
}

void SSD1306_SendSingleByteCommand( const uint8_t Command ) {
    const uint8_t WriteIsCommand = SSD1306_I2C_Command;

    I2C->StartTransmission( DisplayAddress );
        I2C->Write( &WriteIsCommand, sizeof( const uint8_t ) );
        I2C->Write( &Command, sizeof( const uint8_t ) );
    I2C->EndTransmission( );
}

void SSD1306_SendDoubleByteCommand( const uint8_t Command, const uint8_t Param0 ) {
    const uint8_t WriteIsCommand = SSD1306_I2C_Command;

    I2C->StartTransmission( DisplayAddress );
        I2C->Write( &WriteIsCommand, sizeof( const uint8_t ) );
        I2C->Write( &Command, sizeof( const uint8_t ) );
        I2C->Write( &Param0, sizeof( const uint8_t ) );
    I2C->EndTransmission( );
}

void SSD1306_SendTripleByteCommand( const uint8_t Command, const uint8_t Param0, const uint8_t Param1 ) {
    const uint8_t WriteIsCommand = SSD1306_I2C_Command;

    I2C->StartTransmission( DisplayAddress );
        I2C->Write( &WriteIsCommand, sizeof( const uint8_t ) );
        I2C->Write( &Command, sizeof( const uint8_t ) );
        I2C->Write( &Param0, sizeof( const uint8_t ) );
        I2C->Write( &Param1, sizeof( const uint8_t ) );
    I2C->EndTransmission( );
}

static void SSD1306_WritePattern( const uint8_t PatternByte, size_t Length ) {
#if ! defined PatternBufferSize
    while ( Length > 0 ) {
        SSD1306_WriteDataByte( PatternByte );
        Length--;
    }
#else
    size_t LengthRemaining = Length;
    size_t BufferLength = 0;
    int i = 0;

    for ( i = 0; i < PatternBufferSize; i++ ) {
        PatternBuffer[ i ] = PatternByte;
    }

    while ( LengthRemaining ) {
        BufferLength = ( LengthRemaining > PatternBufferSize ) ? PatternBufferSize : LengthRemaining;
        SSD1306_WriteData( 0, PatternBuffer, BufferLength );
        LengthRemaining-= BufferLength;
    }
#endif
}

void SSD1306_Clear( const uint8_t Pattern ) {
    size_t DisplaySize = ( DisplayWidth * DisplayHeight ) / 8;

    SSD1306_SendTripleByteCommand( SSD1306_Op_SetColumnAddress, 0, DisplayWidth - 1 );
    SSD1306_SendTripleByteCommand( SSD1306_Op_SetPageAddress, 0, DisplayPages - 1 );

    SSD1306_WritePattern( Pattern, DisplaySize );

    PrintX = 0;
    PrintY = 0;
}

void SSD1306_DrawPixel( const int x, const int y, const SSD_COLOR Color ) {
    int YBit = ( y & 0x07 );
    int Page = ( y / 8 );

    if ( x < 0 || x >= DisplayWidth || y < 0 || y >= DisplayHeight ) {
        DebugPrintString( "Clipped pixel at %d,%d\n", x, y );
        return;
    }

    SSD1306_SendTripleByteCommand( SSD1306_Op_SetColumnAddress, x, x );
    SSD1306_SendTripleByteCommand( SSD1306_Op_SetPageAddress, Page, Page );

    SSD1306_WriteDataByte( ( Color ) ? BIT( YBit ) : 0 );
}

void SSD1306_DrawHLine( const int x0, const int y, const int x1, const SSD_COLOR Color ) {
    int Width = ( x1 - x0 ) + 1;
    int YBit = ( y & 0x07 );

    if ( x0 < 0 || x0 >= DisplayWidth || x1 < x0 || x1 >= DisplayWidth || y < 0 || y >= DisplayHeight ) {
        DebugPrintString( "HLine clipped at %d,%d width %d\n", x0, y, Width );
        return;
    }

    SSD1306_SendTripleByteCommand( SSD1306_Op_SetPageAddress, y / 8, y / 8 );
    SSD1306_WritePattern( ( Color ) ? BIT( YBit ) : 0, Width );
}

void SSD1306_DrawVLine( const int x, const int y0, const int y1, const SSD_COLOR Color ) {
    uint8_t ColBuffer[ DisplayPages ];
    int StartYPage = ( y0 / 8 );
    int EndYPage = ( y1 / 8 );
    int NumPages = ( EndYPage - StartYPage ) + 1;
    int YByte = 0;
    int YBit = 0;
    int y = 0;

    if ( x < 0 || x >= DisplayWidth || y0 < 0 || y0 >= DisplayHeight || y1 < y0 || y1 >= DisplayHeight ) {
        DebugPrintString( "VLine clipped at %d,%d height: %d\n", x, y0, ( y1 - y0 ) );
        return;
    }

    SSD1306_SendTripleByteCommand( SSD1306_Op_SetColumnAddress, x, x );
    SSD1306_SendTripleByteCommand( SSD1306_Op_SetPageAddress, StartYPage, EndYPage );

    memset( ColBuffer, 0, sizeof( ColBuffer ) );

    for ( y = y0; y <= y1; y++ ) {
        YByte = ( y / 8 );
        YBit = ( y & 0x07 );

        ColBuffer[ YByte ] |= BIT( YBit );
    }

    SSD1306_WriteData( DataSource_Local, ColBuffer, NumPages );
}

void SSD1306_FillRect( const int x0, const int y0, const int x1, const int y1, const SSD_COLOR Color ) {
    int Width = ( x1 - x0 ) + 1;
    int Height = ( y1 - y0 ) + 1;
    int FillSize = 0;

    if ( x0 < 0 || x0 >= DisplayWidth || x1 < 0 || x1 >= DisplayWidth || y0 < 0 || y0 >= DisplayHeight || y1 < 0 || y1 >= DisplayHeight ) {
        DebugPrintString( "FillRect: Clipped at %d,%d to %d,%d\n", x0, y0, x1, y1 );
        return;
    }

    /* Always round up to a multiple of 8 due to how pages work */
    /* Should be done on y coordinates? */
    Height = ( Height + 7 ) & ~7;

    FillSize = ( Width * Height ) / 8;

    SSD1306_SendTripleByteCommand( SSD1306_Op_SetColumnAddress, x0, x1 );
    SSD1306_SendTripleByteCommand( SSD1306_Op_SetPageAddress, ( y0 / 8 ), ( y1 / 8 ) );

    SSD1306_WritePattern( ( Color == SSD_COLOR_WHITE ) ? 0xFF : 0x00, FillSize );
}

static uint8_t GlyphReadEEPROM( const uint16_t Offset ) {
    return I2C->EEPROMReadByte( Offset );
}

static uint8_t GlyphReadPROGMEM( const uint8_t* Address ) {
    return pgm_read_byte( Address );
}

static uint8_t GlyphReadByte( const uint32_t Offset ) {
    return ( CurrentFont->IsExternal == true ) ? GlyphReadEEPROM( Offset ) : GlyphReadPROGMEM( &CurrentFont->Data[ Offset ] );
}

static int GetGlyphInfo( const char c, int* OutGlyphWidth, uint16_t* OutGlyphOffset ) {
    uint16_t GlyphOffset = 0;
    int GlyphWidth = 0;
    int GlyphYBytes = 0;
    int GlyphSize = 0;
    int i = 0;

    if ( c < CurrentFont->FirstChar || c > CurrentFont->LastChar ) {
        return 0;
    }

    GlyphYBytes = ( CurrentFont->FontHeightPxRoundedUp / 8 );

    if ( CurrentFont->IsStream == true ) {
        for ( i = 0; i < ( c - CurrentFont->FirstChar ); i++ ) {
            GlyphWidth = GlyphReadByte( GlyphOffset );
            GlyphSize = ( ( GlyphWidth * GlyphYBytes ) ) + 1;
            GlyphOffset+= GlyphSize;
        }

        NullCheckAndAssign( OutGlyphWidth, GlyphReadByte( GlyphOffset++ ) );
        NullCheckAndAssign( OutGlyphOffset, GlyphOffset );
    } else {
        GlyphWidth = CurrentFont->FontWidthPx;
        GlyphSize = ( GlyphWidth * GlyphYBytes ) + 1;

        GlyphOffset = ( GlyphSize * ( c - CurrentFont->FirstChar ) );

        if ( CurrentFont->IsExternal ) {
            GlyphOffset+= ( uint16_t ) CurrentFont->Data;
        }

        NullCheckAndAssign( OutGlyphWidth, GlyphReadByte( GlyphOffset ) );
        NullCheckAndAssign( OutGlyphOffset, ( ++GlyphOffset ) );
    }

    return 1;
}

int SSD1306_DrawChar( const char c, const int x, const int y, const SSD_COLOR Color ) {
    uint16_t GlyphOffset = 0;
    int GlyphHeightBytes = 0;
    int GlyphWidth = 0;
    int GlyphSize = 0;
    int XEnd = 0;
    int YEnd = 0;

    if ( CurrentFont != NULL && GetGlyphInfo( c, &GlyphWidth, &GlyphOffset ) > 0 ) {
        GlyphHeightBytes = ( CurrentFont->FontHeightPxRoundedUp / 8 );
        GlyphSize = ( GlyphWidth * GlyphHeightBytes );

        YEnd = y + CurrentFont->FontHeightPxRoundedUp;
        XEnd = x + GlyphWidth;

        if ( x < 0 || XEnd < 0 || y < 0 || YEnd < 0 || x >= DisplayWidth || XEnd >= DisplayWidth || y > DisplayHeight || YEnd > DisplayHeight ) {
            DebugPrintString( "Clipped character [%c] at %d, %d\n", c, x, y );
            return -1;
        }

        SSD1306_SendTripleByteCommand( SSD1306_Op_SetColumnAddress, x, XEnd );
        SSD1306_SendTripleByteCommand( SSD1306_Op_SetPageAddress, y / 8, ( YEnd / 8 ) - 1 );

        if ( CurrentFont->IsExternal == true ) {
            SSD1306_WriteData( DataSource_EEPROM, ( const uint8_t* ) GlyphOffset, GlyphSize );
        } else {
            SSD1306_WriteData( DataSource_Progmem, &CurrentFont->Data[ GlyphOffset ], GlyphSize );
        }

        return GlyphWidth;
    }

    return -1;
}

int SSD1306_DrawString( const char* Text, int x, int y, const SSD_COLOR Color ) {
    SSD_COLOR LastColor = SSD1306_GetPrintColor( );

    SSD1306_SetPrintCursor( x, y );
    SSD1306_SetPrintColor( Color );

    SSD1306_PrintString( Text );
    SSD1306_SetPrintColor( LastColor );

    return PrintX;
}

void SSD1306_SetPrintCursor( const int x, const int y ) {
    PrintX = x;
    PrintY = y;
}

void SSD1306_GetPrintCursor( int* x, int* y ) {
    if ( x != NULL ) {
        *x = PrintX;
    }

    if ( y != NULL ) {
        *y = PrintY;
    }
}

const SSD_COLOR SSD1306_GetPrintColor( void ) {
    return PrintColor;
}

void SSD1306_SetPrintColor( const SSD_COLOR Color ) {
    PrintColor = Color;
}

static void PrintConstrain( const int GlyphWidth ) {
    if ( ( PrintX + GlyphWidth ) >= DisplayWidth ) {
        PrintY+= CurrentFont->FontHeightPxRoundedUp;
        PrintX = 0;
    }

    if ( ( PrintY + CurrentFont->FontHeightPxRoundedUp ) > DisplayHeight ) {
        PrintY = 0;
        PrintX = 0;
    }
}

void SSD1306_PrintChar( const char c ) {
    int GlyphWidth = 0;

    if ( CurrentFont != NULL ) {
         switch ( c ) {
            case '\r': {
                PrintX = 0;
                PrintConstrain( 0 );
                break;
            }
            case '\n': {
                PrintY+= CurrentFont->FontHeightPxRoundedUp;
                PrintX = 0;

                PrintConstrain( 0 );
                break;
            }
            case '\t': {
                SSD1306_PrintChar( ' ' );
                SSD1306_PrintChar( ' ' );
                SSD1306_PrintChar( ' ' );
                SSD1306_PrintChar( ' ' );

                break;
            }
            default: {
                if ( GetGlyphInfo( c, &GlyphWidth, NULL ) > 0 ) {
                    PrintConstrain( GlyphWidth );
                        if ( SSD1306_DrawChar( c, PrintX, PrintY, PrintColor ) > 0 ) {
                            PrintX+= GlyphWidth;
                        }
                    PrintConstrain( GlyphWidth );
                }

                break;
            }
        };
    }
}

void SSD1306_PrintString( const char* Text ) {
    if ( CurrentFont != NULL && Text != NULL ) {
        while ( *Text != '\0' ) {
            SSD1306_PrintChar( *Text++ );
        }
    }
}

void SSD1306_PrintInt( const int Value ) {
    char Buffer[ 16 ];

    itoa( Value, Buffer, 10 );
    SSD1306_PrintString( Buffer );
}

void SSD1306_SetFont( const GLCD_FontDef* Font ) {
    CurrentFont = Font;
}
