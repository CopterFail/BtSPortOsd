


#ifndef __CHARSET_H__
#define __CHARSET_H__

// charset: multiosdfont.mcm
#define CHAR_GPS_FIX    0   // 3 chars
#define CHAR_SAT        16  // 2 chars
#define CHAR_HOME       18
#define CHAR_KMH        129
#define CHAR_MAN        130
#define CHAR_LAT        131
#define CHAR_LON        132
#define CHAR_ALT        133
#define CHAR_VEL        134
#define CHAR_THR        135
#define CHAR_AIR        136
#define CHAR_ARROW      144 // 15 * 2 chars (90deg / 4 )
#define CHAR_DEG        176
#define CHAR_UPDOWN     177
#define CHAR_CLOCK      179
#define CHAR_FUNKE      180
#define CHAR_LEFTRIGHT  181  
#define CHAR_BATT       244 // 6 chars emptry -> full
#define CHAR_FLASH      250
#define CHAR_BULB       251


void uploadFont( void );
void showFont( void );


#endif
