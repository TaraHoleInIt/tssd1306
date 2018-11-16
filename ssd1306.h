/** 
 * \file ssd1306.h
 * \brief SSD1306 API
 */

#ifndef _SSD1306_H_
#define _SSD1306_H_

#include <stddef.h>
#include <stdint.h>

#include "glcd_font.h"

#ifndef BIT
    #define BIT( n ) ( 1 << n )
#endif

#define SSD1306_COM_Disable_LR_Remap 0
#define SSD1306_COM_Enable_LR_Remap ( 1 << 5 )

#define SSD1306_COM_Pins_Sequential 0
#define SSD1306_COM_Pins_Alternative ( 1 << 4 )

#define COM_ScanDir_LR 0
#define COM_ScanDir_RL 1

#define SSD1306_Op_SetContrast 0x81
#define SSD1306_Op_EntireDisplayOn 0xA4
#define SSD1306_Op_EntireDisplayOff 0xA5
#define SSD1306_Op_SetNormal 0xA6
#define SSD1306_Op_SetInverted 0xA7
#define SSD1306_Op_DisplayOff 0xAE
#define SSD1306_Op_DisplayOn 0xAF
#define SSD1306_Op_SetAddressMode 0x20
#define SSD1306_Op_SetMuxRatio 0xA8
#define SSD1306_Op_SetDisplayOffset 0xD3
#define SSD1306_Op_SetDisplayStartLine 0x40
#define SSD1306_Op_Horizontal_Flip_Off 0xA0
#define SSD1306_Op_Horizontal_Flip_On 0xA1
#define SSD1306_Op_Vertical_Flip_Off 0xC0
#define SSD1306_Op_Vertical_Flip_On 0xC8
#define SSD1306_Op_SetCOMPinsConfig 0xDA
#define SSD1306_Op_SetDisplayClock 0xD5
#define SSD1306_Op_EnableChargePumpRegulator 0x8D
#define SSD1306_Op_SetColumnAddress 0x21
#define SSD1306_Op_SetPageAddress 0x22

#define SSD1306_I2C_Command 0x00
#define SSD1306_I2C_Data 0x40

/**
 * @brief Type of memory to pull data from when writing to the display
 * 
 */
typedef enum {
    DataSource_Local = 0, /**< Data is in local addressable space */
    DataSource_Progmem, /**< Data is in flash/progmem space */
    DataSource_EEPROM /**< Data is on an EEPROM */
} DataSource;

struct DisplayInterfaceProcs_s;

/**
 * @brief Screen device interface, details, and, control lines.
 * 
 */
typedef struct {
    struct DisplayInterfaceProcs_s* Interface; /**< Interface callbacks to talk to the display */

    uint8_t Width; /**< Width of the display in pixels */
    uint8_t Height; /**< Height of the display in pixels */

    uint8_t Address; /**< Address of display if using I2C */
    int8_t CSPin; /**< Chip select pin if using SPI */

    uint8_t PrintX; /**< Current X coordinate for PrintXXX functions */
    uint8_t PrintY; /**< Current Y coordinate for PrintXXX functions */

    const GLCD_FontDef* CurrentFont; /**< Pointer to GLCD font to use for text drawing */
} tssd1306;

/**
 * @brief Callbacks used for communicating with the display.
 * 
 */
typedef struct DisplayInterfaceProcs_s {
    void ( *StartTransmission ) ( tssd1306* DeviceHandle, bool IsCommand ); /**< Begin talking to the display */
    size_t ( *Write ) ( tssd1306* DeviceHandle, const uint8_t* Data, const size_t Length ); /**< Write buffer to the display */
    void ( *WriteByte ) ( tssd1306* DeviceHandle, const uint8_t Data ); /**< Write single byte to the display */
    void ( *EndTransmission ) ( tssd1306* DeviceHandle ); /**< Finish writing to the display */

    size_t MaxTransferSize; /**< Maximum number of bytes per transmission */
} DisplayInterfaceProcs;

#ifdef __cplusplus
    extern "C" {
#endif

__attribute__( ( weak ) ) size_t EEPROMRead( const uint16_t Address, uint8_t* Buffer, size_t Length );
__attribute__( ( weak ) ) uint8_t EEPROMReadByte( const uint16_t Address );

#if defined HAS_DEBUG
    __attribute__( ( weak ) ) void DebugPrintString( const char* Fmt, ... );
#else
    #define DebugPrintString( Fmt, ... )
#endif

/**
 * @brief Sends a command to the display that takes no parameters
 * 
 * @param [ in ] DeviceHandle Pointer to device handle
 * @param [ in ] Command Opcode of command
 * @remark For example, SSD1306_Op_Horizontal_Flip_On is a single byte command
 */
void SSD1306_SendSingleByteCommand( tssd1306* DeviceHandle, const uint8_t Command );

/**
 * @brief Sends a command to the display that takes a single parameter
 * 
 * @param [ in ] DeviceHandle Pointer to device handle
 * @param [ in ] Command Opcode of command
 * @param [ in ] Param0 Command parameter
 * @remark For example, SSD1306_Op_SetContrast is a double byte command
 */
void SSD1306_SendDoubleByteCommand( tssd1306* DeviceHandle, const uint8_t Command, const uint8_t Param0 );

/**
 * @brief Sends a command to the display that takes two parameters
 * 
 * @param [ in ] DeviceHandle Pointer to device handle
 * @param [ in ] Command Opcode of command 
 * @param [ in ] Param0 First parameter
 * @param [ in ] Param1 Second parameter
 * @remark SSD1306_Op_SetColumnAddress is an example of a triple byte command
 */
void SSD1306_SendTripleByteCommand( tssd1306* DeviceHandle, const uint8_t Command, const uint8_t Param0, const uint8_t Param1 );

/**
 * @brief Writes data from the given source to the display
 * 
 * @param [ in ] DeviceHandle Pointer to device handle
 * @param [ in ] Source Where to pull the data from 
 * @param [ in ] Data Pointer to data, except for EEPROMS where this is an address within the EEPROM
 * @param [ in ] Length Length of data to send 
 */
void SSD1306_WriteData( tssd1306* DeviceHandle, DataSource Source, const uint8_t* Data, size_t Length );

/**
 * @brief Writes a single byte to the display
 * 
 * @param [ in ] DeviceHandle Pointer to device handle
 * @param [ in ] Data Data byte to write to the display 
 */
void SSD1306_WriteDataByte( tssd1306* DeviceHandle, const uint8_t Data );

/**
 * @brief Fills the screen with (Pattern)
 * 
 * @param [ in ] DeviceHandle Pointer to device handle
 * @param [ in ] Pattern 8 Bit pattern to fill the screen with.
 * @remark Pattern corresponds to 8 pixels vertically with bit 0 being the top pixel and bit 7 being the bottom.
 * @remark For example, a pattern of 1 would be a line going horizontally from one side of the screen to the other every 8 pixels vertically.
 */
void SSD1306_Clear( tssd1306* DeviceHandle, const uint8_t Pattern );

/**
 * @brief Draws an individual pixel
 * 
 * @param [ in ] DeviceHandle Pointer to device handle
 * @param [ in ] x X Coordinate 
 * @param [ in ] y Y Coordinate
 * @remark This overwrites any existing pixels at the page the y coordinate is located on
 * @remark For example, if you have a pixel on at 0,0 and you then draw a pixel at 0,1 then the first pixel will be overwritten
 * @remark and only the one at 0,1 will be visible
 */
void SSD1306_DrawPixel( tssd1306* DeviceHandle, const int x, const int y );

/**
 * @brief Draws a horizontal line
 * 
 * @param [ in ] DeviceHandle Pointer to device handle 
 * @param [ in ] x0 Start X coordinate
 * @param [ in ] y Start Y coordinate
 * @param [ in ] x1 End X coordinate
 * @remark This will overwrite anything already within the same page ( y / 8 )
 */
void SSD1306_DrawHLine( tssd1306* DeviceHandle, const int x0, const int y, const int x1 );

/**
 * @brief Draws a vertical line
 * 
 * @param [ in ] DeviceHandle Pointer to device handle
 * @param [ in ] x Start X coordinate
 * @param [ in ] y0 Start Y coordinate
 * @param [ in ] y1 End Y coordinate
 */
void SSD1306_DrawVLine( tssd1306* DeviceHandle, const int x, const int y0, const int y1 );

/**
 * @brief Fills a section of screen with white, y coordinate must be 8 aligned
 * 
 * @param [ in ] DeviceHandle Pointer to device handle 
 * @param [ in ] x0 Start X coordinate 
 * @param [ in ] y0 Start Y cooddinate 
 * @param [ in ] x1 End X coordinate 
 * @param [ in ] y1 End Y coordinate 
 */
void SSD1306_FillRect( tssd1306* DeviceHandle, const int x0, const int y0, const int x1, const int y1 );

/**
 * @brief Draws a character
 * 
 * @param [ in ] DeviceHandle Pointer to device handle
 * @param [ in ] c Character to draw
 * @param [ in ] x X Coordinate
 * @param [ in ] y Y Coordinate
 * @return int Width of the character if drawn, -1 if character would be clipped or is not in the font
 */
int SSD1306_DrawChar( tssd1306* DeviceHandle, const char c, const int x, const int y );

/**
 * @brief Draws a string of characters
 * 
 * @param [ in ] DeviceHandle Pointer to device handle
 * @param [ in ] Text String to draw
 * @param [ in ] x X Coordinate
 * @param [ in ] y Y Coordinate
 * @return X Coordinate after last character
 * @remark This will obey newline characters as well as move down a row if the end of the screen is reached
 */
int SSD1306_DrawString( tssd1306* DeviceHandle, const char* Text, int x, int y );

/**
 * @brief Sets the location where the SSD1306_Printxxx routines should start drawing characters
 * 
 * @param [ in ] DeviceHandle Pointer to device handle
 * @param [ in ] x New X cursor coordinate 
 * @param [ in ] y New Y cursor coordinage 
 */
void SSD1306_SetPrintCursor( tssd1306* DeviceHandle, const int x, const int y );

/**
 * @brief Gets the location of the cursor used in the SSD1306_Printxxx routines
 * 
 * @param [ in ] DeviceHandle Pointer to device handle
 * @param [ out ] x Current cursor X coordinate 
 * @param [ out ] y Current cursor Y coordinate 
 */
void SSD1306_GetPrintCursor( tssd1306* DeviceHandle, int* x, int* y );

/**
 * @brief Draws a character to the screen
 * 
 * @param [ in ] DeviceHandle Pointer to device handle
 * @param [ in ] c Character to draw 
 * @remark Supported escape characters are \r \n \t
 */
void SSD1306_PrintChar( tssd1306* DeviceHandle, const char c );

/**
 * @brief Draws a string of characters to the screen
 * 
 * @param [ in ] DeviceHandle Pointer to device handle
 * @param [ in ] Text Text to draw 
 */
void SSD1306_PrintString( tssd1306* DeviceHandle, const char* Text );

/**
 * @brief Draws an integer to the screen
 * 
 * @param [ in ] DeviceHandle Pointer to device handle
 * @param [ in ] Value Integer value to draw 
 */
void SSD1306_PrintInt( tssd1306* DeviceHandle, const int Value );

/**
 * @brief Sets the current font
 * 
 * @param [ in ] DeviceHandle Pointer to device handle
 * @param Font [ in ] New font to use
 */
void SSD1306_SetFont( tssd1306* DeviceHandle, const GLCD_FontDef* Font );

/**
 * @brief Initializes and zeroes out the display
 * 
 * @param [ in ] DeviceHandle Pointer to device handle
 */
void SSD1306_Init( tssd1306* DeviceHandle );

#ifdef __cplusplus
    }
#endif

#endif
