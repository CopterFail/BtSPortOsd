

#ifndef __OSD_H__
#define __OSD_H__

void osd_print (uint8_t x, uint8_t y, const char string[30]);
void osd_print_char (uint8_t x, uint8_t y, const char value);
void vPrintBattery( uint8_t x, uint8_t y, float u );
void vPrintArrow( uint8_t x, uint8_t y, float d );

#endif
