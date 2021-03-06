#include <avr/pgmspace.h>
#include "../ssd1306.h"
#include "../glcd_font.h"

//WARNING: This Font Require X-GLCD Lib.
//         You can not use it with MikroE GLCD Lib.

//Font Generated by MikroElektronika GLCD Font Creator 1.2.0.0
//MikroElektronika 2011 
//http://www.mikroe.com 

//GLCD FontName : Droid_Sans_Fallback9x11
//GLCD FontSize : 9 x 11
PROGMEM static const uint8_t Droid_Sans_Fallback_9x11_Data[ ] = {
	/*   */ 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	/* ! */ 0x03, 0x00, 0x00, 0x00, 0x00, 0x7E, 0x01, 
	/* " */ 0x05, 0x00, 0x00, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x0E, 0x00, 
	/* # */ 0x07, 0x00, 0x00, 0x48, 0x00, 0xFE, 0x01, 0x48, 0x00, 0x48, 0x00, 0xFE, 0x01, 0x48, 0x00, 
	/* $ */ 0x06, 0x00, 0x00, 0x8C, 0x00, 0x12, 0x01, 0xFF, 0x03, 0x22, 0x01, 0xC4, 0x00, 
	/* % */ 0x09, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x12, 0x01, 0xCC, 0x00, 0x30, 0x00, 0xCC, 0x00, 0x22, 0x01, 0xC0, 0x00, 
	/* & */ 0x07, 0x00, 0x00, 0x00, 0x00, 0xEC, 0x00, 0x12, 0x01, 0x32, 0x01, 0xCC, 0x00, 0x20, 0x01, 
	/* ' */ 0x02, 0x00, 0x00, 0x0E, 0x00, 
	/* ( */ 0x04, 0x00, 0x00, 0x00, 0x00, 0xFC, 0x03, 0x02, 0x04, 
	/* ) */ 0x03, 0x00, 0x00, 0x02, 0x04, 0xFC, 0x03, 
	/* * */ 0x04, 0x00, 0x00, 0x0A, 0x00, 0x04, 0x00, 0x0A, 0x00, 
	/* + */ 0x06, 0x00, 0x00, 0x20, 0x00, 0x20, 0x00, 0xF8, 0x00, 0x20, 0x00, 0x20, 0x00, 
	/* , */ 0x03, 0x00, 0x00, 0x00, 0x02, 0x00, 0x01, 
	/* - */ 0x04, 0x00, 0x00, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 
	/* . */ 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 
	/* / */ 0x04, 0x00, 0x00, 0x80, 0x01, 0x78, 0x00, 0x06, 0x00, 
	/* 0 */ 0x06, 0x00, 0x00, 0xFC, 0x00, 0x02, 0x01, 0x02, 0x01, 0x02, 0x01, 0xFC, 0x00, 
	/* 1 */ 0x05, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x04, 0x00, 0xFE, 0x01, 
	/* 2 */ 0x06, 0x00, 0x00, 0x04, 0x01, 0x82, 0x01, 0x42, 0x01, 0x22, 0x01, 0x1C, 0x01, 
	/* 3 */ 0x06, 0x00, 0x00, 0x84, 0x00, 0x02, 0x01, 0x12, 0x01, 0x12, 0x01, 0xEC, 0x00, 
	/* 4 */ 0x06, 0x00, 0x00, 0x60, 0x00, 0x50, 0x00, 0x4C, 0x00, 0xFE, 0x01, 0x40, 0x00, 
	/* 5 */ 0x06, 0x00, 0x00, 0x9E, 0x00, 0x12, 0x01, 0x12, 0x01, 0x12, 0x01, 0xE2, 0x00, 
	/* 6 */ 0x06, 0x00, 0x00, 0xFC, 0x00, 0x12, 0x01, 0x12, 0x01, 0x12, 0x01, 0xE4, 0x00, 
	/* 7 */ 0x06, 0x00, 0x00, 0x02, 0x00, 0x02, 0x01, 0xE2, 0x00, 0x1A, 0x00, 0x06, 0x00, 
	/* 8 */ 0x06, 0x00, 0x00, 0xEC, 0x00, 0x12, 0x01, 0x12, 0x01, 0x12, 0x01, 0xEC, 0x00, 
	/* 9 */ 0x06, 0x00, 0x00, 0x9C, 0x00, 0x22, 0x01, 0x22, 0x01, 0x22, 0x01, 0xFC, 0x00, 
	/* : */ 0x03, 0x00, 0x00, 0x00, 0x00, 0x10, 0x01, 
	/* ; */ 0x03, 0x00, 0x00, 0x00, 0x02, 0x10, 0x01, 
	/* < */ 0x06, 0x00, 0x00, 0x20, 0x00, 0x50, 0x00, 0x50, 0x00, 0x88, 0x00, 0x88, 0x00, 
	/* = */ 0x06, 0x00, 0x00, 0x50, 0x00, 0x50, 0x00, 0x50, 0x00, 0x50, 0x00, 0x50, 0x00, 
	/* > */ 0x06, 0x00, 0x00, 0x88, 0x00, 0x88, 0x00, 0x50, 0x00, 0x50, 0x00, 0x20, 0x00, 
	/* ? */ 0x06, 0x00, 0x00, 0x04, 0x00, 0x02, 0x00, 0x62, 0x01, 0x12, 0x00, 0x0C, 0x00, 
	/* @ */ 0x09, 0x38, 0x00, 0x70, 0x00, 0x8C, 0x01, 0x34, 0x01, 0x4A, 0x02, 0x4A, 0x02, 0x7A, 0x02, 0x42, 0x02, 0x44, 0x00, 
	/* A */ 0x08, 0x00, 0x00, 0x80, 0x01, 0x60, 0x00, 0x58, 0x00, 0x46, 0x00, 0x58, 0x00, 0x60, 0x00, 0x80, 0x01, 
	/* B */ 0x07, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x01, 0x12, 0x01, 0x12, 0x01, 0x12, 0x01, 0xEC, 0x00, 
	/* C */ 0x07, 0x00, 0x00, 0x00, 0x00, 0xFC, 0x00, 0x02, 0x01, 0x02, 0x01, 0x02, 0x01, 0x84, 0x00, 
	/* D */ 0x08, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x01, 0x02, 0x01, 0x02, 0x01, 0x02, 0x01, 0x84, 0x00, 0x78, 0x00, 
	/* E */ 0x07, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x01, 0x12, 0x01, 0x12, 0x01, 0x12, 0x01, 0x02, 0x01, 
	/* F */ 0x06, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x01, 0x12, 0x00, 0x12, 0x00, 0x12, 0x00, 
	/* G */ 0x08, 0x00, 0x00, 0x00, 0x00, 0xFC, 0x00, 0x02, 0x01, 0x02, 0x01, 0x22, 0x01, 0x22, 0x01, 0xE4, 0x01, 
	/* H */ 0x07, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x01, 0x10, 0x00, 0x10, 0x00, 0x10, 0x00, 0xFE, 0x01, 
	/* I */ 0x03, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x01, 
	/* J */ 0x05, 0x00, 0x00, 0x80, 0x00, 0x00, 0x01, 0x00, 0x01, 0xFE, 0x00, 
	/* K */ 0x08, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x01, 0x10, 0x00, 0x28, 0x00, 0x44, 0x00, 0x82, 0x00, 0x00, 0x01, 
	/* L */ 0x07, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 
	/* M */ 0x09, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x01, 0x08, 0x00, 0x30, 0x00, 0xC0, 0x00, 0x30, 0x00, 0x08, 0x00, 0xFE, 0x01, 
	/* N */ 0x07, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x01, 0x0C, 0x00, 0x30, 0x00, 0xC0, 0x00, 0xFE, 0x01, 
	/* O */ 0x08, 0x00, 0x00, 0x00, 0x00, 0xFC, 0x00, 0x02, 0x01, 0x02, 0x01, 0x02, 0x01, 0x02, 0x01, 0xFC, 0x00, 
	/* P */ 0x08, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x01, 0x22, 0x00, 0x22, 0x00, 0x22, 0x00, 0x22, 0x00, 0x1C, 0x00, 
	/* Q */ 0x08, 0x00, 0x00, 0x00, 0x00, 0xFC, 0x00, 0x02, 0x01, 0x02, 0x01, 0x42, 0x01, 0x82, 0x01, 0xFC, 0x02, 
	/* R */ 0x07, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x01, 0x22, 0x00, 0x22, 0x00, 0x62, 0x00, 0x9C, 0x01, 
	/* S */ 0x07, 0x00, 0x00, 0x00, 0x00, 0x8C, 0x00, 0x12, 0x01, 0x12, 0x01, 0x22, 0x01, 0xC4, 0x00, 
	/* T */ 0x06, 0x00, 0x00, 0x02, 0x00, 0x02, 0x00, 0xFE, 0x01, 0x02, 0x00, 0x02, 0x00, 
	/* U */ 0x07, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0xFE, 0x00, 
	/* V */ 0x08, 0x00, 0x00, 0x06, 0x00, 0x18, 0x00, 0x60, 0x00, 0x80, 0x01, 0x60, 0x00, 0x18, 0x00, 0x06, 0x00, 
	/* W */ 0x09, 0x06, 0x00, 0x06, 0x00, 0x38, 0x00, 0xC0, 0x01, 0x38, 0x00, 0x06, 0x00, 0x38, 0x00, 0xC0, 0x01, 0x38, 0x00, 
	/* X */ 0x08, 0x00, 0x00, 0x02, 0x01, 0x84, 0x00, 0x48, 0x00, 0x30, 0x00, 0x48, 0x00, 0x84, 0x00, 0x02, 0x01, 
	/* Y */ 0x08, 0x00, 0x00, 0x06, 0x00, 0x08, 0x00, 0x10, 0x00, 0xE0, 0x01, 0x10, 0x00, 0x08, 0x00, 0x06, 0x00, 
	/* Z */ 0x06, 0x00, 0x00, 0x00, 0x00, 0x82, 0x01, 0x62, 0x01, 0x1A, 0x01, 0x06, 0x01, 
	/* [ */ 0x04, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x07, 0x02, 0x04, 
	/* \ */ 0x04, 0x00, 0x00, 0x06, 0x00, 0x78, 0x00, 0x80, 0x01, 
	/* ] */ 0x03, 0x00, 0x00, 0x02, 0x04, 0xFE, 0x07, 
	/* ^ */ 0x06, 0x00, 0x00, 0x08, 0x00, 0x04, 0x00, 0x02, 0x00, 0x04, 0x00, 0x08, 0x00, 
	/* _ */ 0x07, 0x00, 0x00, 0x00, 0x04, 0x00, 0x04, 0x00, 0x04, 0x00, 0x04, 0x00, 0x04, 0x00, 0x04, 
	/* ` */ 0x03, 0x00, 0x00, 0x02, 0x00, 0x04, 0x00, 
	/* a */ 0x06, 0x00, 0x00, 0x80, 0x00, 0x50, 0x01, 0x50, 0x01, 0x50, 0x01, 0xE0, 0x01, 
	/* b */ 0x06, 0x00, 0x00, 0xFE, 0x01, 0x10, 0x01, 0x10, 0x01, 0x10, 0x01, 0xE0, 0x00, 
	/* c */ 0x05, 0x00, 0x00, 0xE0, 0x00, 0x10, 0x01, 0x10, 0x01, 0xA0, 0x00, 
	/* d */ 0x06, 0x00, 0x00, 0xE0, 0x00, 0x10, 0x01, 0x10, 0x01, 0x10, 0x01, 0xFE, 0x01, 
	/* e */ 0x06, 0x00, 0x00, 0xE0, 0x00, 0x50, 0x01, 0x50, 0x01, 0x50, 0x01, 0x60, 0x01, 
	/* f */ 0x03, 0x00, 0x00, 0xFC, 0x01, 0x12, 0x00, 
	/* g */ 0x06, 0x00, 0x00, 0xE0, 0x04, 0x10, 0x05, 0x10, 0x05, 0x10, 0x05, 0xF0, 0x03, 
	/* h */ 0x06, 0x00, 0x00, 0xFE, 0x01, 0x20, 0x00, 0x10, 0x00, 0x10, 0x00, 0xE0, 0x01, 
	/* i */ 0x02, 0x00, 0x00, 0xF2, 0x01, 
	/* j */ 0x02, 0x00, 0x00, 0xF2, 0x03, 
	/* k */ 0x05, 0x00, 0x00, 0xFE, 0x01, 0x40, 0x00, 0xA0, 0x00, 0x10, 0x01, 
	/* l */ 0x02, 0x00, 0x00, 0xFE, 0x01, 
	/* m */ 0x08, 0x00, 0x00, 0xF0, 0x01, 0x10, 0x00, 0x10, 0x00, 0xF0, 0x01, 0x10, 0x00, 0x10, 0x00, 0xE0, 0x01, 
	/* n */ 0x06, 0x00, 0x00, 0xF0, 0x01, 0x20, 0x00, 0x10, 0x00, 0x10, 0x00, 0xE0, 0x01, 
	/* o */ 0x06, 0x00, 0x00, 0xE0, 0x00, 0x10, 0x01, 0x10, 0x01, 0x10, 0x01, 0xE0, 0x00, 
	/* p */ 0x06, 0x00, 0x00, 0xF0, 0x07, 0x10, 0x01, 0x10, 0x01, 0x10, 0x01, 0xE0, 0x00, 
	/* q */ 0x06, 0x00, 0x00, 0xE0, 0x00, 0x10, 0x01, 0x10, 0x01, 0x10, 0x01, 0xF0, 0x07, 
	/* r */ 0x03, 0x00, 0x00, 0xF0, 0x01, 0x10, 0x00, 
	/* s */ 0x05, 0x00, 0x00, 0x20, 0x01, 0x50, 0x01, 0x50, 0x01, 0x90, 0x00, 
	/* t */ 0x03, 0x00, 0x00, 0xF8, 0x01, 0x10, 0x01, 
	/* u */ 0x06, 0x00, 0x00, 0xF0, 0x00, 0x00, 0x01, 0x00, 0x01, 0x80, 0x00, 0xF0, 0x01, 
	/* v */ 0x06, 0x00, 0x00, 0x30, 0x00, 0xC0, 0x00, 0x00, 0x01, 0xC0, 0x00, 0x30, 0x00, 
	/* w */ 0x08, 0x00, 0x00, 0x70, 0x00, 0x80, 0x01, 0x40, 0x00, 0x30, 0x00, 0x40, 0x00, 0x80, 0x01, 0x70, 0x00, 
	/* x */ 0x05, 0x00, 0x00, 0xB0, 0x01, 0x40, 0x00, 0x40, 0x00, 0xB0, 0x01, 
	/* y */ 0x05, 0x00, 0x00, 0x70, 0x04, 0x80, 0x03, 0x80, 0x00, 0x70, 0x00, 
	/* z */ 0x05, 0x00, 0x00, 0x90, 0x01, 0x50, 0x01, 0x50, 0x01, 0x30, 0x01, 
	/* { */ 0x04, 0x00, 0x00, 0x20, 0x00, 0xDC, 0x03, 0x02, 0x04, 
	/* | */ 0x03, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x03, 
	/* } */ 0x04, 0x00, 0x00, 0x02, 0x04, 0xDC, 0x03, 0x20, 0x00, 
	/* ~ */ 0x06, 0x00, 0x00, 0x04, 0x00, 0x02, 0x00, 0x06, 0x00, 0x04, 0x00, 0x02, 0x00, 
	/*  */ 0x04, 0x00, 0x00, 0xFE, 0x01, 0x02, 0x01, 0xFE, 0x01, 
};

static const int Droid_Sans_Fallback_9x11_OldSize = 1824;
static const int Droid_Sans_Fallback_9x11_Size = 1178;

const GLCD_FontDef Font_Droid_Sans_Fallback_9x11 = {
	Droid_Sans_Fallback_9x11_Data,
	9,
	11,
	16,
	'\x20',
	'\x7F',
	true,
	false
};
