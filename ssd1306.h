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

/**
 * @brief Width of your display
 * 
 */
#define SSD1306_CFG_WIDTH 128

/**
 * @brief Height of your display
 * 
 */
#define SSD1306_CFG_HEIGHT 64

/**
 * @brief I2C Address of your display
 * 
 */
#define SSD1306_CFG_ADDRESS 0x3C

#define DisplayAddress SSD1306_CFG_ADDRESS
#define DisplayWidth SSD1306_CFG_WIDTH
#define DisplayHeight SSD1306_CFG_HEIGHT
#define DisplayPages ( SSD1306_CFG_HEIGHT / 8 )

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
 * @brief Structure containing pointers to I2C communication functions
 * 
 */
typedef struct {
    void ( *StartTransmission ) ( const int Address );
    void ( *Write ) ( const uint8_t* Data, const size_t Length );
    void ( *EndTransmission ) ( void );

    /**
     * @remark Maximum number of bytes your I2C API can transmit at a time
     * @remark The API will split up larger transfers to fit within this limit
     */
    const size_t TXBufferLen;
} I2CProcs;

#ifdef __cplusplus
    extern "C" {
#endif

/**
 * @brief Fills the screen with (Pattern)
 * 
 * @param [ in ] Pattern 8 Bit pattern to fill the screen with.
 * @remark Pattern corresponds to 8 pixels vertically with bit 0 being the top pixel and bit 7 being the bottom.
 * @remark For example, a pattern of 1 would be a line going horizontally from one side of the screen to the other every 8 pixels vertically.
 */
void SSD1306_Clear( const uint8_t Pattern );

/**
 * @brief Draws an individual pixel
 * 
 * @param x [ in ] X Coordinate 
 * @param y [ in ] Y Coordinate
 * @param Color [ in ] Pixel color
 * @remark This overwrites any existing pixels at the page the y coordinate is located on
 * @remark For example, if you have a pixel on at 0,0 and you then draw a pixel at 0,1 then the first pixel will be overwritten
 * @remark and only the one at 0,1 will be visible
 */
void SSD1306_DrawPixel( const int x, const int y, const int Color );

/**
 * @brief Draws a horizontal line
 * 
 * @param x0 [ in ] Start X coordinate
 * @param y [ in ] Start Y coordinate
 * @param x1 [ in ] End X coordinate
 * @param Color Line color
 * @remark This will overwrite anything already within the same page ( y / 8 )
 */
void SSD1306_DrawHLine( const int x0, const int y, const int x1, const int Color );

/**
 * @brief Draws a vertical line
 * 
 * @param x [ in ] Start X coordinate
 * @param y0 [ in ] Start Y coordinate
 * @param y1 [ in ] End Y coordinate
 * @param Color [ in ] Line color
 */
void SSD1306_DrawVLine( const int x, const int y0, const int y1, const int Color );

/**
 * @brief Draws a character
 * 
 * @param c [ in ] Character to draw
 * @param x [ in ] X Coordinate
 * @param y [ in ] Y Coordinate
 * @param Color [ in ] Color to draw character
 * @return int Width of the character if drawn, -1 if character would be clipped or is not in the font
 */
int SSD1306_DrawChar( const char c, const int x, const int y, const int Color );

/**
 * @brief Draws a string of characters
 * 
 * @param Text [ in ] String to draw
 * @param x [ in ] X Coordinate
 * @param y [ in ] Y Coordinate
 * @param Color [ in ] Color to draw characters
 * @remark This will obey newline characters as well as move down a row if the end of the screen is reached
 */
void SSD1306_DrawString( const char* Text, int x, int y, const int Color );

/**
 * @brief Sets the current font
 * 
 * @param Font [ in ] New font to use
 */
void SSD1306_SetFont( const GLCD_FontDef* Font );

/**
 * @brief Initializes and zeroes out the display
 * 
 * @param I2CInterface [ in ] I2C Interface
 */
void SSD1306_Init( const I2CProcs* I2CInterface );

#ifdef __cplusplus
    }
#endif

#endif
