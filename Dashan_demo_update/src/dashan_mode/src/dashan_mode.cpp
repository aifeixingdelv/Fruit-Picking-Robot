#include <ros/ros.h>

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include <dashan_msg/Mode.h>

/*include following files for socket programming*/
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/if_ether.h>
#include <net/if.h>
#include <linux/sockios.h>

#define NAVIGATION_MODE 1
#define GMAPPING_MODE 2

#define MAC0        0x00  
#define MAC1        0x1f
#define MAC2        0xc6
#define MAC3        0x82
#define MAC4        0x8c
#define MAC5        0xe8



static int s_robotMode = 0;  /*robot mode. 1:navigatioin mode. 2:gmapping mode*/



static int Checkhardware(void)
{
    int iRet = 0;
    const char *device="eth0"; 
    unsigned char macaddr[6];       /*mac read from hardware*/
    unsigned char mac_allowed[6];   /*mac specifed from base_controller.h*/
    struct ifreq req;
    int i = 0;;
    int fd;

    /*get the specified allowed mac*/
    mac_allowed[0] = MAC0;
    mac_allowed[1] = MAC1;
    mac_allowed[2] = MAC2;
    mac_allowed[3] = MAC3;
    mac_allowed[4] = MAC4;
    mac_allowed[5] = MAC5;
    
    /*read the hardware mac*/
    fd = socket(AF_INET, SOCK_DGRAM, 0);
    strcpy(req.ifr_name, device);        //\u0153璞\u017e名作为输入参数\u017d?    iRet = ioctl(fd, SIOCGIFHWADDR, &req);  //謀u017d行取MAC地址操作
    close(fd);

    if (-1 != iRet)
    {
        memcpy(macaddr, req.ifr_hwaddr.sa_data, 6); //取输出的MAC地址
        #if 0
        printf("mac: ");
        for(i=0; i<6; i++)
        {
            printf("%x ", macaddr[i]);
        }
        printf("\n");
        #endif
    }
    
    /*compare the mac*/
    for(i=0; i<6; i++)
    {
        if (mac_allowed[i] != macaddr[i])
        {
            break;
        }
    }

    if (6 != i)
    {
        ROS_ERROR("THE HARDWARE IS NOT AUTHORISED ! PLEASE CONTACT ZHISHAN CORP.\n");
        iRet = -1;
    }

	/*remove 70-persistent-net.rules , prevent eth0 name change to eth1,eth2...*/
	remove("/etc/udev/rules.d/70-persistent-net.rules");
    
    return iRet;
}


static void modeCallback(const dashan_msg::Mode :: ConstPtr &msg)
{
    s_robotMode = msg->mode;
}

int main(int argc, char** argv)
{
	int iRet;
	ROS_INFO("dashan_mode node loaded!\n");

	/* check hardware */
	/*
    if (0 != Checkhardware())
    {
        return iRet;
    }
    */
	ros::init(argc, argv, "dashan_mode");
	ros::NodeHandle nh;

    ros::Rate loop_rate(10); 

    /*subscribe robot mode msg*/
    ros::Subscriber sub_robot_mode_cmd = nh.subscribe("/dashan_mode", 1, modeCallback);

    /*waiting for robot mode be set*/
    while((NAVIGATION_MODE != s_robotMode) && (GMAPPING_MODE != s_robotMode)) 
    {
	    ros::spinOnce();
		loop_rate.sleep();
    }

    /*launch different nodes according to the s_robotMode*/
    if (NAVIGATION_MODE == s_robotMode)
    {
        ROS_INFO("dashan_core: NAVIGATION_MODE launch... \n");
        system("roslaunch dashan_2dnav dashan_demo_amcl.launch");
    }

    if (GMAPPING_MODE == s_robotMode)
    {
        ROS_INFO("dashan_core: GMAPPING_MODE launch... \n");     
        system("roslaunch dashan_2dnav gmapping_demo.launch");
    }
}
