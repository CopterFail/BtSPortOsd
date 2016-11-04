




/* ************************************************************ */
/* **************** MAIN PROGRAM - MODULES ******************** */
/* ************************************************************ */



// AVR Includes
#include <avr/pgmspace.h>  // Needed for PROGMEM stuff

/* **********************************************/
/* ***************** INCLUDES *******************/

#include "Arduino.h"

//#define membug 
#ifdef membug
#include <MemoryFree.h>
#endif

#include "ArduCam_Max7456.h"
#include <EEPROM.h>
#include "Spi.h"

#include "teldata.h"
#include "debug.h"
#include "charset.h"
#include "osd.h"
#include "definitions.h"

/* *************************************************/
/* ***************** DEFINITIONS *******************/

//OSD Hardware 
#define MinimOSD


#define EEPROM_ADR_MAGIC_KEY 8
#define EEPROM_MAGIC_KEY_SIZE 16
const uint8_t MagicKey[] = { // key to check if EEprom matches software
  'O','S','D','-','T','E','R','M',
  'R','E','V','1','.','0','.','0'
};


// Objects and Serial definitions
OSD osd; //OSD object 

uint8_t debug=1;

TelData teldata;


/**********************************************/
/*                   SETUP()                  */
/**********************************************/
void setup() 
{

   // use values only of EEprom is not 255 = unsaved
   // check if eeprom is matching current software
   // the check is done by comparing magic key in eeprom
   uint8_t eeprom_invalid=0;

   for(int i=0; i<EEPROM_MAGIC_KEY_SIZE; i++)
   {
        if((uint8_t)EEPROM.read(EEPROM_ADR_MAGIC_KEY+i) != (uint8_t)pgm_read_word_near(MagicKey + i))
        {
            eeprom_invalid=1;
            break;
        }        
   }
    if(eeprom_invalid) // EEprom does not match current software, must store new defaults
    {
        // store magic key for next check
        for(int i=0; i<EEPROM_MAGIC_KEY_SIZE; i++)
        {
            EEPROM.write(EEPROM_ADR_MAGIC_KEY+i,pgm_read_word_near(MagicKey + i));
        }         
    }

    // debug reset EEPROM
    //EEPROM.write(EEPROM_ADR_MAGIC_KEY,255);    
        
    // read last setting from eeprom

//    video_mode=EEPROM.read(EEPROM_ADR_VIDEO_MODE);

#if TV_FORMAT == PAL
    osd.setMode(1); //pal
#else
    osd.setMode(0); 
#endif

    osd.init();
    osd.set_h_offset(OSD_H_OFFSET);
    osd.set_v_offset(OSD_V_OFFSET);

    // simple start screen
    screen_startup();
    // show message if EEPROM need reinit
    if(eeprom_invalid)
    {
       osd_print(3,12,"INVALID EEPROM CLEARED");
    }
    
    Serial.begin(TELEMETRY_SPEED);  
    delay(1000);
    osd.clear();

//uploadFont();
    showFont();
    delay(2000);
//while(1);
    osd.clear();

    analogReference(INTERNAL);

    
} // END of setup();


/************************************************/
/*                 MAIN LOOP                    */
/************************************************/

void loop() 
{
  static uint32_t u32LastUpdate = 0U;
  vGetTelemetrieData();
  if( (millis()- u32LastUpdate) > OSD_UPDATE_INTERVALL ){
    vUpdateOsd();
    u32LastUpdate = millis(); 
  }  
}


void vGetTelemetrieData( void )
{
  while( Serial.available() )
    teldata.vReadSPORT( Serial.read() );
}


extern uint8_t telbuffer[20];
extern uint8_t u8telcnt;
void vUpdateOsd( void )
{
    static char buffer[30];
    static float uground=7.4;
    static uint8_t u8BtLive=0;
    static uint32_t u32LastCount = 0;
    
    teldata.vUpdateGpsModel();
    uground = 0.9 * uground + 0.1 * (float)(analogRead( 2 )) / 59.0f;

    // Battery data:
    osd_print_char( 2, 2, 'B');
    vPrintBattery(  3, 2, uground );
    osd_print_char( 4, 2, 'M');
    //vPrintBattery(  5, 2, (float)teldata.u16UavBatt2 * 0.01 );
    sprintf( buffer, " %02d.%02d ", teldata.u16UavBatt2 / 100 ,teldata.u16UavBatt2 % 100 );
    osd_print(5,2,buffer);    
    
    //osd_print_char( 6, 2, 'T');
    //vPrintBattery(  7, 2, transmitter battery ? );

    // GPS data:
    if( teldata.u8UavSatCnt >= 4 ){
      sprintf( buffer, "D%04d ", (uint32_t)teldata.fHomeDistance );
      osd_print(24,2,buffer);    
      vPrintArrow( 14, 12, teldata.fHomeDirection );
    }
    sprintf( buffer, "H%03d ", teldata.i16UavBaroAlt );
    osd_print(24,3,buffer);    

    // Signal data:
    sprintf( buffer, "%c%02d ", CHAR_FUNKE, teldata.u8UavRssi );
    osd_print(24,4,buffer);    
    sprintf( buffer, "%c%c%02d ", CHAR_SAT, CHAR_SAT+1, teldata.u8UavSatCnt );
    osd_print(24,5,buffer);    
    
    // Statistic & debug:  
    if( ( teldata.u32Count() - u32LastCount ) > 300 ){
         u32LastCount = teldata.u32Count();
         u8BtLive = 1 - u8BtLive;
    }
    osd_print_char( 2, 15, u8BtLive ? 'x' : '+');
    
    /*
    sprintf( buffer, "S.Port Telegrams: %d ", teldata.u32Count() );
    osd_print(2,7,buffer);    
    osd_print(2,8+(u8telcnt&7),telbuffer);    
    */

    //alternative: dtostrf
    //dtostrf(uground, 3, 2, buffer );


}


///////////////////////////////////////
//  SCREENS
///////////////////////////////////////
/*******************/
/*  START SCREEN   */
/*******************/

void screen_startup(void)
{
    uint8_t y=5;
    uint8_t x=3;
    osd.clear();
    osd_print(x,y++,"  Bluetooth S.Port OSD  ");    
    osd_print(x,y++,"2016-06-29 by CopterFail");    
    osd_print(x,y++,"      V1.0.0            ");    
}


