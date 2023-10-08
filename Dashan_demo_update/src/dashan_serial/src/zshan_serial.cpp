/*******************************************************************************
* Copyright (C): 
* Filename: Zshan_serial.cpp
* Author: chengwei 
* Date:   2015/10/18  
* Version: A001
* Description : zshan_serial node. raspberryPi serial port send and receive.
               
* History:  <author>     <date>            <version>      <description>
*           chengwei    2015/10/18          A001         create this file
            cuijie      2016/04/04         A002          change this file
			cuijie      2016/05/14         A002          change this file
*******************************************************************************/

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <sensor_msgs/LaserScan.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <pthread.h>
#include <sys/types.h>  
#include <sys/stat.h>   
#include <fcntl.h>      
#include <termios.h>    
#include <errno.h>      
#include <dashan_msg/zhishancmd.h>
#include "dashan_msg/wheelSpeed.h"
#include "dashan_msg/imudata.h"
#include "dashan_msg/diagnosis.h"
#include "dashan_msg/hmiStatus.h"
#include "../include/zshan_serial/zshan_serial.h"
#define PI 3.1415926535
static int fd ;	                            /*file description of tty device*/
static Zshan_RecvPack_RealTime stParseRTPkg;
static Zshan_RecvPack_RealTime stParseRTPkgLastTime;
static Zshan_RecvPack_NRT stParseNRTPkg;
static int s_serial_comm_stat = 0;          /*serial commmunication state. 0:ok 1:error*/
static geometry_msgs::Twist s_vel; 
static int cmd_vel_timeout = 0;

static ros::Publisher s_pubZhishancmd;
static dashan_msg::zhishancmd s_msgZhishancmd;
static dashan_msg::hmiStatus msghmiStatus;

static char c_DiagState = 0;
static int testcountRECV = 0;
static int testcountSEND = 0;
static int s_rod_control = 0;
static int SonarWarnningLeft = 0;
static int SonarWarnningRight = 0;
static bool g_bIsLogOpen = true;
static bool g_bAutoChargeFlag = false;
static bool g_bManualStopCharge = false;

pthread_mutex_t mutex; 
/**
time printf
**/
void print_time_serial_TEST(int test)
{
    struct timeval tv;
    struct tm* ptm;
    char time_str[128];
    long milliseconds;
    gettimeofday(&tv, NULL);
    ptm = localtime(&tv.tv_sec);
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", ptm);
    milliseconds = tv.tv_sec / 1000;
    printf("[serial][recv]%s.%03ld[%s]\n", time_str, milliseconds,test);
}
void print_time_serial_RECV()
{
    struct timeval tv;
    struct tm* ptm;
    char time_str[128];
    long milliseconds;
    gettimeofday(&tv, NULL);
    ptm = localtime(&tv.tv_sec);
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", ptm);
    milliseconds = tv.tv_sec / 1000;
	testcountRECV++;
    printf("[serial][recv]%s.%03ld[%d]\n", time_str, milliseconds,testcountRECV);
}
void print_time_serial_SEND()
{
    struct timeval tv;
    struct tm* ptm;
    char time_str[128];
    long milliseconds;
    gettimeofday(&tv, NULL);
    ptm = localtime(&tv.tv_sec);
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", ptm);
    milliseconds = tv.tv_sec / 1000;
	testcountSEND++;
    printf("[serial][send]%s.%03ld[%d]\n", time_str, milliseconds,testcountSEND);
}
/**
*@brief  set serial databits, stopbits, parity
*@param  fd     serial device file description
*@param  nBits value should be 7 or 8
*@param  nStop value should be 1 or 2
*@param  nEvent  value should be N,E,O,,S
*/
int SetSerialPort(int fd,int nSpeed,int nBits, char nEvent, int nStop)
{ 
    struct termios newtio,oldtio;
    if  ( tcgetattr( fd,&oldtio)  !=  0) {
        perror("SetupSerial 1");
        return -1;
    }
    bzero( &newtio, sizeof( newtio ) );
    newtio.c_cflag  |=  CLOCAL | CREAD;
    newtio.c_cflag &= ~CSIZE;
    switch( nBits )
    {
    case 7:
        newtio.c_cflag |= CS7;
        break;
    case 8:
        newtio.c_cflag |= CS8;
        break;
    }
    switch( nEvent )
    {
    case 'O': //
        newtio.c_cflag |= PARENB;
        newtio.c_cflag |= PARODD;
        newtio.c_iflag |= (INPCK | ISTRIP);
        break;
    case 'E': //
        newtio.c_iflag |= (INPCK | ISTRIP);
        newtio.c_cflag |= PARENB;
        newtio.c_cflag &= ~PARODD;
        break;
    case 'N':  //
        newtio.c_cflag &= ~PARENB;
        break;
    }
    switch( nSpeed )
    {
    case 2400:
        cfsetispeed(&newtio, B2400);
        cfsetospeed(&newtio, B2400);
        break;
    case 4800:
        cfsetispeed(&newtio, B4800);
        cfsetospeed(&newtio, B4800);
        break;
    case 9600:
        cfsetispeed(&newtio, B9600);
        cfsetospeed(&newtio, B9600);
        break;
    case 19200:
        cfsetispeed(&newtio, B19200);
        cfsetospeed(&newtio, B19200);
        break;
    case 115200:
        cfsetispeed(&newtio, B115200);
        cfsetospeed(&newtio, B115200);
        break;
    case 460800:
        cfsetispeed(&newtio, B460800);
        cfsetospeed(&newtio, B460800);
        break;
    default:
        cfsetispeed(&newtio, B9600);
        cfsetospeed(&newtio, B9600);
        break;
    }
    if( nStop == 1 )
        newtio.c_cflag &=  ~CSTOPB;
    else if ( nStop == 2 )
        newtio.c_cflag |=  CSTOPB;
    newtio.c_cc[VTIME]  = 0;
    newtio.c_cc[VMIN] = 0;
    tcflush(fd,TCIFLUSH);
    if((tcsetattr(fd,TCSANOW,&newtio))!=0)
    {
        perror("com set error");
        return -1;
    }
    //printf("set done!\n");

    return 0;
}

/*******************************************************************************
 * Function: CalcCheckCode
 * Identifier:  (Trace to: )
 * Description: check the check sum code in the Zshan_Send_Pack
 *
 * Input:  pPack
 * Output: pPack
 * Return: void
 * Others: 
 * Log: 2015/10/21 chengwei create.
 * Log: 20156/04/28 Peter changed.
 *******************************************************************************/
void CalcCheckCode(Zshan_Send_Pack *pPack)
{
	char *ptmp = (char *)pPack;
	unsigned char sum = 0;

	while(ptmp != (char *)&(pPack->check_code))
	{
		sum += *ptmp;
		ptmp++;
	}
	pPack->check_code = sum ;
}

/*******************************************************************************
 * Function: serialPutData
 * Identifier:  (Trace to: )
 * Description: send len of bytes to serial port
 *
 * Input:  pbuf:data to send     len:bytes num to send
 * Output: none
 * Return: void
 * Others: 
 * Log: 2015/10/21 chengwei create.
 *******************************************************************************/
void serialPutData(char *pbuf, int len)
{
	char *ptmp = pbuf;
	if ((NULL == pbuf) || (0 == len))
	{
		return;
	}
	
	for (int i = 0; i < len; i++)
	{
		//serialPutchar(fd, *ptmp);
		////printf("%x ", *ptmp);
		write(fd, ptmp, 1);
		ptmp++;
	}
	return;
}

/*******************************************************************************
 * Function: SendData
 * Identifier:  (Trace to: )
 * Description: send pack data to serial port
 *
 * Input:  pack
 * Output: none
 * Return: void
 * Others: 
 * Log: 2015/10/21 chengwei create.
 *******************************************************************************/
static void SendData(Zshan_Send_Pack *pack)
{
	//printf("\n");
	std::cout << "vx:" << pack->vx << ", vz:" << pack->vz << "  SEND" << std::endl;
	
	serialPutData ((char *)&pack->start_flag, 1);
	serialPutData ((char *)&pack->index, 1);
	serialPutData ((char *)&pack->vx, 2);
	serialPutData ((char *)&pack->vz, 2);
	serialPutData ((char *)&pack->cLedHelth, 1);
	serialPutData ((char *)&pack->cLedstatus, 1);
	serialPutData ((char *)&pack->cPushRodPos, 1);
	serialPutData ((char *)pack->reserved, 3);
	serialPutData ((char *)&pack->check_code, 1);
}
/*******************************************************************************
 * Function: tread
 * Identifier:  (Trace to: )
 * Description: received nbytes data to buf, return if receive succeed or timout  
 *
 * Input:  fd: serial device   buf: recv buffer   nbytes:num of bytes desired to recv     timout:recv timeout value 
 * Output: buf:recv buffer
 * Return: number of bytes we received
 * Others: only receive one time
 * Log: 2015/10/21 chengwei create.
 *******************************************************************************/
ssize_t tread(int fd, void *buf, size_t nbytes, unsigned int timout)
{
    int   nfds;
    fd_set  readfds;
    struct timeval  tv;

    tv.tv_sec = 0;
    tv.tv_usec = timout;

    FD_ZERO(&readfds);
    FD_SET(fd, &readfds);

    nfds = select(fd+1, &readfds, NULL, NULL, &tv);

    if (nfds <= 0) 
    {
        if (nfds == 0)
        {
            errno = ETIME;
        }
        return(-1);
    }

    return(read(fd, buf, nbytes));

}

/*******************************************************************************
 * Function: treadn
 * Identifier:  (Trace to: )
 * Description: continuiosly received nbytes data to buf until receive nbytes or timout  
 *
 * Input:  fd: serial device   buf: recv buffer   nbytes:num of bytes desired to recv     timout:recv timeout value 
 * Output: buf:recv buffer
 * Return: number of bytes we received
 * Others: 
 * Log: 2015/10/21 chengwei create.
 *******************************************************************************/
ssize_t treadn(int fd, void *buf, size_t nbytes, unsigned int timout)
{
    size_t      nleft;
    ssize_t     nread;

    nleft = nbytes;
    while (nleft > 0)
    {
        if ((nread = tread(fd, buf, nleft, timout)) < 0) 
        {
             if (nleft == nbytes)
             {
                return(-1); /* error, return -1 */
             }
             else
             {
                break;      /* error, return amount read so far */
             }
        } else if (nread == 0) 
        {
             break;          /* EOF */
        }

        nleft -= nread;
        buf += nread;
    }

    return(nbytes - nleft);      /* return >= 0 */
}


/*******************************************************************************
 * Function: SerialRecvTask
 * Identifier:  (Trace to: )
 * Description: a independent thread to receive serial port data
 *
 * Input:  
 * Output: none
 * Return: void
 * Others: 
 * Log: 2015/10/21 chengwei create.
 *******************************************************************************/
void *SerialRecvTask(void *arg)
{
	unsigned char sum = 0;
	int count = 0;
	char buff[BUF_MAX_LEN] = {0};
	int iIndex = 0;
	int i = 0;
	bool bIsValidPkg = false;
    int err_count = 0;
	int no_data_count = 0;
    int mutexReturn = 0;
	while(1)
	{
		/*recv until timeout or recv BUF_MAX_LEN data*/
		memset(buff,0x00,BUF_MAX_LEN);
		count = 0;
		iIndex =0;
		mutexReturn = 0;
		count = treadn(fd, buff, BUF_MAX_LEN, 10000); //10000 usec (10ms) character interval. we define the frame interval is 100ms and the character interval in a frame	should be less than 5ms at 115200bps

		if (count <= 0 || count > BUF_MAX_LEN)
		{
			no_data_count++;
			if (50 < no_data_count)	/*long time no data come, we assume the serial comm is error*/
			{
				s_serial_comm_stat = COMM_STAT_ERR; /*set serial comm state to error*/
                ROS_ERROR("set serial comm state to error!\n");
			}
			s_serial_comm_stat = COMM_STAT_WAIT; 
			continue;
		}
		no_data_count = 0;
		for(i = 0;i < count;i++)
		{
			if((RECV_PACK_START_FLAG == (unsigned char)buff[i]) 
				&& (RECV_PACK_START_FLAG_RT == (unsigned char)buff[i+1])
			    && (RT_RECV_PACK_LEN <= (count - i)))
			{
				iIndex = i;
				bIsValidPkg = true;
				break;
			}
			else if((RECV_PACK_START_FLAG == (unsigned char)buff[i]) 
				&& (RECV_PACK_START_FLAG_NRT == (unsigned char)buff[i+1])
			    && (NRT_RECV_PACK_LEN <= (count - i)))
			{
				iIndex = i;
				bIsValidPkg = true;
				break;
			}
			else
			{
				iIndex = 0;
				bIsValidPkg = false;
			}
		}
 
	    if(true == bIsValidPkg)
		{
			mutexReturn = pthread_mutex_lock(&mutex);/*lock the mutex*/  
			if(0 != mutexReturn)
			{
				
			}
			if(RECV_PACK_START_FLAG_RT == (unsigned char)buff[iIndex+1])
			{//real time package
		
				sum = 0;
				
				stParseRTPkg.start_flag = buff[iIndex];
				stParseRTPkg.index = buff[iIndex+1];
				memcpy(&stParseRTPkg.l_wheel_vel, &buff[iIndex+2], 2);
				memcpy(&stParseRTPkg.r_wheel_vel, &buff[iIndex+4], 2);
				memcpy(&stParseRTPkg.lAngleZ, &buff[iIndex+6], 2);
				memcpy(&stParseRTPkg.sAngSpeedZ, &buff[iIndex+8], 2);
				stParseRTPkg.cSonarFL = buff[iIndex+10];//front left
				stParseRTPkg.cSonarFR = buff[iIndex+11];
				stParseRTPkg.cSonarLR = buff[iIndex+12];//left rear
				stParseRTPkg.cSonarRR = buff[iIndex+13];
				stParseRTPkg.check_code = buff[iIndex+14];
				/*check the check code*/
				for (i = iIndex; i < iIndex + RT_RECV_PACK_LEN - 1; i++) /*calc from start_flag to reserved exclude check code*/
				{
					sum += buff[i];
				}
				if (sum != stParseRTPkg.check_code)
				{
					//memset(&stParseRTPkg, 0x00, sizeof(Zshan_RecvPack_RealTime));
					stParseRTPkg = stParseRTPkgLastTime;
					ROS_INFO_COND_NAMED(true == g_bIsLogOpen, "zhishanlog", "[SERIAL][RTPKG_SUM_wrong] = %d\n", sum);
				}
				else
				{
					stParseRTPkgLastTime = stParseRTPkg;
					s_serial_comm_stat = COMM_STAT_OK;
				}
			}
			else if((RECV_PACK_START_FLAG_NRT  == (unsigned char)buff[iIndex+1]))
			{//none real time package
				sum = 0;
				stParseNRTPkg.start_flag = buff[iIndex];
				stParseNRTPkg.index = buff[iIndex+1];
				stParseNRTPkg.battery_left = buff[iIndex+2];
				stParseNRTPkg.cPushRodPos= buff[iIndex+3];
				stParseNRTPkg.cTemp = buff[iIndex+4];
				stParseNRTPkg.cHumidity = buff[iIndex+5];
				stParseNRTPkg.cSmoke = buff[iIndex+6];
				stParseNRTPkg.cChargeState = buff[iIndex+7];
				stParseNRTPkg.cButtonState= buff[iIndex+8];
				memcpy(stParseNRTPkg.reserved, &buff[iIndex+9], 3); 
				stParseNRTPkg.check_code = buff[iIndex+12];

				/*check the check code*/
				for (i = iIndex; i < iIndex + NRT_RECV_PACK_LEN - 1; i++) /*calc from start_flag to reserved exclude check code*/
				{
					sum += buff[i];
				}
				/*check start flag*/
				if (sum != stParseNRTPkg.check_code)
				{
					memset(&stParseNRTPkg, 0x00, sizeof(Zshan_RecvPack_NRT));
					ROS_INFO_COND_NAMED(true == g_bIsLogOpen, "zhishanlog", "[SERIAL][NRTPKG_SUM_wrong] = %d\n", sum);
				}
				else
				{

					if(0x01 == stParseNRTPkg.cChargeState)//zheng zai chong dian dongzuo
					{
						ROS_INFO_COND_NAMED(true == g_bIsLogOpen, "zhishanlog", "[SERIAL][zhengzaichongdiandongzuo] = %d\n", 1);
						g_bAutoChargeFlag = false;
					}
					else if(0x02 == stParseNRTPkg.cChargeState)//xun zhao chong dian zhuang shi bai
					{
							ROS_INFO_COND_NAMED(true == g_bIsLogOpen, "zhishanlog", "[SERIAL][xunzhaochongdianzhuangshibai] = %d\n", 2);			
					}
					else if(0x03 == stParseNRTPkg.cChargeState)//chong dian wan cheng
					{
						ROS_INFO_COND_NAMED(true == g_bIsLogOpen, "zhishanlog", "[SERIAL][chongdianwancheng] = %d\n", 3);
						g_bManualStopCharge = false;
					}
					else if(0x04 == stParseNRTPkg.cChargeState)//zhengzaichongdian zhuangtai
					{
						ROS_INFO_COND_NAMED(true == g_bIsLogOpen, "zhishanlog", "[SERIAL][zhengzaichongdianzhuangtai] = %d\n", 4);
						g_bAutoChargeFlag = false;	
					}	
				}
			}
			else
			{
					err_count++;
					if (3 == err_count)
					{
						//ROS_INFO("real time package set serial comm state to error!\n");
						err_count = 0;
						s_serial_comm_stat = COMM_STAT_ERR; /*set serial comm state to error*/
						ROS_WARN("RT_err_COMM_STAT_ERR!\n");
					}
					else
					{
						ROS_WARN("RT_COMM_STAT_WAIT!\n");
						s_serial_comm_stat = COMM_STAT_WAIT; /*set serial comm state to error*/
					}
				ROS_INFO_COND_NAMED(true == g_bIsLogOpen, "zhishanlog", "%x%x%x%x%x%x%x%x", (unsigned char)buff[0],(unsigned char)buff[1],(unsigned char)buff[2],(unsigned char)buff[3],(unsigned char)buff[4],(unsigned char)buff[5]);
				ROS_INFO_COND_NAMED(true == g_bIsLogOpen, "zhishanlog", "%x%x%x%x%x%x%x%x", (unsigned char)buff[6],(unsigned char)buff[7],(unsigned char)buff[8],(unsigned char)buff[9],(unsigned char)buff[10],(unsigned char)buff[11]);
				ROS_INFO_COND_NAMED(true == g_bIsLogOpen, "zhishanlog", "%x%x%x%x%x%x%x%x", (unsigned char)buff[12],(unsigned char)buff[13],(unsigned char)buff[14],(unsigned char)buff[15],(unsigned char)buff[16],(unsigned char)buff[17]);
				ROS_INFO_COND_NAMED(true == g_bIsLogOpen, "zhishanlog", "[SERIAL][PKG_TYPE_LENTH_WRONG] len= %d\n", count);
				//s_serial_comm_stat = COMM_STAT_WAIT; /*set serial comm state to error*/
			}
			pthread_mutex_unlock(&mutex);/*unlock the mutex*/  
		}
	}
}

/*******************************************************************************
 * Function: cmd_velCallback
 * Identifier:  (Trace to: )
 * Description: call back function when ros twist msg received
 *
 * Input:  geometry_msgs::Twist
 * Output: none
 * Return: void
 * Others: 
 * Log: 2015/10/21 chengwei create.
 *******************************************************************************/
void cmd_velCallback(const geometry_msgs::Twist::ConstPtr& vel)
{
	s_vel.linear.x = vel->linear.x;	
	s_vel.linear.y = vel->linear.y;    
	s_vel.angular.z = vel->angular.z;	

    cmd_vel_timeout = 0;
    std::cout << "vx:" << s_vel.linear.x << ", vz:" << s_vel.angular.z << "  CMD_VEL" << std::endl;
    //ROS_INFO("sub cmd_cel");
}
/*******************************************************************************
 * Function: zhishancmd
 * Identifier:  (Trace to: )
 * Description: call back func for btn message
 *              
 * Input:  dashan_msg::zhishancmd
 * Output: None
 * Return: None
 * Others: 
 * Log: 2016/08/02 cuijie create.
 *******************************************************************************/
static void zhishancmdCallback(const dashan_msg::zhishancmd :: ConstPtr &msg)
{
	if(0 < msg->rodControl && 9 > msg->rodControl)
	{
		s_rod_control = msg->rodControl;
		ROS_INFO_COND_NAMED(true == g_bIsLogOpen, "zhishanlog", "[SERIAl][dance] = %d\n", s_rod_control);
	}
	if(3 == msg->autoCharge)
	{  
        g_bAutoChargeFlag = true;
		ROS_INFO_COND_NAMED(true == g_bIsLogOpen, "zhishanlog", "[SERIAl][start auto charge by android] = %d\n", 3);
	}
	else if(2 == msg->autoCharge)//android send stop charge command
	{
		g_bManualStopCharge = true;
		ROS_INFO_COND_NAMED(true == g_bIsLogOpen, "zhishanlog", "[SERIAl][stop auto charge by android] = %d\n", 2);	
	}
	else
	{
		
	}
}

void dashan_diagCallback(const dashan_msg::diagnosis :: ConstPtr &msg)
{
	c_DiagState = msg->State;
	if(4 == c_DiagState)
	{//#define GREEN_BLINK 4 in diagnosis
		SonarWarnningLeft = 0;
        SonarWarnningRight = 0;
		ROS_INFO_COND_NAMED(true == g_bIsLogOpen, "zhishanlog", "[SERIAl][SonarWarnning] = %d\n", c_DiagState);	
	}
	//ROS_INFO("I heard: [%d]", msg->buttonState);
	//ROS_INFO("I heard2: [%d]", msg->rpcNodeInfo);
}
void dashan_r2000_scan_Callback(const sensor_msgs::LaserScan :: ConstPtr &msg)
{
   msghmiStatus.pos_x = (msg->ranges[449] + msg->ranges[550] + msg->ranges[551])/3;
   msghmiStatus.pos_y = (msg->ranges[649] + msg->ranges[650] + msg->ranges[651])/3;
}

/*******************************************************************************
 * Function: main
 * Identifier:  (Trace to: )
 * Description: zshan serial node main function
 *
 * Input:  
 * Output: none
 * Return: void
 * Others: 
 * Log: 2015/10/21 chengwei create.
 *******************************************************************************/
int main(int argc, char** argv)
{
    int count = 0;
	int sendChargeStopCmd = 0;
    Zshan_Send_Pack send_pack = {0};
    pthread_t tid;		/*serial port receive task thread id*/
    int err;
    void *res;
    dashan_msg::wheelSpeed wheel_speed_msg;    /*node message, defined in dashan_msg\msg*/
    dashan_msg::imudata imu_msg;
    //ROS_INFO("Zshan_serial node loaded!\n");
    ros::init(argc, argv, "Zshan_serial");
    ros::NodeHandle nh;

    /*ROS subscriber /turtle1/cmd_vel */
    //ros::Subscriber cmd_vel_sub = nh.subscribe("/turtlebot_teleop/cmd_vel", 1000, cmd_velCallback); 
    //ros::Subscriber cmd_vel_sub = nh.subscribe("/cmd_vel", 1, cmd_velCallback);
    /*twist msg from turtlebot teleop node*/
    ros::Subscriber cmd_vel_sub1 = nh.subscribe("/smooth_cmd_vel", 1000, cmd_velCallback);  /* twist msg from vel smoother node*/
    ros::Subscriber sub_zhishancmd = nh.subscribe("/zhishanAndroid/zhishancmd", 1000, zhishancmdCallback);     /*button msg from dashan_hmi node*/
    ros::Subscriber sub_dashan_diag = nh.subscribe("/dashan_diag", 1000, dashan_diagCallback);     /*button msg from dashan_hmi node*/
    //ros::Subscriber sub_r2000_node_scan = nh.subscribe("/scan", 1000, dashan_r2000_scan_Callback);     /*button msg from dashan_hmi node*/

   /*ROS publisher*/
    ros::Publisher pub = nh.advertise<dashan_msg::wheelSpeed>("/wheel_speed", 1000);

    ros::Publisher pubIMUData = nh.advertise<dashan_msg::imudata>("/imu_data", 1000);//Peter
	ros::Publisher pubHMI = nh.advertise<dashan_msg::hmiStatus>("/zhishanAndroid/hmiStatus", 1000);
    s_pubZhishancmd = nh.advertise<dashan_msg::zhishancmd>("/zhishanAndroid/zhishancmd", 1000);

    memset(&send_pack, 0x00, sizeof(Zshan_Send_Pack));
    send_pack.start_flag = SEND_PACK_START_FLAG;
    send_pack.index = SEND_PACK_START_INDEX;
#if 1
    /*open serial device*/
    if ((fd = open ("/dev/ttyS1", O_RDWR|O_NOCTTY|O_NDELAY)) < 0)
    {
	ROS_ERROR("Unable to open serial device: %s\n", "/dev/ttyS1") ;
	return 1 ;
    }
     if(fcntl(fd, F_SETFL, 0)<0)
        printf("fcntl failed!\n");
    else
        printf("fcntl=%d\n",fcntl(fd, F_SETFL,0));

    if(isatty(STDIN_FILENO)==0)
        printf("standard input is not a terminal device\n");
    else
        printf("isatty success!\n");
    //printf("fd-open=%d\n",fd);
    /*set serial options*/
    if (SetSerialPort(fd,115200,8,1,'n') == 1)     /*8 databits, 1 stopbit, no parity*/
    {
        ROS_ERROR("SetSerialPort Error !\n");
        return 1 ;
    }

#if 1
	/*spawn a thread to receive serial port data*/
	if(0 != pthread_mutex_init(&mutex,NULL))  
    {  
		ROS_ERROR("[SERIAL]cannot create mutex_init!\n");
        exit(1);  
		return 1;
    } 
	err = pthread_create(&tid, NULL, SerialRecvTask, NULL);
	if (0 != err)
	{
		ROS_ERROR("cannot create SerialRecvTask thread!\n");
		return 1;
	}
#endif

#endif
	/*send serial port data periodly*/
	ros::Rate loop_rate(20); //20hz, 50ms
	while(ros::ok())
	{
		//print_time_serial_SEND();
		/*construct send package*/
                //by hulu20190603
                cmd_vel_timeout++;
		if(cmd_vel_timeout > 10)  //用于判断没有按下手柄速度的情况下，清除之前的订阅到速度信息，防止暴走
		{
		   s_vel.linear.x = 0.0;	
  	           s_vel.linear.y = 0.0;    
	           s_vel.angular.z = 0.0;	

		   cmd_vel_timeout = 0;
		}
		send_pack.vx = (short)(s_vel.linear.x * 1000);// convert speed to integar
		send_pack.vz = (short)(s_vel.angular.z * 1000);//
		if(0 == c_DiagState)
		{
			send_pack.cLedHelth = 0x02;//green light always on
		}
		else
		{
			send_pack.cLedHelth = c_DiagState;
		}
		send_pack.cLedstatus = 0x34;//Peter,change here
		send_pack.cPushRodPos = (short)(s_rod_control);//Peter,change here
		send_pack.reserved[1] = (char)s_rod_control;//
		if(true == g_bAutoChargeFlag)
		{
			send_pack.reserved[0] = 0x01;//start charge
			ROS_INFO_COND_NAMED(true == g_bIsLogOpen, "zhishanlog", "[SERIAL][start charge] = %d\n", 1);
		}
		else
		{
			send_pack.reserved[0] = 0x00;//
		}
		if(true == g_bManualStopCharge)
		{
			if(10 > sendChargeStopCmd)
			{
			    send_pack.reserved[0] = 0x03;//stop charge
			    sendChargeStopCmd++;
				ROS_INFO_COND_NAMED(true == g_bIsLogOpen, "zhishanlog", "[SERIAL][sendChargeStopCmd] bigthan  %d\n", 10);

			}
			else
			{
				ROS_INFO_COND_NAMED(true == g_bIsLogOpen, "zhishanlog", "[SERIAL][sendChargeStopCmd] smallthan %d\n", 10);
				send_pack.reserved[0] = 0x00;//
				g_bManualStopCharge = false;
			}
		}
		else
		{
			sendChargeStopCmd = 0;
		}

                //not write reserve here
                //ROS_INFO("send pack from PC to DSP");
		CalcCheckCode(&send_pack);

		/*send the package*/
		SendData(&send_pack);
		/////////////////////
        /////////////////////
		pthread_mutex_lock(&mutex);/*lock the mutex*/  

		wheel_speed_msg.leftwheel_speed = ((double)(stParseRTPkg.l_wheel_vel) / 1000.0);
		wheel_speed_msg.rightwheel_speed =((double)(stParseRTPkg.r_wheel_vel) / 1000.0);
		
		//buttonStatus.FuncBtn = (int)stParseNRTPkg.cButtonState;
		
		imu_msg.Temp = stParseNRTPkg.cTemp;
		imu_msg.Yaw = (float)((float)stParseRTPkg.lAngleZ/100.0); //chengwei deleted
		imu_msg.Gz = (float)((float)stParseRTPkg.sAngSpeedZ / 10.0);//Peter,20160514
		//ROS_INFO("imu_msg.Yaw: %f\n", imu_msg.Yaw);
		msghmiStatus.temperature = stParseNRTPkg.cTemp;
		msghmiStatus.humidity = stParseNRTPkg.cHumidity;
		msghmiStatus.smogAlert = stParseNRTPkg.cSmoke;
		//
		msghmiStatus.batteryPercent = stParseNRTPkg.battery_left;
		/*publish wheel speed*/
		pub.publish(wheel_speed_msg);
		/*publish imu message*/
        pubIMUData.publish(imu_msg);
		
        pthread_mutex_unlock(&mutex);/*unlock the mutex*/  
		
	    /*get received wheel speed and send to other ros node*/
		if (COMM_STAT_OK == s_serial_comm_stat)
		{
			msghmiStatus.commLinkState = COMM_STAT_OK;
		}
		else if(COMM_STAT_ERR == s_serial_comm_stat)
		{
           msghmiStatus.commLinkState = COMM_STAT_ERR;
		}
		else
		{
           msghmiStatus.commLinkState = COMM_STAT_ERR;
		}
        pubHMI.publish(msghmiStatus);
		/////////
		if(stParseRTPkg.cSonarFL< OBSTACLE_AVOIDANCE && 0 < stParseRTPkg.cSonarFL)
		{
			SonarWarnningLeft++;   
		}
		else
		{
			SonarWarnningLeft = 0;
		}
				
		if(stParseRTPkg.cSonarFR < OBSTACLE_AVOIDANCE && 0 < stParseRTPkg.cSonarFR)
		{
			SonarWarnningRight++;
		}
		else
		{
			SonarWarnningRight = 0;
		}
		
	    if(SonarWarnningLeft > 120) //120*50ms
		{
			/*
			s_msgZhishancmd.zhishanCommand = 8;//voice
			s_msgZhishancmd.zhishanPara = 3;
			s_msgZhishancmd.zhishanVoice = 32;//please make a way
			s_pubZhishancmd.publish(s_msgZhishancmd);
			s_msgZhishancmd.zhishanCommand = 21;//turn right
			s_msgZhishancmd.zhishanPara = 2; //2*PI/4
			s_msgZhishancmd.zhishanVoice = 0;
			s_pubZhishancmd.publish(s_msgZhishancmd);
			*/
			ROS_INFO_COND_NAMED(true == g_bIsLogOpen, "zhishanlog", "PeterSonarfrontleft = %d\n", stParseRTPkg.cSonarFL);
			
			SonarWarnningLeft = 0;
		}
		else if(SonarWarnningRight > 120)
		{
			/*
			s_msgZhishancmd.zhishanCommand = 8;//voice
			s_msgZhishancmd.zhishanPara = 3;
			s_msgZhishancmd.zhishanVoice = 32;//please make a way
			s_pubZhishancmd.publish(s_msgZhishancmd);
			s_msgZhishancmd.zhishanCommand = 15;//turn left
			s_msgZhishancmd.zhishanPara = 2;//2*PI/4
			s_msgZhishancmd.zhishanVoice = 0;
			s_pubZhishancmd.publish(s_msgZhishancmd);
			*/
			ROS_INFO_COND_NAMED(true == g_bIsLogOpen, "zhishanlog", "PeterSonarfrontright = %d\n", stParseRTPkg.cSonarFR);
			
			SonarWarnningRight = 0;
		}
		else
		{
			
		}

        s_rod_control = 0;
		ros::spinOnce();
		loop_rate.sleep();
	}

    /*when node exit, handle the thread*/
	err = pthread_cancel(tid);
	if (0 != err)
	{
		ROS_ERROR("cannot cancel SerialRecvTask thread!\n");
		return 1;
	}

	err = pthread_join(tid, &res);
	if (0 != err)
	{
		ROS_ERROR("cannot join SerialRecvTask thread!\n");
		return 1;
	}
	return 0 ;
}


