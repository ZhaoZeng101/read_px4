#include <uORB/topics/manual_control_mavdata.h>
269 	uORB::PublicationMulti<manual_control_mavdata_s>	_manual_control_mavdata_pub{ORB_ID(manual_control_mavdata)};

	} else {
		//manual_control_setpoint_s manual{};
		manual_control_mavdata_s manual_mav{};
		//PX4_INFO("mavlink_receiver.cpp--handle_message_manual_control()--if(_mavlink->should_gener...)else ");
		//manual_mav.timestamp = manual.timestamp = hrt_absolute_time();
		//manual.x = man.x / 1000.0f;
		//manual.y = man.y / 1000.0f;
		//manual.r = man.r / 1000.0f;
		//manual.z = man.z / 1000.0f;
		//manual.data_source = manual_control_setpoint_s::SOURCE_MAVLINK_0 + _mavlink->get_instance_id();

		//_manual_control_setpoint_pub.publish(manual);

		manual_mav.x = man.x;
		manual_mav.y = man.y;
		manual_mav.z = man.z;
		manual_mav.r = man.r;
		manual_mav.buttons = man.buttons;
		manual_mav.target = man.target;

		if(0)
		PX4_INFO("manual_mavdata:\ttimestamp:%8.4f\tchannels[x]:%8.4f\tchannels[y]:%8.4f\tchannels[z]:%8.4f\tchannels[r]:%8.4f\tmanual.source:%8.4f\tmode:%8.4f",
				(double)manual_mav.timestamp,
				(double)manual_mav.x,
				(double)manual_mav.y,
				(double)manual_mav.z,
				(double)manual_mav.r,
				(double)manual_mav.buttons,
				(double)manual_mav.target);

		_manual_control_mavdata_pub.publish(manual_mav);
	}
