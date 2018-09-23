#ifndef _GLCD_FONT_H_
#define _GLCD_FONT_H_

#include <stdint.h>

typedef struct {
    const uint8_t* Data;
    int FontWidthPx;
    int FontHeightPx;
    int FontHeightPxRoundedUp;
    int FirstChar;
    int LastChar;
} GLCD_FontDef;

#ifdef __cplusplus
extern "C" {
#endif

extern const GLCD_FontDef Font_Droid_Sans_7x10;
extern const GLCD_FontDef Font_Ubuntu_Mono_9x16;

extern const GLCD_FontDef Font_Tarable7Seg_16x32;
extern const GLCD_FontDef Font_Tarable7Seg_32x64;

#ifdef __cplusplus
}
#endif

#endif
