


#include "Arduino.h"
#include "ArduCam_Max7456.h"
#include "osd.h"
#include "charset.h"
#include "definitions.h"

extern OSD osd; 

void osd_print (uint8_t x, uint8_t y, const char string[30])
{
    osd.setPanel(x-1,y-1);  
    osd.openPanel();
    osd.outs(string); 
    osd.closePanel(); 
}

void osd_print_char (uint8_t x, uint8_t y, const char value)
{
    osd.setPanel(x-1,y-1);  
    osd.openPanel();
    osd.outchar(value); 
    osd.closePanel(); 
}

void vPrintBattery( uint8_t x, uint8_t y, float u )
{
    uint8_t cellcount = (uint8_t)(u / CELL_MAX) + 1;
    char c = CHAR_BATT;
    if( cellcount > 0 ){
        u /= cellcount;
        u -= CELL_MIN;
        u *= 6.0 / ( CELL_MAX - CELL_MIN );
        
        if( u < 0.0 ) u = 0.0;
        if( u > 5.0 ) u = 5.0;
        u += 0.9;
        c += (uint8_t)u;
        osd_print_char ( x, y, c );
        }
    else{
      osd_print_char ( x, y, 'X' );
    }
}

void vPrintArrow( uint8_t x, uint8_t y, float d )
{
    uint8_t u8val;
    uint8_t au8buffer[3];
    if( d < 0.0 ) d += 360;
    d *= 0.044444444; //8.0 / 180.0;
    u8val = 2 * (uint8_t)d;
    u8val += CHAR_ARROW;
    au8buffer[0] = u8val;
    au8buffer[1] = u8val+1;
    au8buffer[2] = 0U;
    osd_print ( x, y, (const char *)au8buffer );
}

