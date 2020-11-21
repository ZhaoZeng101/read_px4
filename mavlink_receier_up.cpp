/*************************************************************************
	> File Name: mavlink_receier_up.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 20 Nov 2020 07:14:11 PM PST
 ************************************************************************/

#include<iostream>
using namespace std;
{
		struct manual_control_setpoint_s manual = {};
    //    static orb_advert_t manual_pub = orb_advertise(ORB_ID(manual_control_setpoint), &manual);
        static int rc_channels_sub = orb_subscribe(ORB_ID(rc_channels));
        static struct rc_channels_s rc;
        bool rc_updated;
        
        struct mav_manual_control_s mav_control = {};
        static orb_advert_t mav_manual_control_pub = orb_advertise(ORB_ID(mav_manual_control), &manual);

        orb_check(rc_channels_sub, &rc_updated);
        if(rc_updated){
            orb_copy(ORB_ID(rc_channels), rc_channels_sub, &rc);
        }
        
       // PX4_INFO("man.x / 1000.0f to publish ORB_ID(manual_control_setpoint)");
		manual.timestamp = hrt_absolute_time();
		manual.x = math::constrain(double(man.x - 1500) * 0.005, -1.0, 1.0);
		manual.y = math::constrain(double(man.y - 1500) * 0.005, -1.0, 1.0);
		manual.r = math::constrain(double(man.r - 1500) * 0.003, -1.0, 1.0);
		manual.z = math::constrain(double(man.z - 1000) * 0.001, 0.0, 1.0);
		manual.data_source = manual_control_setpoint_s::SOURCE_MAVLINK_0 + _mavlink->get_instance_id();

        mav_control.timestamp = manual.timestamp;
        mav_control.x = manual.x;
        mav_control.y = manual.y;
        mav_control.z = manual.z;
        mav_control.r = manual.r;

        orb_publish(ORB_ID(mav_manual_control), mav_manual_control_pub, &mav_control); 
	//	int m_inst;
	//	orb_publish_auto(ORB_ID(manual_control_setpoint), &_manual_pub, &manual, &m_inst, ORB_PRIO_VERY_HIGH);
        if((double)rc.channels[4] >= 0.5){
    //        orb_publish(ORB_ID(manual_control_setpoint), manual_pub, &manual);
        }
	}
