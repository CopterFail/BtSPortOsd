

#ifndef __DEFINITIONS_H__
#define __DEFINITIONS_H__

#define CELL_MIN  3.5f
#define CELL_MAX  4.3f

// Screen settings (use smaller NTSC size)
#define SCREEN_X_MAX  30
#define SCREEN_Y_MAX  16  // NTSC 13


#define OSD_EXT_SYC 1
#define OSD_INT_SYC 2
#define OSD_OFF     0
// most screens do "Overscan" so offset may be required.
#define OSD_H_OFFSET 40 // adjust to your screen (0...63, 31 = center)
#define OSD_V_OFFSET 25 // adjust to your screen (0...31, 15 = center)

#define OSD_UPDATE_INTERVALL 300U

#define TELEMETRY_SPEED  57600  // Serial speed 
#define TIMEGAP 3000 // time in us between telegrams

// Set you TV format (PAL = Europe = 50Hz, NTSC = INT = 60Hz)
//#define TV_FORMAT NTSC
#define TV_FORMAT PAL

#define LON_FACTOR 71.5f  
#define LAT_FACTOR 111.3f  

#define RAD_TO_DEG  57.295779513f
#define DEG_TO_RAD  0.017453293f

#endif
