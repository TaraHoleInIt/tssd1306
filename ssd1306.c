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

static const GLCD_FontDef* CurrentFont = NULL;

const I2CProcs* I2C = NULL;

static void SSD1306_WriteData( const uint8_t* Data, size_t Length );
static void SSD1306_WriteDataByte( const uint8_t Data );

static void SSD1306_SendSingleByteCommand( const uint8_t Command );
static void SSD1306_SendDoubleByteCommand( const uint8_t Command, const uint8_t Param0 );
static void SSD1306_SendTripleByteCommand( const uint8_t Command, const uint8_t Param0, const uint8_t Param1 );

static SSD_COLOR PrintColor = SSD_COLOR_WHITE;
static int PrintX = 0;
static int PrintY = 0;

#if defined HAS_DEBUG
    __attribute__( ( weak ) ) void DebugPrintString( const char* Text, ... ) {
    }
#endif

static void SSD1306_WriteData( const uint8_t* Data, size_t Length ) {
    const uint8_t WriteIsData = SSD1306_I2C_Data;
    size_t BytesToWrite = 0;

    if ( Length < ( I2C->TXBufferLen - 1 ) ) {
        I2C->StartTransmission( DisplayAddress );
            I2C->Write( &WriteIsData, sizeof( const uint8_t ) );
            I2C->Write( Data, Length );
        I2C->EndTransmission( );
    } else {
        while ( Length > 0 ) {
            BytesToWrite = ( Length > ( I2C->TXBufferLen - 1 ) ) ? ( I2C->TXBufferLen - 1 ) : Length;

            I2C->StartTransmission( DisplayAddress );
                I2C->Write( &WriteIsData, sizeof( const uint8_t ) );
                I2C->Write( Data, BytesToWrite );
            I2C->EndTransmission( );

            Length-= BytesToWrite;
            Data+= BytesToWrite;
        }
    }
}

static void SSD1306_WriteDataByte( const uint8_t Data ) {
    const uint8_t WriteIsData = SSD1306_I2C_Data;

    I2C->StartTransmission( DisplayAddress );
        I2C->Write( &WriteIsData, sizeof( const uint8_t ) );
        I2C->Write( &Data, sizeof( const uint8_t ) );
    I2C->EndTransmission( );
}

static void SSD1306_SendSingleByteCommand( const uint8_t Command ) {
    const uint8_t WriteIsCommand = SSD1306_I2C_Command;

    I2C->StartTransmission( DisplayAddress );
        I2C->Write( &WriteIsCommand, sizeof( const uint8_t ) );
        I2C->Write( &Command, sizeof( const uint8_t ) );
    I2C->EndTransmission( );
}

static void SSD1306_SendDoubleByteCommand( const uint8_t Command, const uint8_t Param0 ) {
    const uint8_t WriteIsCommand = SSD1306_I2C_Command;

    I2C->StartTransmission( DisplayAddress );
        I2C->Write( &WriteIsCommand, sizeof( const uint8_t ) );
        I2C->Write( &Command, sizeof( const uint8_t ) );
        I2C->Write( &Param0, sizeof( const uint8_t ) );
    I2C->EndTransmission( );
}

static void SSD1306_SendTripleByteCommand( const uint8_t Command, const uint8_t Param0, const uint8_t Param1 ) {
    const uint8_t WriteIsCommand = SSD1306_I2C_Command;

    I2C->StartTransmission( DisplayAddress );
        I2C->Write( &WriteIsCommand, sizeof( const uint8_t ) );
        I2C->Write( &Command, sizeof( const uint8_t ) );
        I2C->Write( &Param0, sizeof( const uint8_t ) );
        I2C->Write( &Param1, sizeof( const uint8_t ) );
    I2C->EndTransmission( );
}

void SSD1306_Clear( const uint8_t Pattern ) {
    const int PageCount = ( DisplayHeight / 8 );
    uint8_t PageBuffer[ DisplayWidth ];
    int Page = 0;

    SSD1306_SendTripleByteCommand( SSD1306_Op_SetColumnAddress, 0, DisplayWidth - 1 );
    memset( PageBuffer, Pattern, DisplayWidth );

    for ( ; Page < PageCount; Page++ ) {
        SSD1306_SendTripleByteCommand( SSD1306_Op_SetPageAddress, Page, Page );
        SSD1306_WriteData( PageBuffer, DisplayWidth );
    }
}

void SSD1306_DrawPixel( const int x, const int y, const SSD_COLOR Color ) {
    int YBit = ( y & 0x07 );
    int YPage = ( y / 8 );

    SSD1306_SendTripleByteCommand( SSD1306_Op_SetColumnAddress, x, x );
    SSD1306_SendTripleByteCommand( SSD1306_Op_SetPageAddress, YPage, YPage );

    SSD1306_WriteDataByte( ( Color ) ? BIT( YBit ) : 0 );
}

void SSD1306_DrawHLine( const int x0, const int y, const int x1, const SSD_COLOR Color ) {
    uint8_t PageBuffer[ DisplayWidth ];
    int Width = ( x1 - x0 );
    int YBit = ( y & 0x07 );
    int YPage = ( y / 8 );

    if ( x0 < 0 || x0 >= DisplayWidth || x1 < x0 || x1 >= DisplayWidth || y < 0 || y >= DisplayHeight ) {
        return;
    }

    SSD1306_SendTripleByteCommand( SSD1306_Op_SetColumnAddress, x0, x1 );
    SSD1306_SendTripleByteCommand( SSD1306_Op_SetPageAddress, YPage, YPage );

    memset( PageBuffer, ( Color ) ? BIT( YBit ) : 0, Width );
    SSD1306_WriteData( PageBuffer, Width );
}

void SSD1306_DrawVLine( const int x, const int y0, const int y1, const SSD_COLOR Color ) {
    uint8_t ColBuffer[ DisplayHeight / 8 ];
    int StartYPage = ( y0 / 8 );
    int EndYPage = ( y1 / 8 );
    int NumPages = ( EndYPage - StartYPage ) + 1;
    int YByte = 0;
    int YBit = 0;
    int y = 0;

    if ( x < 0 || x >= DisplayWidth || y0 < 0 || y0 >= DisplayHeight - 1 || y1 < y0 || y1 >= DisplayHeight ) {
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

    SSD1306_WriteData( ColBuffer, NumPages );
}

static int GetGlyphInfo( const char c, int* OutGlyphWidth, const uint8_t** OutGlyphData ) {
    const uint8_t* GlyphData = NULL;
    int GlyphWidth = 0;
    int GlyphSize = 0;
    int i = 0;

    if ( c < CurrentFont->FirstChar || c > CurrentFont->LastChar ) {
        return 0;
    }

    GlyphSize = ( CurrentFont->FontWidthPx * ( CurrentFont->FontHeightPxRoundedUp / 8 ) ) + 1;

    if ( CurrentFont->IsStream == false ) {
        GlyphData = CurrentFont->Data + ( GlyphSize * ( c - CurrentFont->FirstChar ) );
        GlyphWidth = ( int ) pgm_read_byte( GlyphData );

        if ( OutGlyphWidth != NULL ) {
            *OutGlyphWidth = GlyphWidth;
        }

        if ( OutGlyphData != NULL ) {
            *OutGlyphData = ( GlyphData + 1 );
        }
    } else {
        /* This seeks character by character within the font data until we reach our intended target */
        for ( i = 0, GlyphData = CurrentFont->Data; i < ( c - CurrentFont->FirstChar ); i++ ) {
            GlyphWidth = ( int ) pgm_read_byte( GlyphData );
            GlyphSize = ( GlyphWidth * ( CurrentFont->FontHeightPxRoundedUp / 8 ) ) + 1;

            GlyphData+= ( GlyphSize );
        }

        /* Re-read width */
        GlyphWidth = pgm_read_byte( GlyphData );

        if ( OutGlyphWidth != NULL ) {
            *OutGlyphWidth = GlyphWidth;
        }

        if ( OutGlyphData != NULL ) {
            /* Skip past width data byte */
            *OutGlyphData = ( GlyphData + 1 );
        }
    }

    return 1;
}

int SSD1306_DrawChar( const char c, const int x, const int y, const SSD_COLOR Color ) {
    const uint8_t* GlyphData = NULL;
    uint8_t* RenderedGlyph = NULL;
    int GlyphHeightBytes = 0;
    int GlyphHeight = 0;
    int GlyphWidth = 0;
    int GlyphSize = 0;
    int YStartPage = 0;
    int YEndPage = 0;
    int cx = 0;
    int cy = 0;

    if ( CurrentFont != NULL && GetGlyphInfo( c, &GlyphWidth, &GlyphData ) > 0 ) {
        GlyphHeight = CurrentFont->FontHeightPxRoundedUp;

        if ( x < 0 || ( x + GlyphWidth ) >= DisplayWidth || y < 0 || ( y + GlyphHeight ) > DisplayHeight ) {
            DebugPrintString( "Clipped [%c] at %d,%d x+w: %d, w: %d\n", c, x, y, ( x + GlyphWidth ), GlyphWidth );
            return -1;
        }

        GlyphHeightBytes = ( CurrentFont->FontHeightPxRoundedUp / 8 );
        GlyphSize = GlyphWidth * GlyphHeightBytes;

        YStartPage = ( y / 8 );

        YEndPage = ( ( y + CurrentFont->FontHeightPxRoundedUp ) / 8 );
        YEndPage = ( YEndPage >= DisplayPages ) ? DisplayPages - 1 : YEndPage;
        
        RenderedGlyph = ( uint8_t* ) alloca( GlyphSize );

        if ( RenderedGlyph != NULL ) {
            //DebugPrintString( "%s: c [%c] x [%d] y [%d] YStartPage [%d] YEndPage [%d]\n", __func__, c, x, y, YStartPage, YEndPage );

            SSD1306_SendTripleByteCommand( SSD1306_Op_SetColumnAddress, x, ( ( x + GlyphWidth ) - 1 ) );
            SSD1306_SendTripleByteCommand( SSD1306_Op_SetPageAddress, YStartPage, YEndPage );

            memset( RenderedGlyph, 0x00, GlyphSize );

            for ( cx = 0; cx < GlyphWidth; cx++ ) {
                for ( cy = 0; cy < GlyphHeightBytes; cy++ ) {
                    RenderedGlyph[ cx + ( cy * GlyphWidth ) ] = pgm_read_byte( GlyphData++ );
                }
            }
            
            SSD1306_WriteData( RenderedGlyph, GlyphSize );

            return GlyphWidth;
        }
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
