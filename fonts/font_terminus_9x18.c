#include <avr/pgmspace.h>
#include "../ssd1306.h"
#include "../glcd_font.h"

//WARNING: This Font Require X-GLCD Lib.
//         You can not use it with MikroE GLCD Lib.

//Font Generated by MikroElektronika GLCD Font Creator 1.2.0.0
//MikroElektronika 2011 
//http://www.mikroe.com 

//GLCD FontName : Terminus9x18
//GLCD FontSize : 9 x 18
PROGMEM static const uint8_t Terminus9x18_Data[ ] = {
	/*   */ 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	/* ! */ 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x67, 0x00, 
	/* " */ 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1E, 0x00, 0x00, 
	/* # */ 0x08, 0x00, 0x00, 0x00, 0x40, 0x08, 0x00, 0xF8, 0x7F, 0x00, 0x40, 0x08, 0x00, 0x40, 0x08, 0x00, 0x40, 0x08, 0x00, 0xF8, 0x7F, 0x00, 0x40, 0x08, 0x00, 
	/* $ */ 0x08, 0x00, 0x00, 0x00, 0xE0, 0x21, 0x00, 0x10, 0x42, 0x00, 0x10, 0x42, 0x00, 0xFC, 0xFF, 0x01, 0x10, 0x42, 0x00, 0x10, 0x42, 0x00, 0x20, 0x3C, 0x00, 
	/* % */ 0x09, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x28, 0x60, 0x00, 0x38, 0x18, 0x00, 0x00, 0x06, 0x00, 0x80, 0x01, 0x00, 0x60, 0x70, 0x00, 0x18, 0x50, 0x00, 0x00, 0x70, 0x00, 
	/* & */ 0x09, 0x00, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x70, 0x22, 0x00, 0x88, 0x41, 0x00, 0x08, 0x41, 0x00, 0x88, 0x42, 0x00, 0x70, 0x24, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x63, 0x00, 
	/* ' */ 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1E, 0x00, 0x00, 
	/* ( */ 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x0F, 0x00, 0x30, 0x30, 0x00, 0x08, 0x40, 0x00, 
	/* ) */ 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x40, 0x00, 0x30, 0x30, 0x00, 0xC0, 0x0F, 0x00, 
	/* * */ 0x08, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x20, 0x09, 0x00, 0x40, 0x05, 0x00, 0x80, 0x03, 0x00, 0x40, 0x05, 0x00, 0x20, 0x09, 0x00, 0x00, 0x01, 0x00, 
	/* + */ 0x08, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0xE0, 0x0F, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 
	/* , */ 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x70, 0x00, 
	/* - */ 0x08, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 
	/* . */ 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 
	/* / */ 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x18, 0x00, 0x00, 0x06, 0x00, 0x80, 0x01, 0x00, 0x60, 0x00, 0x00, 0x18, 0x00, 0x00, 
	/* 0 */ 0x08, 0x00, 0x00, 0x00, 0xF0, 0x3F, 0x00, 0x08, 0x44, 0x00, 0x08, 0x42, 0x00, 0x08, 0x41, 0x00, 0x88, 0x40, 0x00, 0x48, 0x40, 0x00, 0xF0, 0x3F, 0x00, 
	/* 1 */ 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x40, 0x00, 0x10, 0x40, 0x00, 0xF8, 0x7F, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 
	/* 2 */ 0x08, 0x00, 0x00, 0x00, 0x70, 0x60, 0x00, 0x08, 0x50, 0x00, 0x08, 0x48, 0x00, 0x08, 0x44, 0x00, 0x08, 0x42, 0x00, 0x08, 0x41, 0x00, 0xF0, 0x40, 0x00, 
	/* 3 */ 0x08, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00, 0x08, 0x40, 0x00, 0x08, 0x41, 0x00, 0x08, 0x41, 0x00, 0x08, 0x41, 0x00, 0x08, 0x41, 0x00, 0xF0, 0x3E, 0x00, 
	/* 4 */ 0x08, 0x00, 0x00, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x09, 0x00, 0x80, 0x08, 0x00, 0x40, 0x08, 0x00, 0x20, 0x08, 0x00, 0x10, 0x08, 0x00, 0xF8, 0x7F, 0x00, 
	/* 5 */ 0x08, 0x00, 0x00, 0x00, 0xF8, 0x31, 0x00, 0x08, 0x41, 0x00, 0x08, 0x41, 0x00, 0x08, 0x41, 0x00, 0x08, 0x41, 0x00, 0x08, 0x41, 0x00, 0x08, 0x3E, 0x00, 
	/* 6 */ 0x08, 0x00, 0x00, 0x00, 0xE0, 0x3F, 0x00, 0x10, 0x41, 0x00, 0x08, 0x41, 0x00, 0x08, 0x41, 0x00, 0x08, 0x41, 0x00, 0x08, 0x41, 0x00, 0x00, 0x3E, 0x00, 
	/* 7 */ 0x08, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x08, 0x00, 0x00, 0x08, 0x00, 0x00, 0x08, 0x78, 0x00, 0x08, 0x06, 0x00, 0x88, 0x01, 0x00, 0x78, 0x00, 0x00, 
	/* 8 */ 0x08, 0x00, 0x00, 0x00, 0xF0, 0x3E, 0x00, 0x08, 0x41, 0x00, 0x08, 0x41, 0x00, 0x08, 0x41, 0x00, 0x08, 0x41, 0x00, 0x08, 0x41, 0x00, 0xF0, 0x3E, 0x00, 
	/* 9 */ 0x08, 0x00, 0x00, 0x00, 0xF0, 0x01, 0x00, 0x08, 0x42, 0x00, 0x08, 0x42, 0x00, 0x08, 0x42, 0x00, 0x08, 0x42, 0x00, 0x08, 0x22, 0x00, 0xF0, 0x1F, 0x00, 
	/* : */ 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x30, 0x00, 
	/* ; */ 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0xC0, 0x70, 0x00, 
	/* < */ 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x80, 0x04, 0x00, 0x40, 0x08, 0x00, 0x20, 0x10, 0x00, 0x10, 0x20, 0x00, 0x08, 0x40, 0x00, 
	/* = */ 0x08, 0x00, 0x00, 0x00, 0x40, 0x04, 0x00, 0x40, 0x04, 0x00, 0x40, 0x04, 0x00, 0x40, 0x04, 0x00, 0x40, 0x04, 0x00, 0x40, 0x04, 0x00, 0x40, 0x04, 0x00, 
	/* > */ 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x40, 0x00, 0x10, 0x20, 0x00, 0x20, 0x10, 0x00, 0x40, 0x08, 0x00, 0x80, 0x04, 0x00, 0x00, 0x03, 0x00, 
	/* ? */ 0x08, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x10, 0x00, 0x00, 0x08, 0x00, 0x00, 0x08, 0x6C, 0x00, 0x08, 0x02, 0x00, 0x10, 0x01, 0x00, 0xE0, 0x00, 0x00, 
	/* @ */ 0x09, 0x00, 0x00, 0x00, 0xF0, 0x3F, 0x00, 0x08, 0x40, 0x00, 0x08, 0x40, 0x00, 0x88, 0x47, 0x00, 0x48, 0x48, 0x00, 0x48, 0x48, 0x00, 0x48, 0x44, 0x00, 0xF0, 0x4F, 0x00, 
	/* A */ 0x08, 0x00, 0x00, 0x00, 0xF0, 0x7F, 0x00, 0x08, 0x02, 0x00, 0x08, 0x02, 0x00, 0x08, 0x02, 0x00, 0x08, 0x02, 0x00, 0x08, 0x02, 0x00, 0xF0, 0x7F, 0x00, 
	/* B */ 0x08, 0x00, 0x00, 0x00, 0xF8, 0x7F, 0x00, 0x08, 0x41, 0x00, 0x08, 0x41, 0x00, 0x08, 0x41, 0x00, 0x08, 0x41, 0x00, 0x08, 0x41, 0x00, 0xF0, 0x3E, 0x00, 
	/* C */ 0x08, 0x00, 0x00, 0x00, 0xF0, 0x3F, 0x00, 0x08, 0x40, 0x00, 0x08, 0x40, 0x00, 0x08, 0x40, 0x00, 0x08, 0x40, 0x00, 0x08, 0x40, 0x00, 0x30, 0x30, 0x00, 
	/* D */ 0x08, 0x00, 0x00, 0x00, 0xF8, 0x7F, 0x00, 0x08, 0x40, 0x00, 0x08, 0x40, 0x00, 0x08, 0x40, 0x00, 0x08, 0x40, 0x00, 0x10, 0x20, 0x00, 0xE0, 0x1F, 0x00, 
	/* E */ 0x08, 0x00, 0x00, 0x00, 0xF8, 0x7F, 0x00, 0x08, 0x41, 0x00, 0x08, 0x41, 0x00, 0x08, 0x41, 0x00, 0x08, 0x41, 0x00, 0x08, 0x40, 0x00, 0x08, 0x40, 0x00, 
	/* F */ 0x08, 0x00, 0x00, 0x00, 0xF8, 0x7F, 0x00, 0x08, 0x01, 0x00, 0x08, 0x01, 0x00, 0x08, 0x01, 0x00, 0x08, 0x01, 0x00, 0x08, 0x00, 0x00, 0x08, 0x00, 0x00, 
	/* G */ 0x08, 0x00, 0x00, 0x00, 0xF0, 0x3F, 0x00, 0x08, 0x40, 0x00, 0x08, 0x40, 0x00, 0x08, 0x42, 0x00, 0x08, 0x42, 0x00, 0x08, 0x42, 0x00, 0x30, 0x3E, 0x00, 
	/* H */ 0x08, 0x00, 0x00, 0x00, 0xF8, 0x7F, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0xF8, 0x7F, 0x00, 
	/* I */ 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x40, 0x00, 0xF8, 0x7F, 0x00, 0x08, 0x40, 0x00, 
	/* J */ 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x08, 0x40, 0x00, 0xF8, 0x3F, 0x00, 0x08, 0x00, 0x00, 
	/* K */ 0x08, 0x00, 0x00, 0x00, 0xF8, 0x7F, 0x00, 0x00, 0x03, 0x00, 0x80, 0x04, 0x00, 0x40, 0x08, 0x00, 0x20, 0x10, 0x00, 0x10, 0x20, 0x00, 0x08, 0x40, 0x00, 
	/* L */ 0x08, 0x00, 0x00, 0x00, 0xF8, 0x7F, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 
	/* M */ 0x09, 0x00, 0x00, 0x00, 0xF8, 0x7F, 0x00, 0x10, 0x00, 0x00, 0x60, 0x00, 0x00, 0x80, 0x01, 0x00, 0x80, 0x01, 0x00, 0x60, 0x00, 0x00, 0x10, 0x00, 0x00, 0xF8, 0x7F, 0x00, 
	/* N */ 0x08, 0x00, 0x00, 0x00, 0xF8, 0x7F, 0x00, 0x40, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x02, 0x00, 0x00, 0x04, 0x00, 0xF8, 0x7F, 0x00, 
	/* O */ 0x08, 0x00, 0x00, 0x00, 0xF0, 0x3F, 0x00, 0x08, 0x40, 0x00, 0x08, 0x40, 0x00, 0x08, 0x40, 0x00, 0x08, 0x40, 0x00, 0x08, 0x40, 0x00, 0xF0, 0x3F, 0x00, 
	/* P */ 0x08, 0x00, 0x00, 0x00, 0xF8, 0x7F, 0x00, 0x08, 0x02, 0x00, 0x08, 0x02, 0x00, 0x08, 0x02, 0x00, 0x08, 0x02, 0x00, 0x08, 0x02, 0x00, 0xF0, 0x01, 0x00, 
	/* Q */ 0x08, 0x00, 0x00, 0x00, 0xF0, 0x3F, 0x00, 0x08, 0x40, 0x00, 0x08, 0x40, 0x00, 0x08, 0x60, 0x00, 0x08, 0x40, 0x00, 0x08, 0xC0, 0x00, 0xF0, 0x3F, 0x01, 
	/* R */ 0x08, 0x00, 0x00, 0x00, 0xF8, 0x7F, 0x00, 0x08, 0x02, 0x00, 0x08, 0x06, 0x00, 0x08, 0x0A, 0x00, 0x08, 0x12, 0x00, 0x08, 0x22, 0x00, 0xF0, 0x41, 0x00, 
	/* S */ 0x08, 0x00, 0x00, 0x00, 0xF0, 0x30, 0x00, 0x08, 0x41, 0x00, 0x08, 0x41, 0x00, 0x08, 0x41, 0x00, 0x08, 0x41, 0x00, 0x08, 0x41, 0x00, 0x30, 0x3E, 0x00, 
	/* T */ 0x08, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x08, 0x00, 0x00, 0x08, 0x00, 0x00, 0xF8, 0x7F, 0x00, 0x08, 0x00, 0x00, 0x08, 0x00, 0x00, 0x08, 0x00, 0x00, 
	/* U */ 0x08, 0x00, 0x00, 0x00, 0xF8, 0x3F, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0xF8, 0x3F, 0x00, 
	/* V */ 0x08, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00, 0x80, 0x03, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x60, 0x00, 0x00, 0x1C, 0x00, 0x80, 0x03, 0x00, 0x78, 0x00, 0x00, 
	/* W */ 0x09, 0x00, 0x00, 0x00, 0xF8, 0x7F, 0x00, 0x00, 0x20, 0x00, 0x00, 0x18, 0x00, 0x00, 0x06, 0x00, 0x00, 0x06, 0x00, 0x00, 0x18, 0x00, 0x00, 0x20, 0x00, 0xF8, 0x7F, 0x00, 
	/* X */ 0x08, 0x00, 0x00, 0x00, 0x18, 0x60, 0x00, 0x60, 0x18, 0x00, 0x80, 0x04, 0x00, 0x00, 0x03, 0x00, 0x80, 0x04, 0x00, 0x60, 0x18, 0x00, 0x18, 0x60, 0x00, 
	/* Y */ 0x08, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x60, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x7E, 0x00, 0x80, 0x01, 0x00, 0x60, 0x00, 0x00, 0x18, 0x00, 0x00, 
	/* Z */ 0x08, 0x00, 0x00, 0x00, 0x08, 0x78, 0x00, 0x08, 0x44, 0x00, 0x08, 0x42, 0x00, 0x08, 0x41, 0x00, 0x88, 0x40, 0x00, 0x48, 0x40, 0x00, 0x38, 0x40, 0x00, 
	/* [ */ 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x7F, 0x00, 0x08, 0x40, 0x00, 0x08, 0x40, 0x00, 
	/* \ */ 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x60, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x06, 0x00, 0x00, 0x18, 0x00, 0x00, 0x60, 0x00, 
	/* ] */ 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x40, 0x00, 0x08, 0x40, 0x00, 0xF8, 0x7F, 0x00, 
	/* ^ */ 0x08, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x08, 0x00, 0x00, 0x04, 0x00, 0x00, 0x02, 0x00, 0x00, 0x04, 0x00, 0x00, 0x08, 0x00, 0x00, 0x10, 0x00, 0x00, 
	/* _ */ 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 
	/* ` */ 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x02, 0x00, 0x00, 
	/* a */ 0x08, 0x00, 0x00, 0x00, 0x00, 0x3C, 0x00, 0x40, 0x42, 0x00, 0x40, 0x42, 0x00, 0x40, 0x42, 0x00, 0x40, 0x42, 0x00, 0x40, 0x42, 0x00, 0x80, 0x7F, 0x00, 
	/* b */ 0x08, 0x00, 0x00, 0x00, 0xF8, 0x7F, 0x00, 0x40, 0x40, 0x00, 0x40, 0x40, 0x00, 0x40, 0x40, 0x00, 0x40, 0x40, 0x00, 0x40, 0x40, 0x00, 0x80, 0x3F, 0x00, 
	/* c */ 0x08, 0x00, 0x00, 0x00, 0x80, 0x3F, 0x00, 0x40, 0x40, 0x00, 0x40, 0x40, 0x00, 0x40, 0x40, 0x00, 0x40, 0x40, 0x00, 0x40, 0x40, 0x00, 0x80, 0x20, 0x00, 
	/* d */ 0x08, 0x00, 0x00, 0x00, 0x80, 0x3F, 0x00, 0x40, 0x40, 0x00, 0x40, 0x40, 0x00, 0x40, 0x40, 0x00, 0x40, 0x40, 0x00, 0x40, 0x40, 0x00, 0xF8, 0x7F, 0x00, 
	/* e */ 0x08, 0x00, 0x00, 0x00, 0x80, 0x3F, 0x00, 0x40, 0x44, 0x00, 0x40, 0x44, 0x00, 0x40, 0x44, 0x00, 0x40, 0x44, 0x00, 0x40, 0x44, 0x00, 0x80, 0x27, 0x00, 
	/* f */ 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0xF0, 0x7F, 0x00, 0x48, 0x00, 0x00, 0x48, 0x00, 0x00, 0x08, 0x00, 0x00, 
	/* g */ 0x08, 0x00, 0x00, 0x00, 0x80, 0x3F, 0x00, 0x40, 0x40, 0x02, 0x40, 0x40, 0x02, 0x40, 0x40, 0x02, 0x40, 0x40, 0x02, 0x40, 0x40, 0x02, 0xC0, 0xFF, 0x01, 
	/* h */ 0x08, 0x00, 0x00, 0x00, 0xF8, 0x7F, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x80, 0x7F, 0x00, 
	/* i */ 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x40, 0x00, 0xD8, 0x7F, 0x00, 0x00, 0x40, 0x00, 
	/* j */ 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x02, 0x00, 0x00, 0x02, 0x40, 0x00, 0x02, 0xD8, 0xFF, 0x01, 
	/* k */ 0x08, 0x00, 0x00, 0x00, 0xF8, 0x7F, 0x00, 0x00, 0x04, 0x00, 0x00, 0x04, 0x00, 0x00, 0x0A, 0x00, 0x00, 0x11, 0x00, 0x80, 0x20, 0x00, 0x40, 0x40, 0x00, 
	/* l */ 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x40, 0x00, 0xF8, 0x7F, 0x00, 0x00, 0x40, 0x00, 
	/* m */ 0x08, 0x00, 0x00, 0x00, 0xC0, 0x7F, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0xC0, 0x7F, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x80, 0x7F, 0x00, 
	/* n */ 0x08, 0x00, 0x00, 0x00, 0xC0, 0x7F, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x80, 0x7F, 0x00, 
	/* o */ 0x08, 0x00, 0x00, 0x00, 0x80, 0x3F, 0x00, 0x40, 0x40, 0x00, 0x40, 0x40, 0x00, 0x40, 0x40, 0x00, 0x40, 0x40, 0x00, 0x40, 0x40, 0x00, 0x80, 0x3F, 0x00, 
	/* p */ 0x08, 0x00, 0x00, 0x00, 0xC0, 0xFF, 0x03, 0x40, 0x40, 0x00, 0x40, 0x40, 0x00, 0x40, 0x40, 0x00, 0x40, 0x40, 0x00, 0x40, 0x40, 0x00, 0x80, 0x3F, 0x00, 
	/* q */ 0x08, 0x00, 0x00, 0x00, 0x80, 0x3F, 0x00, 0x40, 0x40, 0x00, 0x40, 0x40, 0x00, 0x40, 0x40, 0x00, 0x40, 0x40, 0x00, 0x40, 0x40, 0x00, 0xC0, 0xFF, 0x03, 
	/* r */ 0x08, 0x00, 0x00, 0x00, 0xC0, 0x7F, 0x00, 0x00, 0x01, 0x00, 0x80, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 
	/* s */ 0x08, 0x00, 0x00, 0x00, 0x80, 0x23, 0x00, 0x40, 0x44, 0x00, 0x40, 0x44, 0x00, 0x40, 0x44, 0x00, 0x40, 0x44, 0x00, 0x40, 0x44, 0x00, 0x80, 0x38, 0x00, 
	/* t */ 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0xF8, 0x3F, 0x00, 0x40, 0x40, 0x00, 0x40, 0x40, 0x00, 0x00, 0x40, 0x00, 
	/* u */ 0x08, 0x00, 0x00, 0x00, 0xC0, 0x3F, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0xC0, 0x7F, 0x00, 
	/* v */ 0x08, 0x00, 0x00, 0x00, 0xC0, 0x01, 0x00, 0x00, 0x06, 0x00, 0x00, 0x18, 0x00, 0x00, 0x60, 0x00, 0x00, 0x18, 0x00, 0x00, 0x06, 0x00, 0xC0, 0x01, 0x00, 
	/* w */ 0x08, 0x00, 0x00, 0x00, 0xC0, 0x3F, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x7E, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0xC0, 0x3F, 0x00, 
	/* x */ 0x08, 0x00, 0x00, 0x00, 0xC0, 0x60, 0x00, 0x00, 0x11, 0x00, 0x00, 0x0A, 0x00, 0x00, 0x04, 0x00, 0x00, 0x0A, 0x00, 0x00, 0x11, 0x00, 0xC0, 0x60, 0x00, 
	/* y */ 0x08, 0x00, 0x00, 0x00, 0xC0, 0x3F, 0x00, 0x00, 0x40, 0x02, 0x00, 0x40, 0x02, 0x00, 0x40, 0x02, 0x00, 0x40, 0x02, 0x00, 0x40, 0x02, 0xC0, 0xFF, 0x01, 
	/* z */ 0x08, 0x00, 0x00, 0x00, 0x40, 0x60, 0x00, 0x40, 0x50, 0x00, 0x40, 0x48, 0x00, 0x40, 0x44, 0x00, 0x40, 0x42, 0x00, 0x40, 0x41, 0x00, 0xC0, 0x40, 0x00, 
	/* { */ 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0xF0, 0x3E, 0x00, 0x08, 0x40, 0x00, 0x08, 0x40, 0x00, 
	/* | */ 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x7F, 0x00, 
	/* } */ 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x40, 0x00, 0x08, 0x40, 0x00, 0xF0, 0x3E, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 
	/* ~ */ 0x08, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x02, 0x00, 0x00, 0x02, 0x00, 0x00, 0x0C, 0x00, 0x00, 0x10, 0x00, 0x00, 0x10, 0x00, 0x00, 0x0E, 0x00, 0x00, 
	/*  */ 0x09, 0x00, 0x7E, 0x00, 0x00, 0x41, 0x00, 0x80, 0x40, 0x00, 0x40, 0x40, 0x00, 0x20, 0x40, 0x00, 0x40, 0x40, 0x00, 0x80, 0x40, 0x00, 0x00, 0x41, 0x00, 0x00, 0x7E, 0x00, 
};

const GLCD_FontDef Font_Terminus_9x18 = {
    Terminus9x18_Data,
    9,
    18,
    24,
    ' ',
    '\x7F',
    true,
	false
};
