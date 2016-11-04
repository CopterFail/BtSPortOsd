

#ifndef __TELDATA_H__
#define __TELDATA_H__


class TelData
{
    uint32_t u32Counter;
    
public:
    float   fUavLat;
    float   fUavLon;
    uint8_t  u8UavSatCnt;
    uint8_t  u8UavFixType;
    int16_t  i16UavGpsAlt;
    int16_t  i16UavBaroAlt;
    uint16_t u16UavGpsSpeed;
    uint16_t u16UavGpsCourse;
    int16_t  i16UavVario;
    uint16_t u16UavBatt2;
    uint8_t  u8UavRssi;
    uint8_t  u8UavSWR;
    uint8_t  u8UavRxBatt;
    uint8_t u8UavAdc1;
    uint8_t u8UavAdc2;
    float   fHomeLat;
    float   fHomeLon;
    uint8_t u8HomeFix;
    uint16_t u16Modes;

    float   fHomeDirection;
    float   fHomeDistance;
    
    
public:
    TelData();
    
    uint32_t u32Count( void ){
        return u32Counter;
        }
        
    void vReadSPORT( int b );
    void vUpdateGpsModel( void );
    
private:
    uint8_t u8CheckCrcSPORT( void );
    uint8_t u8DecodeSPORT( void );
    
};


#endif
