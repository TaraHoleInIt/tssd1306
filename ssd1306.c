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

static void SSD1306_WriteDataPGM( tssd1306* DeviceHandle, const uint8_t* Data, size_t Length );
static void SSD1306_WriteDataEEPROM( tssd1306* DeviceHandle, const uint8_t* Address, size_t Length );
static void SSD1306_WriteDataLocal( tssd1306* DeviceHandle, const uint8_t* Data, size_t Length );

static uint8_t GlyphReadEEPROM( const uint16_t Offset );
static uint8_t GlyphReadPROGMEM( const uint8_t* Address );
static uint8_t GlyphReadByte( const GLCD_FontDef* Font, const uint32_t Offset );

static int GetGlyphInfo( const GLCD_FontDef* Font, const char c, int* OutGlyphWidth, uint16_t* OutGlyphOffset );

#if defined HAS_DEBUG
    __attribute__( ( weak ) ) void DebugPrintString( const char* Text, ... ) {
    }
#endif

__attribute__( ( weak ) ) size_t EEPROMRead( const uint16_t Address, uint8_t* Buffer, size_t Length ) {
    return 0;
}

__attribute__( ( weak ) ) uint8_t EEPROMReadByte( const uint16_t Address ) {
    return 0;
}

#if defined PatternBufferSize
static uint8_t PatternBuffer[ PatternBufferSize ];
#endif

void SSD1306_WriteDataByte( tssd1306* DeviceHandle, const uint8_t Data ) {
    DeviceHandle->Interface->StartTransmission( DeviceHandle, false );
        DeviceHandle->Interface->WriteByte( DeviceHandle, Data );
    DeviceHandle->Interface->EndTransmission( DeviceHandle );
}

void SSD1306_WriteData( tssd1306* DeviceHandle, DataSource Source, const uint8_t* Data, size_t Length ) {
    switch ( Source ) {
        case DataSource_Local: {
            SSD1306_WriteDataLocal( DeviceHandle, Data, Length );
            break;
        }
        case DataSource_Progmem: {
            SSD1306_WriteDataPGM( DeviceHandle, Data, Length );
            break;
        }
        case DataSource_EEPROM: {
            SSD1306_WriteDataEEPROM( DeviceHandle, Data, Length );
            break;
        }
        default: return;
    };
}

static void SSD1306_WriteDataLocal( tssd1306* DeviceHandle, const uint8_t* Data, size_t Length ) {
    int BytesToWrite = 0;

    while ( Length > 0 ) {
        BytesToWrite = ( Length > DeviceHandle->Interface->MaxTransferSize ) ? DeviceHandle->Interface->MaxTransferSize : Length;

        DeviceHandle->Interface->StartTransmission( DeviceHandle, false );
            DeviceHandle->Interface->Write( DeviceHandle, Data, BytesToWrite );
        DeviceHandle->Interface->EndTransmission( DeviceHandle );

        Length-= BytesToWrite;
        Data+= BytesToWrite;
    }
}

static void SSD1306_WriteDataPGM( tssd1306* DeviceHandle, const uint8_t* Data, size_t Length ) {
#if ! defined PatternBufferSize
    int i = 0;

    while ( Length > 0 ) {
        DeviceHandle->Interface->StartTransmission( DeviceHandle, false );
            for ( i = 0; i < DeviceHandle->Interface->MaxTransferSize && Length > 0; i++, Data++, Length-- ) {
                DeviceHandle->Interface->WriteByte( DeviceHandle, pgm_read_byte( Data ) );
            }
        DeviceHandle->Interface->EndTransmission( DeviceHandle );
    }
#else
    int BytesToWrite = 0;

    while ( Length > 0 ) {
        BytesToWrite = ( Length > PatternBufferSize ) ? PatternBufferSize : Length;

        memcpy_P( PatternBuffer, Data, BytesToWrite );
        SSD1306_WriteDataLocal( DeviceHandle, PatternBuffer, BytesToWrite );

        Length-= BytesToWrite;
        Data+= BytesToWrite;
    }
#endif
}

static void SSD1306_WriteDataEEPROM( tssd1306* DeviceHandle, const uint8_t* Address, size_t Length ) {
#if ! defined PatternBufferSize
    size_t i = 0;

    for ( i = 0; i < Length; i++ ) {
        // TODO:
        // EEPROM STUFF
        DeviceHandle->Interface->StartTransmission( DeviceHandle, false );
            DeviceHandle->Interface->WriteByte( DeviceHandle, EEPROMReadByte( Address + i ) );
        DeviceHandle->Interface->EndTransmission( DeviceHandle );
    }
#else
    int BytesToWrite = 0;

    while ( Length > 0 ) {
        BytesToWrite = ( Length > PatternBufferSize ) ? PatternBufferSize : Length;

        //I2C->EEPROMRead( ( const uint16_t ) Address, PatternBuffer, BytesToWrite );

        EEPROMRead( ( const uint16_t ) Address, PatternBuffer, BytesToWrite );
        SSD1306_WriteDataLocal( DeviceHandle, PatternBuffer, BytesToWrite );

        Length-= BytesToWrite;
        Address+= BytesToWrite;
    }
#endif
}

void SSD1306_SendSingleByteCommand( tssd1306* DeviceHandle, const uint8_t Command ) {
    DeviceHandle->Interface->StartTransmission( DeviceHandle, true );
        DeviceHandle->Interface->WriteByte( DeviceHandle, Command );
    DeviceHandle->Interface->EndTransmission( DeviceHandle );
}

void SSD1306_SendDoubleByteCommand( tssd1306* DeviceHandle, const uint8_t Command, const uint8_t Param0 ) {
    DeviceHandle->Interface->StartTransmission( DeviceHandle, true );
        DeviceHandle->Interface->WriteByte( DeviceHandle, Command );
        DeviceHandle->Interface->WriteByte( DeviceHandle, Param0 );
    DeviceHandle->Interface->EndTransmission( DeviceHandle );
}

void SSD1306_SendTripleByteCommand( tssd1306* DeviceHandle, const uint8_t Command, const uint8_t Param0, const uint8_t Param1 ) {
    DeviceHandle->Interface->StartTransmission( DeviceHandle, true );
        DeviceHandle->Interface->WriteByte( DeviceHandle, Command );
        DeviceHandle->Interface->WriteByte( DeviceHandle, Param0 );
        DeviceHandle->Interface->WriteByte( DeviceHandle, Param1 );
    DeviceHandle->Interface->EndTransmission( DeviceHandle );
}

static void SSD1306_WritePattern( tssd1306* DeviceHandle, const uint8_t PatternByte, size_t Length ) {
#if ! defined PatternBufferSize
    size_t i = 0;   

    while ( Length > 0 ) {
        DeviceHandle->Interface->StartTransmission( DeviceHandle, false );

        for ( i = 0; i < DeviceHandle->Interface->MaxTransferSize && Length > 0; i++, Length-- ) {
            DeviceHandle->Interface->WriteByte( DeviceHandle, PatternByte );
        }
        
        DeviceHandle->Interface->EndTransmission( DeviceHandle );
    }
#else
    int BytesToWrite = 0;
    int BytesWritten = 0;
    int i = 0;

    for ( i = 0; i < PatternBufferSize && i < Length; i++ ) {
        PatternBuffer[ i ] = PatternByte;
    }

    memset( PatternBuffer, PatternByte, PatternBufferSize );

    while ( Length > 0 ) {
        BytesToWrite = ( Length > PatternBufferSize ) ? PatternBufferSize : Length;
        BytesToWrite = ( BytesToWrite > DeviceHandle->Interface->MaxTransferSize ) ? DeviceHandle->Interface->MaxTransferSize : BytesToWrite;

        SSD1306_WriteDataLocal( DeviceHandle, PatternBuffer, BytesToWrite );

        BytesWritten+= BytesToWrite;
        Length-= BytesToWrite;
    }
#endif
}

void SSD1306_Clear( tssd1306* DeviceHandle, const uint8_t Pattern ) {
    size_t DisplaySize = ( DeviceHandle->Width * DeviceHandle->Height ) / 8;

    SSD1306_SendTripleByteCommand( DeviceHandle, SSD1306_Op_SetColumnAddress, 0, DeviceHandle->Width - 1 );
    SSD1306_SendTripleByteCommand( DeviceHandle, SSD1306_Op_SetPageAddress, 0, ( DeviceHandle->Height / 8 ) - 1 );

    SSD1306_WritePattern( DeviceHandle, Pattern, DisplaySize );

    DeviceHandle->PrintX = 0;
    DeviceHandle->PrintY = 0;
}

void SSD1306_DrawPixel( tssd1306* DeviceHandle, const int x, const int y ) {
    int YBit = ( y & 0x07 );
    int Page = ( y / 8 );

    if ( x < 0 || x >= DeviceHandle->Width || y < 0 || y >= DeviceHandle->Height ) {
        DebugPrintString( "Clipped pixel at %d,%d\n", x, y );
        return;
    }

    SSD1306_SendTripleByteCommand( DeviceHandle, SSD1306_Op_SetColumnAddress, x, x );
    SSD1306_SendTripleByteCommand( DeviceHandle, SSD1306_Op_SetPageAddress, Page, Page );

    SSD1306_WriteDataByte( DeviceHandle, BIT( YBit ) );
}

void SSD1306_DrawHLine( tssd1306* DeviceHandle, const int x0, const int y, const int x1 ) {
    int Width = ( x1 - x0 ) + 1;
    int YBit = ( y  & 0x07 );
    int YPage = ( y / 8 );

    if ( x0 < 0 || x0 >= DeviceHandle->Width || x1 < x0 || x1 >= DeviceHandle->Width || y < 0 || y >= DeviceHandle->Height ) {
        DebugPrintString( "HLine clipped at %d,%d width %d\n", x0, y, Width );
        return;
    }

    SSD1306_SendTripleByteCommand( DeviceHandle, SSD1306_Op_SetPageAddress, YPage, YPage );
    SSD1306_SendTripleByteCommand( DeviceHandle, SSD1306_Op_SetColumnAddress, x0, x1 );

    SSD1306_WritePattern( DeviceHandle, BIT( YBit ), Width );
}

void SSD1306_DrawVLine( tssd1306* DeviceHandle, const int x, const int y0, const int y1 ) {
    uint8_t ColBuffer[ 8 ];
    int StartYPage = ( y0 / 8 );
    int EndYPage = ( y1 / 8 );
    int NumPages = ( EndYPage - StartYPage ) + 1;
    int YByte = 0;
    int YBit = 0;
    int y = 0;

    if ( x < 0 || x >= DeviceHandle->Width || y0 < 0 || y0 >= DeviceHandle->Height || y1 < y0 || y1 >= DeviceHandle->Height ) {
        DebugPrintString( "VLine clipped at %d,%d height: %d\n", x, y0, ( y1 - y0 ) );
        return;
    }

    SSD1306_SendTripleByteCommand( DeviceHandle, SSD1306_Op_SetColumnAddress, x, x );
    SSD1306_SendTripleByteCommand( DeviceHandle, SSD1306_Op_SetPageAddress, StartYPage, EndYPage );

    memset( ColBuffer, 0, sizeof( ColBuffer ) );

    for ( y = y0; y <= y1; y++ ) {
        YByte = ( y / 8 );
        YBit = ( y & 0x07 );

        ColBuffer[ YByte ] |= BIT( YBit );
    }

    SSD1306_WriteData( DeviceHandle, DataSource_Local, ColBuffer, NumPages );
}

void SSD1306_FillRect( tssd1306* DeviceHandle, const int x0, const int y0, const int x1, const int y1 ) {
    int Width = ( x1 - x0 ) + 1;
    int Height = ( y1 - y0 ) + 1;
    int FillSize = 0;

    if ( x0 < 0 || x0 >= DeviceHandle->Width || x1 < 0 || x1 >= DeviceHandle->Width || y0 < 0 || y0 >= DeviceHandle->Height || y1 < 0 || y1 >= DeviceHandle->Height ) {
        DebugPrintString( "FillRect: Clipped at %d,%d to %d,%d\n", x0, y0, x1, y1 );
        return;
    }

    /* Always round up to a multiple of 8 due to how pages work */
    /* Should be done on y coordinates? */
    Height = ( Height + 7 ) & ~7;

    FillSize = ( Width * Height ) / 8;

    SSD1306_SendTripleByteCommand( DeviceHandle, SSD1306_Op_SetColumnAddress, x0, x1 );
    SSD1306_SendTripleByteCommand( DeviceHandle, SSD1306_Op_SetPageAddress, ( y0 / 8 ), ( y1 / 8 ) );

    SSD1306_WritePattern( DeviceHandle, 0xFF, FillSize );
}

static uint8_t GlyphReadEEPROM( const uint16_t Offset ) {
    return EEPROMReadByte( Offset );
}

static uint8_t GlyphReadPROGMEM( const uint8_t* Address ) {
    return pgm_read_byte( Address );
}

static uint8_t GlyphReadByte( const GLCD_FontDef* Font, const uint32_t Offset ) {
    return ( Font->IsExternal == true ) ? GlyphReadEEPROM( Offset ) : GlyphReadPROGMEM( &Font->Data[ Offset ] );
}

static int GetGlyphInfo( const GLCD_FontDef* Font, const char c, int* OutGlyphWidth, uint16_t* OutGlyphOffset ) {
    uint16_t GlyphOffset = 0;
    int GlyphWidth = 0;
    int GlyphYBytes = 0;
    int GlyphSize = 0;
    int i = 0;

    if ( Font == NULL || c < Font->FirstChar || c > Font->LastChar ) {
        return 0;
    }

    GlyphYBytes = ( Font->FontHeightPxRoundedUp / 8 );

    if ( Font->IsStream == true ) {
        for ( i = 0; i < ( c - Font->FirstChar ); i++ ) {
            GlyphWidth = GlyphReadByte( Font, GlyphOffset );
            GlyphSize = ( ( GlyphWidth * GlyphYBytes ) ) + 1;
            GlyphOffset+= GlyphSize;
        }

        NullCheckAndAssign( OutGlyphWidth, GlyphReadByte( Font, GlyphOffset++ ) );
        NullCheckAndAssign( OutGlyphOffset, GlyphOffset );
    } else {
        GlyphWidth = Font->FontWidthPx;
        GlyphSize = ( GlyphWidth * GlyphYBytes ) + 1;

        GlyphOffset = ( GlyphSize * ( c - Font->FirstChar ) );

        if ( Font->IsExternal ) {
            GlyphOffset+= ( uint16_t ) Font->Data;
        }

        NullCheckAndAssign( OutGlyphWidth, GlyphReadByte( Font, GlyphOffset ) );
        NullCheckAndAssign( OutGlyphOffset, ( ++GlyphOffset ) );
    }

    return 1;
}

int SSD1306_DrawChar( tssd1306* DeviceHandle, const char c, const int x, const int y ) {
    uint16_t GlyphOffset = 0;
    int GlyphHeightBytes = 0;
    int GlyphWidth = 0;
    int GlyphSize = 0;
    int XEnd = 0;
    int YEnd = 0;

    if ( GetGlyphInfo( DeviceHandle->CurrentFont, c, &GlyphWidth, &GlyphOffset ) > 0 ) {
        GlyphHeightBytes = ( DeviceHandle->CurrentFont->FontHeightPxRoundedUp / 8 );
        GlyphSize = ( GlyphWidth * GlyphHeightBytes );

        YEnd = y + DeviceHandle->CurrentFont->FontHeightPxRoundedUp;
        XEnd = x + GlyphWidth;

        if ( x < 0 || XEnd < 0 || y < 0 || YEnd < 0 || x >= DeviceHandle->Width || XEnd >= DeviceHandle->Width || y > DeviceHandle->Height || YEnd > DeviceHandle->Height ) {
            DebugPrintString( "Clipped character [%c] at %d, %d\n", c, x, y );
            return -1;
        }

        SSD1306_SendTripleByteCommand( DeviceHandle, SSD1306_Op_SetColumnAddress, x, XEnd );
        SSD1306_SendTripleByteCommand( DeviceHandle, SSD1306_Op_SetPageAddress, y / 8, ( YEnd / 8 ) - 1 );

        if ( DeviceHandle->CurrentFont->IsExternal == true ) {
            SSD1306_WriteData( DeviceHandle, DataSource_EEPROM, ( const uint8_t* ) GlyphOffset, GlyphSize );
        } else {
            SSD1306_WriteData( DeviceHandle, DataSource_Progmem, &DeviceHandle->CurrentFont->Data[ GlyphOffset ], GlyphSize );
        }

        return GlyphWidth;
    }

    return -1;
}

int SSD1306_DrawString( tssd1306* DeviceHandle, const char* Text, int x, int y ) {
    SSD1306_SetPrintCursor( DeviceHandle, x, y );
    SSD1306_PrintString( DeviceHandle, Text );

    return DeviceHandle->PrintX;
}

void SSD1306_SetPrintCursor( tssd1306* DeviceHandle, const int x, const int y ) {
    DeviceHandle->PrintX = x;
    DeviceHandle->PrintY = y;
}

void SSD1306_GetPrintCursor( tssd1306* DeviceHandle, int* x, int* y ) {
    NullCheckAndAssign( x, DeviceHandle->PrintX );
    NullCheckAndAssign( y, DeviceHandle->PrintY );
}

static void PrintConstrain( tssd1306* DeviceHandle, const int GlyphWidth ) {
    if ( ( DeviceHandle->PrintX + GlyphWidth ) >= DeviceHandle->Width ) {
        DeviceHandle->PrintY+= DeviceHandle->CurrentFont->FontHeightPxRoundedUp;
        DeviceHandle->PrintX = 0;
    }

    if ( ( DeviceHandle->PrintY + DeviceHandle->CurrentFont->FontHeightPxRoundedUp ) > DeviceHandle->Height ) {
        DeviceHandle->PrintY = 0;
        DeviceHandle->PrintX = 0;
    }
}

void SSD1306_PrintChar( tssd1306* DeviceHandle, const char c ) {
    int GlyphWidth = 0;

    if ( DeviceHandle->CurrentFont != NULL ) {
         switch ( c ) {
            case '\r': {
                DeviceHandle->PrintX = 0;
                PrintConstrain( DeviceHandle, 0 );
                break;
            }
            case '\n': {
                DeviceHandle->PrintY+= DeviceHandle->CurrentFont->FontHeightPxRoundedUp;
                DeviceHandle->PrintX = 0;

                PrintConstrain( DeviceHandle, 0 );
                break;
            }
            case '\t': {
                SSD1306_PrintChar( DeviceHandle, ' ' );
                SSD1306_PrintChar( DeviceHandle, ' ' );
                SSD1306_PrintChar( DeviceHandle, ' ' );
                SSD1306_PrintChar( DeviceHandle, ' ' );

                break;
            }
            default: {
#if 0
                if ( GetGlyphInfo( DeviceHandle->CurrentFont, c, &GlyphWidth, NULL ) > 0 ) {
                    PrintConstrain( DeviceHandle, GlyphWidth );
                        if ( SSD1306_DrawChar( DeviceHandle, c, DeviceHandle->PrintX, DeviceHandle->PrintY ) > 0 ) {
                            DeviceHandle->PrintX+= GlyphWidth;
                        }
                    PrintConstrain( DeviceHandle, GlyphWidth );
                }
#endif
                if ( c >= DeviceHandle->CurrentFont->FirstChar && c <= DeviceHandle->CurrentFont->LastChar ) {
                    GlyphWidth = SSD1306_DrawChar( DeviceHandle, c, DeviceHandle->PrintX, DeviceHandle->PrintY );

                    if ( GlyphWidth > 0 ) {
                        DeviceHandle->PrintX+= GlyphWidth;
                        PrintConstrain( DeviceHandle, GlyphWidth );
                    }
                }

                break;
            }
        };
    }
}

void SSD1306_PrintString( tssd1306* DeviceHandle, const char* Text ) {
    if ( DeviceHandle->CurrentFont != NULL && Text != NULL ) {
        while ( *Text != '\0' ) {
            SSD1306_PrintChar( DeviceHandle, *Text++ );
        }
    }
}

void SSD1306_PrintInt( tssd1306* DeviceHandle, const int Value ) {
    char Buffer[ 16 ];

    itoa( Value, Buffer, 10 );
    SSD1306_PrintString( DeviceHandle, Buffer );
}

void SSD1306_SetFont( tssd1306* DeviceHandle, const GLCD_FontDef* Font ) {
    DeviceHandle->CurrentFont = Font;
}
