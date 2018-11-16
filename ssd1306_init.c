/**
 * Copyright (c) 2018 Tara Keeling
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include <avr/pgmspace.h>
#include "ssd1306.h"

typedef struct {
    uint8_t Opcode;
    uint8_t Length;
    uint8_t Params[ 2 ];
} InitCommand;

PROGMEM static const InitCommand InitSequenceGenericStart[ ] = {
    { SSD1306_Op_SetMuxRatio, 1, { 63, 0 } },
    { SSD1306_Op_SetDisplayOffset, 1, { 0, 0 } },
    { SSD1306_Op_SetDisplayStartLine, 0, { 0, 0 } },
    { SSD1306_Op_Horizontal_Flip_Off, 0, { 0, 0 } },
    { SSD1306_Op_Vertical_Flip_Off, 0, { 0, 0 } },
    { SSD1306_Op_SetContrast, 1, { 0x7F, 0 } },
    { SSD1306_Op_EntireDisplayOff, 0, { 0, 0 } },
    { SSD1306_Op_SetNormal, 0, { 0, 0 } },
    { SSD1306_Op_SetDisplayClock, 1, { 0x80, 0 } },
    { SSD1306_Op_EnableChargePumpRegulator, 1, { 0x14, 0 } },
    { SSD1306_Op_SetAddressMode, 1, { 1, 0 } }
};

void SSD1306_Init( tssd1306* DeviceHandle ) {
    int NumberOfInitCommands = sizeof( InitSequenceGenericStart ) / sizeof( InitSequenceGenericStart[ 0 ] );
    int i = 0;
    int j = 0;

    for ( i = 0; i < NumberOfInitCommands; i++ ) {
        DeviceHandle->Interface->StartTransmission( DeviceHandle, true );
            DeviceHandle->Interface->WriteByte( DeviceHandle, pgm_read_byte( &InitSequenceGenericStart[ i ].Opcode ) );

            for ( j = 0; j < pgm_read_byte( &InitSequenceGenericStart[ i ].Length ); j++ ) {
                DeviceHandle->Interface->WriteByte( DeviceHandle, pgm_read_byte( &InitSequenceGenericStart[ i ].Params[ j ] ) );
            }

        DeviceHandle->Interface->EndTransmission( DeviceHandle );
    }

    SSD1306_SendTripleByteCommand( DeviceHandle, SSD1306_Op_SetColumnAddress, 0, DeviceHandle->Width - 1 );
    SSD1306_SendTripleByteCommand( DeviceHandle, SSD1306_Op_SetPageAddress, 0, ( DeviceHandle->Height / 8 ) - 1 );

    if ( DeviceHandle->Height == 32 ) {
        SSD1306_SendDoubleByteCommand( DeviceHandle, SSD1306_Op_SetCOMPinsConfig, SSD1306_COM_Disable_LR_Remap | SSD1306_COM_Pins_Sequential | 0x02 );
    } else {
        SSD1306_SendDoubleByteCommand( DeviceHandle, SSD1306_Op_SetCOMPinsConfig, SSD1306_COM_Disable_LR_Remap | SSD1306_COM_Pins_Alternative | 0x02 );
    }

    SSD1306_Clear( DeviceHandle, 0x00 );

    SSD1306_SendSingleByteCommand( DeviceHandle, SSD1306_Op_EntireDisplayOn );
    SSD1306_SendSingleByteCommand( DeviceHandle, SSD1306_Op_DisplayOn );

    DeviceHandle->PrintX = 0;
    DeviceHandle->PrintY = 0;
}
