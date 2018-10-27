#include <avr/pgmspace.h>
#include "../ssd1306.h"
#include "../glcd_font.h"

//WARNING: This Font Require X-GLCD Lib.
//         You can not use it with MikroE GLCD Lib.

//Font Generated by MikroElektronika GLCD Font Creator 1.2.0.0
//MikroElektronika 2011 
//http://www.mikroe.com 

//GLCD FontName : Droid_Sans_Fallback15x17
//GLCD FontSize : 15 x 17
PROGMEM static const uint8_t Droid_Sans_Fallback_15x17_Data[ ] = {
	/*   */ 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	/* ! */ 0x02, 0x00, 0x00, 0x00, 0xFE, 0x13, 0x00, 
	/* " */ 0x05, 0x00, 0x00, 0x00, 0x1E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1E, 0x00, 0x00, 
	/* # */ 0x09, 0x00, 0x02, 0x00, 0x10, 0x1E, 0x00, 0xF0, 0x03, 0x00, 0x1E, 0x02, 0x00, 0x10, 0x02, 0x00, 0x10, 0x1E, 0x00, 0xF0, 0x03, 0x00, 0x1E, 0x02, 0x00, 0x10, 0x00, 0x00, 
	/* $ */ 0x08, 0x00, 0x00, 0x00, 0x18, 0x04, 0x00, 0x24, 0x08, 0x00, 0x42, 0x10, 0x00, 0xFF, 0x3F, 0x00, 0x42, 0x10, 0x00, 0x84, 0x08, 0x00, 0x08, 0x07, 0x00, 
	/* % */ 0x0D, 0x00, 0x00, 0x00, 0x3C, 0x00, 0x00, 0x42, 0x00, 0x00, 0x42, 0x10, 0x00, 0x42, 0x0C, 0x00, 0x3C, 0x02, 0x00, 0x80, 0x01, 0x00, 0x60, 0x00, 0x00, 0x10, 0x0F, 0x00, 0x8C, 0x10, 0x00, 0x82, 0x10, 0x00, 0x80, 0x10, 0x00, 0x00, 0x0F, 0x00, 
	/* & */ 0x0B, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x9C, 0x08, 0x00, 0x62, 0x10, 0x00, 0x42, 0x10, 0x00, 0xA2, 0x10, 0x00, 0x1C, 0x11, 0x00, 0x00, 0x0A, 0x00, 0x00, 0x04, 0x00, 0x00, 0x0A, 0x00, 0x00, 0x11, 0x00, 
	/* ' */ 0x02, 0x00, 0x00, 0x00, 0x1E, 0x00, 0x00, 
	/* ( */ 0x04, 0x00, 0x00, 0x00, 0xE0, 0x1F, 0x00, 0x1C, 0xE0, 0x00, 0x02, 0x00, 0x01, 
	/* ) */ 0x04, 0x00, 0x00, 0x00, 0x02, 0x00, 0x01, 0x1C, 0xE0, 0x00, 0xE0, 0x1F, 0x00, 
	/* * */ 0x05, 0x04, 0x00, 0x00, 0x38, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x38, 0x00, 0x00, 0x04, 0x00, 0x00, 
	/* + */ 0x08, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x80, 0x00, 0x00, 0x80, 0x00, 0x00, 0xF0, 0x07, 0x00, 0x80, 0x00, 0x00, 0x80, 0x00, 0x00, 0x80, 0x00, 0x00, 
	/* , */ 0x03, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x70, 0x00, 
	/* - */ 0x04, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 
	/* . */ 0x02, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 
	/* / */ 0x04, 0x00, 0x18, 0x00, 0x80, 0x07, 0x00, 0x78, 0x00, 0x00, 0x06, 0x00, 0x00, 
	/* 0 */ 0x08, 0x00, 0x00, 0x00, 0xF0, 0x03, 0x00, 0x0C, 0x0C, 0x00, 0x02, 0x10, 0x00, 0x02, 0x10, 0x00, 0x02, 0x10, 0x00, 0x0C, 0x0C, 0x00, 0xF0, 0x03, 0x00, 
	/* 1 */ 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x04, 0x00, 0x00, 0xFE, 0x1F, 0x00, 
	/* 2 */ 0x08, 0x00, 0x00, 0x00, 0x08, 0x18, 0x00, 0x04, 0x14, 0x00, 0x02, 0x12, 0x00, 0x02, 0x11, 0x00, 0x82, 0x10, 0x00, 0x44, 0x10, 0x00, 0x38, 0x10, 0x00, 
	/* 3 */ 0x08, 0x00, 0x00, 0x00, 0x08, 0x04, 0x00, 0x04, 0x08, 0x00, 0x02, 0x10, 0x00, 0x42, 0x10, 0x00, 0x42, 0x10, 0x00, 0xA4, 0x08, 0x00, 0x18, 0x07, 0x00, 
	/* 4 */ 0x08, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x80, 0x02, 0x00, 0x60, 0x02, 0x00, 0x10, 0x02, 0x00, 0x0C, 0x02, 0x00, 0xFE, 0x1F, 0x00, 0x00, 0x02, 0x00, 
	/* 5 */ 0x08, 0x00, 0x00, 0x00, 0x7E, 0x04, 0x00, 0x42, 0x08, 0x00, 0x22, 0x10, 0x00, 0x22, 0x10, 0x00, 0x22, 0x10, 0x00, 0x42, 0x08, 0x00, 0x82, 0x07, 0x00, 
	/* 6 */ 0x08, 0x00, 0x00, 0x00, 0xF8, 0x07, 0x00, 0x44, 0x08, 0x00, 0x22, 0x10, 0x00, 0x22, 0x10, 0x00, 0x22, 0x10, 0x00, 0x44, 0x08, 0x00, 0x88, 0x07, 0x00, 
	/* 7 */ 0x08, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x02, 0x00, 0x00, 0x02, 0x00, 0x00, 0x02, 0x1C, 0x00, 0x82, 0x03, 0x00, 0x72, 0x00, 0x00, 0x0E, 0x00, 0x00, 
	/* 8 */ 0x08, 0x00, 0x00, 0x00, 0x18, 0x07, 0x00, 0xA4, 0x08, 0x00, 0x42, 0x10, 0x00, 0x42, 0x10, 0x00, 0x42, 0x10, 0x00, 0xA4, 0x08, 0x00, 0x18, 0x07, 0x00, 
	/* 9 */ 0x08, 0x00, 0x00, 0x00, 0x78, 0x04, 0x00, 0x84, 0x08, 0x00, 0x02, 0x11, 0x00, 0x02, 0x11, 0x00, 0x02, 0x11, 0x00, 0x84, 0x08, 0x00, 0xF8, 0x07, 0x00, 
	/* : */ 0x02, 0x00, 0x00, 0x00, 0x20, 0x10, 0x00, 
	/* ; */ 0x03, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x20, 0x70, 0x00, 
	/* < */ 0x08, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x40, 0x01, 0x00, 0x40, 0x01, 0x00, 0x20, 0x02, 0x00, 0x20, 0x02, 0x00, 0x10, 0x04, 0x00, 0x10, 0x04, 0x00, 
	/* = */ 0x08, 0x00, 0x00, 0x00, 0x20, 0x01, 0x00, 0x20, 0x01, 0x00, 0x20, 0x01, 0x00, 0x20, 0x01, 0x00, 0x20, 0x01, 0x00, 0x20, 0x01, 0x00, 0x20, 0x01, 0x00, 
	/* > */ 0x08, 0x00, 0x00, 0x00, 0x10, 0x04, 0x00, 0x10, 0x04, 0x00, 0x20, 0x02, 0x00, 0x20, 0x02, 0x00, 0x40, 0x01, 0x00, 0x40, 0x01, 0x00, 0x80, 0x00, 0x00, 
	/* ? */ 0x08, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x04, 0x00, 0x00, 0x02, 0x00, 0x00, 0x02, 0x13, 0x00, 0x82, 0x00, 0x00, 0x44, 0x00, 0x00, 0x38, 0x00, 0x00, 
	/* @ */ 0x0F, 0x00, 0x00, 0x00, 0xC0, 0x0F, 0x00, 0x30, 0x30, 0x00, 0x08, 0x40, 0x00, 0x84, 0x4F, 0x00, 0x64, 0x90, 0x00, 0x22, 0x90, 0x00, 0x12, 0x90, 0x00, 0x12, 0x88, 0x00, 0x12, 0x9F, 0x00, 0xF2, 0x90, 0x00, 0x04, 0x50, 0x00, 0x04, 0x08, 0x00, 0x18, 0x0C, 0x00, 0xE0, 0x03, 0x00, 
	/* A */ 0x0B, 0x00, 0x18, 0x00, 0x00, 0x06, 0x00, 0x80, 0x01, 0x00, 0x60, 0x01, 0x00, 0x18, 0x01, 0x00, 0x06, 0x01, 0x00, 0x18, 0x01, 0x00, 0x60, 0x01, 0x00, 0x80, 0x01, 0x00, 0x00, 0x06, 0x00, 0x00, 0x18, 0x00, 
	/* B */ 0x0A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x1F, 0x00, 0x42, 0x10, 0x00, 0x42, 0x10, 0x00, 0x42, 0x10, 0x00, 0x42, 0x10, 0x00, 0x42, 0x10, 0x00, 0xA4, 0x08, 0x00, 0x18, 0x07, 0x00, 
	/* C */ 0x0B, 0x00, 0x00, 0x00, 0xF0, 0x03, 0x00, 0x0C, 0x0C, 0x00, 0x04, 0x08, 0x00, 0x02, 0x10, 0x00, 0x02, 0x10, 0x00, 0x02, 0x10, 0x00, 0x02, 0x10, 0x00, 0x04, 0x08, 0x00, 0x0C, 0x0C, 0x00, 0x10, 0x02, 0x00, 
	/* D */ 0x0B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x1F, 0x00, 0x02, 0x10, 0x00, 0x02, 0x10, 0x00, 0x02, 0x10, 0x00, 0x02, 0x10, 0x00, 0x02, 0x10, 0x00, 0x04, 0x08, 0x00, 0x0C, 0x0C, 0x00, 0xF0, 0x03, 0x00, 
	/* E */ 0x0A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x1F, 0x00, 0x42, 0x10, 0x00, 0x42, 0x10, 0x00, 0x42, 0x10, 0x00, 0x42, 0x10, 0x00, 0x42, 0x10, 0x00, 0x42, 0x10, 0x00, 0x02, 0x10, 0x00, 
	/* F */ 0x0A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x1F, 0x00, 0x42, 0x00, 0x00, 0x42, 0x00, 0x00, 0x42, 0x00, 0x00, 0x42, 0x00, 0x00, 0x42, 0x00, 0x00, 0x42, 0x00, 0x00, 0x02, 0x00, 0x00, 
	/* G */ 0x0B, 0x00, 0x00, 0x00, 0xF0, 0x03, 0x00, 0x0C, 0x0C, 0x00, 0x04, 0x08, 0x00, 0x02, 0x10, 0x00, 0x02, 0x10, 0x00, 0x02, 0x10, 0x00, 0x82, 0x10, 0x00, 0x84, 0x08, 0x00, 0x8C, 0x0C, 0x00, 0x90, 0x1F, 0x00, 
	/* H */ 0x0A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x1F, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0xFE, 0x1F, 0x00, 
	/* I */ 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x1F, 0x00, 
	/* J */ 0x06, 0x00, 0x0E, 0x00, 0x00, 0x10, 0x00, 0x00, 0x10, 0x00, 0x00, 0x10, 0x00, 0x00, 0x10, 0x00, 0xFE, 0x0F, 0x00, 
	/* K */ 0x0A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x1F, 0x00, 0x40, 0x00, 0x00, 0xA0, 0x00, 0x00, 0x10, 0x01, 0x00, 0x08, 0x02, 0x00, 0x04, 0x04, 0x00, 0x02, 0x08, 0x00, 0x00, 0x10, 0x00, 
	/* L */ 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x1F, 0x00, 0x00, 0x10, 0x00, 0x00, 0x10, 0x00, 0x00, 0x10, 0x00, 0x00, 0x10, 0x00, 0x00, 0x10, 0x00, 0x00, 0x10, 0x00, 
	/* M */ 0x0B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x1F, 0x00, 0x18, 0x00, 0x00, 0x60, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x06, 0x00, 0x80, 0x01, 0x00, 0x60, 0x00, 0x00, 0x18, 0x00, 0x00, 0xFE, 0x1F, 0x00, 
	/* N */ 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x1F, 0x00, 0x0C, 0x00, 0x00, 0x30, 0x00, 0x00, 0xC0, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x0C, 0x00, 0xFE, 0x1F, 0x00, 
	/* O */ 0x0B, 0x00, 0x00, 0x00, 0xF0, 0x03, 0x00, 0x0C, 0x0C, 0x00, 0x04, 0x08, 0x00, 0x02, 0x10, 0x00, 0x02, 0x10, 0x00, 0x02, 0x10, 0x00, 0x02, 0x10, 0x00, 0x04, 0x08, 0x00, 0x0C, 0x0C, 0x00, 0xF0, 0x03, 0x00, 
	/* P */ 0x0A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x1F, 0x00, 0x82, 0x00, 0x00, 0x82, 0x00, 0x00, 0x82, 0x00, 0x00, 0x82, 0x00, 0x00, 0x82, 0x00, 0x00, 0x44, 0x00, 0x00, 0x38, 0x00, 0x00, 
	/* Q */ 0x0B, 0x00, 0x00, 0x00, 0xF0, 0x03, 0x00, 0x0C, 0x0C, 0x00, 0x04, 0x08, 0x00, 0x02, 0x10, 0x00, 0x02, 0x10, 0x00, 0x02, 0x12, 0x00, 0x02, 0x14, 0x00, 0x04, 0x08, 0x00, 0x0C, 0x1C, 0x00, 0xF0, 0x23, 0x00, 
	/* R */ 0x0B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x1F, 0x00, 0x82, 0x00, 0x00, 0x82, 0x00, 0x00, 0x82, 0x00, 0x00, 0x82, 0x00, 0x00, 0x82, 0x00, 0x00, 0x44, 0x01, 0x00, 0x38, 0x0E, 0x00, 0x00, 0x10, 0x00, 
	/* S */ 0x0A, 0x00, 0x00, 0x00, 0x18, 0x04, 0x00, 0x24, 0x08, 0x00, 0x42, 0x10, 0x00, 0x42, 0x10, 0x00, 0x42, 0x10, 0x00, 0x42, 0x10, 0x00, 0x42, 0x10, 0x00, 0x84, 0x08, 0x00, 0x08, 0x07, 0x00, 
	/* T */ 0x09, 0x02, 0x00, 0x00, 0x02, 0x00, 0x00, 0x02, 0x00, 0x00, 0x02, 0x00, 0x00, 0xFE, 0x1F, 0x00, 0x02, 0x00, 0x00, 0x02, 0x00, 0x00, 0x02, 0x00, 0x00, 0x02, 0x00, 0x00, 
	/* U */ 0x0A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x07, 0x00, 0x00, 0x08, 0x00, 0x00, 0x10, 0x00, 0x00, 0x10, 0x00, 0x00, 0x10, 0x00, 0x00, 0x10, 0x00, 0x00, 0x08, 0x00, 0xFE, 0x07, 0x00, 
	/* V */ 0x0B, 0x06, 0x00, 0x00, 0x18, 0x00, 0x00, 0x60, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x06, 0x00, 0x00, 0x18, 0x00, 0x00, 0x06, 0x00, 0x80, 0x01, 0x00, 0x60, 0x00, 0x00, 0x18, 0x00, 0x00, 0x06, 0x00, 0x00, 
	/* W */ 0x0F, 0x06, 0x00, 0x00, 0x38, 0x00, 0x00, 0xC0, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x03, 0x00, 0xE0, 0x00, 0x00, 0x1C, 0x00, 0x00, 0xE0, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x03, 0x00, 0xC0, 0x00, 0x00, 0x38, 0x00, 0x00, 0x06, 0x00, 0x00, 
	/* X */ 0x0B, 0x02, 0x10, 0x00, 0x04, 0x08, 0x00, 0x08, 0x04, 0x00, 0x10, 0x02, 0x00, 0x20, 0x01, 0x00, 0xC0, 0x00, 0x00, 0x20, 0x01, 0x00, 0x10, 0x02, 0x00, 0x08, 0x04, 0x00, 0x04, 0x08, 0x00, 0x02, 0x10, 0x00, 
	/* Y */ 0x0B, 0x02, 0x00, 0x00, 0x04, 0x00, 0x00, 0x08, 0x00, 0x00, 0x10, 0x00, 0x00, 0x20, 0x00, 0x00, 0xC0, 0x1F, 0x00, 0x20, 0x00, 0x00, 0x10, 0x00, 0x00, 0x08, 0x00, 0x00, 0x04, 0x00, 0x00, 0x02, 0x00, 0x00, 
	/* Z */ 0x09, 0x00, 0x00, 0x00, 0x02, 0x18, 0x00, 0x02, 0x14, 0x00, 0x02, 0x13, 0x00, 0x82, 0x10, 0x00, 0x42, 0x10, 0x00, 0x32, 0x10, 0x00, 0x0A, 0x10, 0x00, 0x06, 0x10, 0x00, 
	/* [ */ 0x04, 0x00, 0x00, 0x00, 0xFE, 0xFF, 0x01, 0x02, 0x00, 0x01, 0x02, 0x00, 0x01, 
	/* \ */ 0x04, 0x06, 0x00, 0x00, 0x78, 0x00, 0x00, 0x80, 0x07, 0x00, 0x00, 0x18, 0x00, 
	/* ] */ 0x03, 0x02, 0x00, 0x01, 0x02, 0x00, 0x01, 0xFE, 0xFF, 0x01, 
	/* ^ */ 0x06, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x04, 0x00, 0x00, 0x02, 0x00, 0x00, 0x04, 0x00, 0x00, 0x08, 0x00, 0x00, 
	/* _ */ 0x09, 0x00, 0x80, 0x00, 0x00, 0x80, 0x00, 0x00, 0x80, 0x00, 0x00, 0x80, 0x00, 0x00, 0x80, 0x00, 0x00, 0x80, 0x00, 0x00, 0x80, 0x00, 0x00, 0x80, 0x00, 0x00, 0x80, 0x00, 
	/* ` */ 0x04, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x02, 0x00, 0x00, 0x04, 0x00, 0x00, 
	/* a */ 0x09, 0x00, 0x00, 0x00, 0x20, 0x0E, 0x00, 0x10, 0x11, 0x00, 0x10, 0x11, 0x00, 0x10, 0x11, 0x00, 0x10, 0x11, 0x00, 0x10, 0x11, 0x00, 0xE0, 0x0F, 0x00, 0x00, 0x10, 0x00, 
	/* b */ 0x08, 0x00, 0x00, 0x00, 0xFE, 0x1F, 0x00, 0x20, 0x08, 0x00, 0x10, 0x10, 0x00, 0x10, 0x10, 0x00, 0x10, 0x10, 0x00, 0x20, 0x08, 0x00, 0xC0, 0x07, 0x00, 
	/* c */ 0x08, 0x00, 0x00, 0x00, 0xC0, 0x07, 0x00, 0x20, 0x08, 0x00, 0x10, 0x10, 0x00, 0x10, 0x10, 0x00, 0x10, 0x10, 0x00, 0x20, 0x08, 0x00, 0x40, 0x04, 0x00, 
	/* d */ 0x08, 0x00, 0x00, 0x00, 0xC0, 0x07, 0x00, 0x20, 0x08, 0x00, 0x10, 0x10, 0x00, 0x10, 0x10, 0x00, 0x10, 0x10, 0x00, 0x20, 0x08, 0x00, 0xFE, 0x1F, 0x00, 
	/* e */ 0x08, 0x00, 0x00, 0x00, 0xC0, 0x07, 0x00, 0x20, 0x09, 0x00, 0x10, 0x11, 0x00, 0x10, 0x11, 0x00, 0x10, 0x11, 0x00, 0x20, 0x09, 0x00, 0xC0, 0x05, 0x00, 
	/* f */ 0x05, 0x10, 0x00, 0x00, 0x10, 0x00, 0x00, 0xFC, 0x1F, 0x00, 0x12, 0x00, 0x00, 0x12, 0x00, 0x00, 
	/* g */ 0x08, 0x00, 0x00, 0x00, 0xC0, 0x07, 0x00, 0x20, 0x08, 0x01, 0x10, 0x10, 0x01, 0x10, 0x10, 0x01, 0x10, 0x10, 0x01, 0x20, 0x88, 0x00, 0xF0, 0x7F, 0x00, 
	/* h */ 0x08, 0x00, 0x00, 0x00, 0xFE, 0x1F, 0x00, 0x20, 0x00, 0x00, 0x10, 0x00, 0x00, 0x10, 0x00, 0x00, 0x10, 0x00, 0x00, 0x20, 0x00, 0x00, 0xC0, 0x1F, 0x00, 
	/* i */ 0x02, 0x00, 0x00, 0x00, 0xF2, 0x1F, 0x00, 
	/* j */ 0x02, 0x00, 0x00, 0x01, 0xF2, 0xFF, 0x00, 
	/* k */ 0x08, 0x00, 0x00, 0x00, 0xFE, 0x1F, 0x00, 0x00, 0x01, 0x00, 0x80, 0x01, 0x00, 0x40, 0x02, 0x00, 0x20, 0x04, 0x00, 0x10, 0x08, 0x00, 0x00, 0x10, 0x00, 
	/* l */ 0x02, 0x00, 0x00, 0x00, 0xFE, 0x1F, 0x00, 
	/* m */ 0x0C, 0x00, 0x00, 0x00, 0xF0, 0x1F, 0x00, 0x20, 0x00, 0x00, 0x10, 0x00, 0x00, 0x10, 0x00, 0x00, 0x20, 0x00, 0x00, 0xC0, 0x1F, 0x00, 0x20, 0x00, 0x00, 0x10, 0x00, 0x00, 0x10, 0x00, 0x00, 0x20, 0x00, 0x00, 0xC0, 0x1F, 0x00, 
	/* n */ 0x08, 0x00, 0x00, 0x00, 0xF0, 0x1F, 0x00, 0x20, 0x00, 0x00, 0x10, 0x00, 0x00, 0x10, 0x00, 0x00, 0x10, 0x00, 0x00, 0x20, 0x00, 0x00, 0xC0, 0x1F, 0x00, 
	/* o */ 0x08, 0x00, 0x00, 0x00, 0xC0, 0x07, 0x00, 0x20, 0x08, 0x00, 0x10, 0x10, 0x00, 0x10, 0x10, 0x00, 0x10, 0x10, 0x00, 0x20, 0x08, 0x00, 0xC0, 0x07, 0x00, 
	/* p */ 0x08, 0x00, 0x00, 0x00, 0xF0, 0xFF, 0x01, 0x20, 0x08, 0x00, 0x10, 0x10, 0x00, 0x10, 0x10, 0x00, 0x10, 0x10, 0x00, 0x20, 0x08, 0x00, 0xC0, 0x07, 0x00, 
	/* q */ 0x08, 0x00, 0x00, 0x00, 0xC0, 0x07, 0x00, 0x20, 0x08, 0x00, 0x10, 0x10, 0x00, 0x10, 0x10, 0x00, 0x10, 0x10, 0x00, 0x20, 0x08, 0x00, 0xF0, 0xFF, 0x01, 
	/* r */ 0x05, 0x00, 0x00, 0x00, 0xF0, 0x1F, 0x00, 0x20, 0x00, 0x00, 0x10, 0x00, 0x00, 0x10, 0x00, 0x00, 
	/* s */ 0x07, 0x00, 0x00, 0x00, 0xE0, 0x08, 0x00, 0x10, 0x11, 0x00, 0x10, 0x11, 0x00, 0x10, 0x11, 0x00, 0x10, 0x11, 0x00, 0x20, 0x0E, 0x00, 
	/* t */ 0x05, 0x10, 0x00, 0x00, 0x10, 0x00, 0x00, 0xFE, 0x0F, 0x00, 0x10, 0x10, 0x00, 0x10, 0x00, 0x00, 
	/* u */ 0x08, 0x00, 0x00, 0x00, 0xF0, 0x07, 0x00, 0x00, 0x08, 0x00, 0x00, 0x10, 0x00, 0x00, 0x10, 0x00, 0x00, 0x10, 0x00, 0x00, 0x08, 0x00, 0xF0, 0x1F, 0x00, 
	/* v */ 0x07, 0x30, 0x00, 0x00, 0xC0, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x03, 0x00, 0xC0, 0x00, 0x00, 0x30, 0x00, 0x00, 
	/* w */ 0x0B, 0x70, 0x00, 0x00, 0x80, 0x03, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x06, 0x00, 0x80, 0x01, 0x00, 0x70, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x06, 0x00, 0x00, 0x1C, 0x00, 0x80, 0x03, 0x00, 0x70, 0x00, 0x00, 
	/* x */ 0x07, 0x10, 0x10, 0x00, 0x60, 0x0C, 0x00, 0x80, 0x02, 0x00, 0x00, 0x01, 0x00, 0x80, 0x02, 0x00, 0x60, 0x0C, 0x00, 0x10, 0x10, 0x00, 
	/* y */ 0x07, 0x30, 0x00, 0x01, 0xC0, 0x00, 0x01, 0x00, 0xE3, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x03, 0x00, 0xC0, 0x00, 0x00, 0x30, 0x00, 0x00, 
	/* z */ 0x07, 0x00, 0x00, 0x00, 0x10, 0x18, 0x00, 0x10, 0x14, 0x00, 0x10, 0x13, 0x00, 0x90, 0x10, 0x00, 0x50, 0x10, 0x00, 0x30, 0x10, 0x00, 
	/* { */ 0x05, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0xFC, 0xFE, 0x00, 0x02, 0x00, 0x01, 0x02, 0x00, 0x01, 
	/* | */ 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0xFF, 0x01, 
	/* } */ 0x05, 0x02, 0x00, 0x01, 0x02, 0x00, 0x01, 0xFC, 0xFE, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 
	/* ~ */ 0x08, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x00, 0x02, 0x00, 0x00, 0x02, 0x00, 0x00, 0x04, 0x00, 0x00, 0x08, 0x00, 0x00, 0x08, 0x00, 0x00, 0x06, 0x00, 0x00, 
	/*  */ 0x04, 0xFE, 0x1F, 0x00, 0x02, 0x10, 0x00, 0x02, 0x10, 0x00, 0xFE, 0x1F, 0x00, 
};

static const int Droid_Sans_Fallback_15x17_OldSize = 4416;
static const int Droid_Sans_Fallback_15x17_Size = 2259;

const GLCD_FontDef Font_Droid_Sans_Fallback_15x17 = {
	Droid_Sans_Fallback_15x17_Data,
	15,
	17,
	24,
	'\x20',
	'\x7F',
	true,
	false
};
