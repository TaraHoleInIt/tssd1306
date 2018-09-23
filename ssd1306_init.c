/**
 * Copyright (c) 2018 Tara Keeling
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include <avr/pgmspace.h>
#include "ssd1306.h"

extern const I2CProcs* I2C;

typedef struct {
    uint8_t Opcode;
    uint8_t Length;
    uint8_t Params[ 2 ];
} InitCommand;

#if SSD1306_CFG_WIDTH == 128 && SSD1306_CFG_HEIGHT == 64
PROGMEM static const InitCommand InitSequence[ ] = {
    { SSD1306_Op_SetMuxRatio, 1, { 63, 0 } },
    { SSD1306_Op_SetDisplayOffset, 1, { 0, 0 } },
    { SSD1306_Op_SetDisplayStartLine, 0, { 0, 0 } },
    { SSD1306_Op_Horizontal_Flip_Off, 0, { 0, 0 } },
    { SSD1306_Op_Vertical_Flip_Off, 0, { 0, 0 } },
    { SSD1306_Op_SetCOMPinsConfig, 1, { SSD1306_COM_Disable_LR_Remap | SSD1306_COM_Pins_Alternative | 0x02, 0 } },
    { SSD1306_Op_SetContrast, 1, { 0x7F, 0 } },
    { SSD1306_Op_EntireDisplayOff, 0, { 0, 0 } },
    { SSD1306_Op_SetNormal, 0, { 0, 0 } },
    { SSD1306_Op_SetDisplayClock, 1, { 0x80, 0 } },
    { SSD1306_Op_EnableChargePumpRegulator, 1, { 0x14, 0 } },
    { SSD1306_Op_SetAddressMode, 1, { 0, 0 } },
    { SSD1306_Op_SetColumnAddress, 2, { 0, 127 } },
    { SSD1306_Op_SetPageAddress, 2, { 0, 7 } },
    { SSD1306_Op_EntireDisplayOn, 0, { 0, 0 } },
    { SSD1306_Op_DisplayOn, 0, { 0, 0 } }
};
#endif

#if SSD1306_CFG_WIDTH == 128 && SSD1306_CFG_HEIGHT == 32
PROGMEM static const InitCommand InitSequence[ ] = {
    { SSD1306_Op_SetMuxRatio, 1, { 31, 0 } },
    { SSD1306_Op_SetDisplayOffset, 1, { 0, 0 } },
    { SSD1306_Op_SetDisplayStartLine, 0, { 0, 0 } },
    { SSD1306_Op_Horizontal_Flip_Off, 0, { 0, 0 } },
    { SSD1306_Op_Vertical_Flip_Off, 0, { 0, 0 } },
    { SSD1306_Op_SetCOMPinsConfig, 1, { SSD1306_COM_Disable_LR_Remap | SSD1306_COM_Pins_Sequential | 0x02, 0 } },
    { SSD1306_Op_SetContrast, 1, { 0x7F, 0 } },
    { SSD1306_Op_EntireDisplayOff, 0, { 0, 0 } },
    { SSD1306_Op_SetNormal, 0, { 0, 0 } },
    { SSD1306_Op_SetDisplayClock, 1, { 0x80, 0 } },
    { SSD1306_Op_EnableChargePumpRegulator, 1, { 0x14, 0 } },
    { SSD1306_Op_SetAddressMode, 1, { 0, 0 } },
    { SSD1306_Op_SetColumnAddress, 2, { 0, 127 } },
    { SSD1306_Op_SetPageAddress, 2, { 0, 3 } },
    { SSD1306_Op_EntireDisplayOn, 0, { 0, 0 } },
    { SSD1306_Op_DisplayOn, 0, { 0, 0 } }
};
#endif

static void WriteSingleByte( const uint8_t Data ) {
    I2C->Write( &Data, sizeof( const uint8_t ) );
}

void SSD1306_Init( const I2CProcs* I2CInterface ) {
    size_t i = 0;
    size_t j = 0;

    if ( I2CInterface ) {
        I2C = I2CInterface;

        for ( i = 0; i < sizeof( InitSequence ) / sizeof( InitSequence[ 0 ] ); i++ ) {
            I2C->StartTransmission( DisplayAddress );
                WriteSingleByte( SSD1306_I2C_Command );
                WriteSingleByte( pgm_read_byte( &InitSequence[ i ].Opcode ) );

                for ( j = 0; j < ( size_t ) pgm_read_byte( &InitSequence[ i ].Length ); j++ ) {
                    WriteSingleByte( pgm_read_byte( &InitSequence[ i ].Params[ j ] ) );
                }
            I2C->EndTransmission( );
        }

        SSD1306_Clear( 0 );
    }
}
