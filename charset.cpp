


#include "Arduino.h"
#include "ArduCam_Max7456.h"
#include "charset.h"
#include "osd.h"

extern OSD osd; 

void uploadFont( void )
{ 
    uint16_t byte_count = 0;
    byte bit_count=0;
    byte ascii_binary[0x08];

    // move these local to prevent ram usage
    uint8_t character_bitmap[0x40];
    int font_count = 0;
    Serial.begin(19200);  
    osd.clear();
    osd_print(1,2,"Waiting for new Font...");     

    Serial.print(F("\nPlease send *.mcm file.\n"));            

    while(font_count < 255) { 
        int8_t incomingByte = Serial.read();
        switch(incomingByte) // parse and decode mcm file
        {
        case 0x0d: // carridge return, end of line
            //Serial.println("cr");
            if (bit_count == 8 && (ascii_binary[0] == 0x30 || ascii_binary[0] == 0x31))
            {
                // turn 8 ascii binary bytes to single byte '01010101' = 0x55
                // fill in 64 bytes of character data
                // made this local to prevent needing a global
                byte ascii_byte;

                ascii_byte = 0;

                if (ascii_binary[0] == 0x31) // ascii '1'
                    ascii_byte = ascii_byte + 128;

                if (ascii_binary[1] == 0x31)
                    ascii_byte = ascii_byte + 64;

                if (ascii_binary[2] == 0x31)
                    ascii_byte = ascii_byte + 32;

                if (ascii_binary[3] == 0x31)
                    ascii_byte = ascii_byte + 16;

                if (ascii_binary[4] == 0x31)
                    ascii_byte = ascii_byte + 8;

                if (ascii_binary[5] == 0x31)
                    ascii_byte = ascii_byte + 4;

                if (ascii_binary[6] == 0x31)
                    ascii_byte = ascii_byte + 2;

                if (ascii_binary[7] == 0x31)
                    ascii_byte = ascii_byte + 1;

                character_bitmap[byte_count] = ascii_byte;
                byte_count++;
                bit_count = 0;
            }
            else
                bit_count = 0;
            break;
        case 0x0a: // line feed, ignore
            //Serial.println("ln");   
            break;
        case 0x30: // ascii '0'
        case 0x31: // ascii '1' 
            ascii_binary[bit_count] = incomingByte;
            bit_count++;
            break;
        default:
            break;
        }

        // we have one completed character
        // write the character to NVM 
        if(byte_count == 64)
        {
            osd.write_NVM(font_count, character_bitmap);    
            byte_count = 0;
            font_count++;
            Serial.print(font_count, DEC);
            Serial.println(" chars done");            
        }
    }
    Serial.print(F("Font update done. Restart system manual\n\n"));      

    //delay(2000);
    //asm volatile ("  jmp 0");  // softstart by jumping to start vector   
    // REBOOT, WILL NEVER GET HERE

}

void showFont( void )
{
  uint8_t x=2, y=2, c=0;

  for( c=0; c<255; c++ ){
    osd_print_char ( x++, y, c );
    if( x > 28 ){
      x = 2;
      y++;
    }
  }


}


