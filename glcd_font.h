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

extern const GLCD_FontDef Font_Tarable7Seg_16x32;

extern const GLCD_FontDef Font_Terminus_6x12;
extern const GLCD_FontDef Font_Terminus_9x18;
extern const GLCD_FontDef Font_Terminus_10x23;

extern const GLCD_FontDef Font_Droid_Sans_Fallback_9x11;
extern const GLCD_FontDef Font_Droid_Sans_Fallback_11x12;
extern const GLCD_FontDef Font_Droid_Sans_Fallback_13x14;
extern const GLCD_FontDef Font_Droid_Sans_Fallback_15x17;
extern const GLCD_FontDef Font_Droid_Sans_Fallback_17x18;
extern const GLCD_FontDef Font_Droid_Sans_Fallback_19x22;

extern const GLCD_FontDef Font_BM437_IBM_BIOS_8x8;

#ifdef __cplusplus
}
#endif

#endif
