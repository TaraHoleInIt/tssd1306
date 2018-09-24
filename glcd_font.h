#ifndef _GLCD_FONT_H_
#define _GLCD_FONT_H_

#include <stdint.h>
#include <stdbool.h>

/**
 * @brief Contains information needed to render characters within the font
 * 
 */
typedef struct {
    const uint8_t* Data; /**< Pointer to actual font data */
    int FontWidthPx; /**< Width of font in pixels */
    int FontHeightPx; /**< Height of font in pixels */
    int FontHeightPxRoundedUp; /**< Height of font rounded up to the nearest 8 aligned number. ie. a 22px high font should have 24 here */
    int FirstChar; /**< First character in font */
    int LastChar; /**< Last character in font */
    bool IsStream; /**< Set to true if this font was size reduced and needs a different character lookup function */
} GLCD_FontDef;

#ifdef __cplusplus
extern "C" {
#endif

extern const GLCD_FontDef Font_Droid_Sans_7x10;
extern const GLCD_FontDef Font_Ubuntu_Mono_9x16;
extern const GLCD_FontDef Font_Ubuntu_Mono_Bold_9x16;
extern const GLCD_FontDef Font_Ubuntu_Mono_7x13;
extern const GLCD_FontDef Font_Ubuntu_Mono_13x22;

extern const GLCD_FontDef Font_Tarable7Seg_16x32;
extern const GLCD_FontDef Font_Tarable7Seg_32x64;

#ifdef __cplusplus
}
#endif

#endif
