
#ifndef __SPORT_H__
#define __SPORT_H__

// Frsky-specific
#define START_STOP                  0x7e
#define DATA_FRAME                  0x10


//Frsky DATA ID's 
#define FR_ID_ALTITUDE              0x0100  //ALT_FIRST_ID
#define FR_ID_VARIO                 0x0110  //VARIO_FIRST_ID
#define FR_ID_VFAS                  0x0210  //VFAS_FIRST_ID
#define FR_ID_CURRENT               0x0200  //CURR_FIRST_ID
#define FR_ID_CELLS                 0x0300  //CELLS_FIRST_ID
#define FR_ID_CELLS_LAST            0x030F  //CELLS_LAST_ID
#define FR_ID_T1                    0x0400  //T1_FIRST_ID
#define FR_ID_T2                    0x0410  //T2_FIRST_ID
#define FR_ID_RPM                   0x0500  //RPM_FIRST_ID
#define FR_ID_FUEL                  0x0600  //FUEL_FIRST_ID
#define FR_ID_ACCX                  0x0700  //ACCX_FIRST_ID
#define FR_ID_ACCY                  0x0710  //ACCY_FIRST_ID
#define FR_ID_ACCZ                  0x0720  //ACCZ_FIRST_ID
#define FR_ID_LATLONG               0x0800  //GPS_LONG_LATI_FIRST_ID
#define FR_ID_GPS_ALT               0x0820  //GPS_ALT_FIRST_ID
#define FR_ID_SPEED                 0x0830  //GPS_SPEED_FIRST_ID
#define FR_ID_GPS_COURSE            0x0840  //GPS_COURS_FIRST_ID
#define FR_ID_GPS_TIME_DATE         0x0850  //GPS_TIME_DATE_FIRST_ID
#define FR_ID_GPS_SAT               0x0860  //GPS satellite count and fix state (own definition)
#define FR_ID_A3_FIRST              0x0900  //A3_FIRST_ID
#define FR_ID_A4_FIRST              0x0910  //A4_FIRST_ID
#define FR_ID_AIR_SPEED_FIRST       0x0A00  //AIR_SPEED_FIRST_ID
#define FR_ID_RSSI                  0xF101  // used by the radio system
#define FR_ID_ADC1                  0xF102  //ADC1_ID
#define FR_ID_ADC2                  0xF103  //ADC2_ID
#define FR_ID_RXBATT                0xF104  // used by the radio system
#define FR_ID_SWR                   0xF105  // used by the radio system
#define FR_ID_FIRMWARE              0xF106  // used by the radio system


/*
// FrSky new DATA IDs (2 bytes), copied from opentx project
#define ALT_FIRST_ID              0x0100
#define ALT_LAST_ID               0x010f
#define VARIO_FIRST_ID            0x0110
#define VARIO_LAST_ID             0x011f
#define CURR_FIRST_ID             0x0200
#define CURR_LAST_ID              0x020f
#define VFAS_FIRST_ID             0x0210
#define VFAS_LAST_ID              0x021f
#define CELLS_FIRST_ID            0x0300
#define CELLS_LAST_ID             0x030f
#define T1_FIRST_ID               0x0400
#define T1_LAST_ID                0x040f
#define T2_FIRST_ID               0x0410
#define T2_LAST_ID                0x041f
#define RPM_FIRST_ID              0x0500
#define RPM_LAST_ID               0x050f
#define FUEL_FIRST_ID             0x0600
#define FUEL_LAST_ID              0x060f
#define ACCX_FIRST_ID             0x0700
#define ACCX_LAST_ID              0x070f
#define ACCY_FIRST_ID             0x0710
#define ACCY_LAST_ID              0x071f
#define ACCZ_FIRST_ID             0x0720
#define ACCZ_LAST_ID              0x072f
#define GPS_LONG_LATI_FIRST_ID    0x0800
#define GPS_LONG_LATI_LAST_ID     0x080f
#define GPS_ALT_FIRST_ID          0x0820
#define GPS_ALT_LAST_ID           0x082f
#define GPS_SPEED_FIRST_ID        0x0830
#define GPS_SPEED_LAST_ID         0x083f
#define GPS_COURS_FIRST_ID        0x0840
#define GPS_COURS_LAST_ID         0x084f
#define GPS_TIME_DATE_FIRST_ID    0x0850
#define GPS_TIME_DATE_LAST_ID     0x085f
#define A3_FIRST_ID               0x0900
#define A3_LAST_ID                0x090f
#define A4_FIRST_ID               0x0910
#define A4_LAST_ID                0x091f
#define AIR_SPEED_FIRST_ID        0x0a00
#define AIR_SPEED_LAST_ID         0x0a0f
#define POWERBOX_BATT1_FIRST_ID   0x0b00
#define POWERBOX_BATT1_LAST_ID    0x0b0f
#define POWERBOX_BATT2_FIRST_ID   0x0b10
#define POWERBOX_BATT2_LAST_ID    0x0b1f
#define POWERBOX_STATE_FIRST_ID   0x0b20
#define POWERBOX_STATE_LAST_ID    0x0b2f
#define POWERBOX_CNSP_FIRST_ID    0x0b30
#define POWERBOX_CNSP_LAST_ID     0x0b3f
#define RSSI_ID                   0xf101
#define ADC1_ID                   0xf102
#define ADC2_ID                   0xf103
#define SP2UART_A_ID              0xfd00
#define SP2UART_B_ID              0xfd01
#define BATT_ID                   0xf104
#define SWR_ID                    0xf105
#define XJT_VERSION_ID            0xf106
#define FUEL_QTY_FIRST_ID         0x0a10
#define FUEL_QTY_LAST_ID          0x0a1f
*/

#pragma pack(push, 1)
typedef struct {
    int16_t id;
    union{ uint32_t u32; int32_t i32; uint16_t u16; int16_t i16; uint8_t u8; int8_t i8; float f; } data;
    uint8_t crc;
    } tSPortData;
#pragma pack(pop)
 
#endif
