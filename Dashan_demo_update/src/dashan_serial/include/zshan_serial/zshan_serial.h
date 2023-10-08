/************************************************************
 * Copyright (C): 
 * FileName:    zshan_serial.h
 * Author:      chengwei
 * Date:        2015/10/21
 * Version:
 * Description:
 * History:
 *    <author>     <time>           <version>            <desc>
 *    chengwei    2015/10/21          A001         create this file
 **************************************************************/

#ifndef ZSHAN_SERIAL_H
#define ZSHAN_SERIAL_H

#define SEND_PACK_START_FLAG 0xaa
#define SEND_PACK_START_INDEX 0x55
#define RECV_PACK_START_FLAG 0x55
#define RECV_PACK_START_FLAG_RT 0xa1

#define RECV_PACK_START_FLAG_NRT 0xa2

#define BUF_MAX_LEN 256

#define COMM_STAT_WAIT 2
#define COMM_STAT_ERR 1
#define COMM_STAT_OK  0
#define OBSTACLE_AVOIDANCE 30 
/*From PC to DSP,package to send*/
typedef struct Zshan_Send_Pack
{
    unsigned char start_flag;
    unsigned char index;
    short vx;//bug here Endianness
    short vz;
    unsigned char cLedHelth;
    unsigned char cLedstatus;
    unsigned char cPushRodPos;
    char reserved[3];
    unsigned char check_code;
}Zshan_Send_Pack;

/*from DSP to PC, package to receive*/
#define RT_RECV_PACK_LEN 15    /*real time recv package length*/
#define NRT_RECV_PACK_LEN 13    /*not real time recv package length*/
#define RT_AND_NRT_PKG_LEN 28
typedef struct Zshan_RecvPack_RealTime
{
    unsigned char start_flag;
    unsigned char index;
    short l_wheel_vel;
    short r_wheel_vel;
    short lAngleZ;
    short sAngSpeedZ;
    unsigned char cSonarFL;//front left
    unsigned char cSonarFR;
    unsigned char cSonarLR;//left rear
    unsigned char cSonarRR;
    unsigned char check_code;
}Zshan_RecvPack_RealTime;
typedef struct Zshan_RecvPack_NRT
{
    unsigned char start_flag;
    unsigned char index;
    unsigned char battery_left;
    unsigned char cPushRodPos;
    char cTemp;
    unsigned char cHumidity;
    unsigned char cSmoke;
    unsigned char cChargeState;
    unsigned char cButtonState;
    char reserved[3];
    unsigned char check_code;
}Zshan_RecvPack_NRT;

#endif

