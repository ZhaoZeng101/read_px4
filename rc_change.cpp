
	/**
	 * Get and limit value for specified RC function. Returns NAN if not mapped.
	 */
	float		get_rc_limit(float value, float min_value, float max_value);


    	uORB::Subscription	_manual_control_mavdata_sub{ORB_ID(manual_control_mavdata)};	/**< from mavlink control param subscription */


	manual_control_mavdata_s _manual_control_mavdata {};


    float
RCUpdate::get_rc_limit(float value, float min_value, float max_value)
{

	//float value = _rc.channels[_rc.function[func]];
	return math::constrain(value, min_value, max_value);


}

			//added by zz
			_manual_control_mavdata_sub.update(&_manual_control_mavdata);

			if(_rc.channels[5] < (float)-0.5){
				manual_control_setpoint.y = get_rc_limit(manual_control_setpoint.y + _manual_control_mavdata.x/1000.0f, -1.0, 1.0); //get_rc_value(rc_channels_s::RC_CHANNELS_FUNCTION_ROLL, -1.0, 1.0);
				manual_control_setpoint.x = get_rc_limit(manual_control_setpoint.x + _manual_control_mavdata.y/1000.0f, -1.0, 1.0); //get_rc_value(rc_channels_s::RC_CHANNELS_FUNCTION_PITCH, -1.0, 1.0);
			}else if(_rc.channels[5] < (float)0.5){
				manual_control_setpoint.y = get_rc_limit(0, -1.0, 1.0);
				manual_control_setpoint.x = get_rc_limit(0, -1.0, 1.0);
			}
			PX4_INFO("channels[5]::%8.4f", (double)_rc.channels[5]);
			if(0)
			PX4_INFO("manual_mavdata:\ttimestamp:%8.4f\tchannels[x]:%8.4f\tchannels[y]:%8.4f\tchannels[z]:%8.4f\tchannels[r]:%8.4f\tmanual.source:%8.4f\tmode:%8.4f",
				(double)_manual_control_mavdata.timestamp,
				(double)_manual_control_mavdata.x,
				(double)_manual_control_mavdata.y,
				(double)_manual_control_mavdata.z,
				(double)_manual_control_mavdata.r,
				(double)_manual_control_mavdata.buttons,
				(double)_manual_control_mavdata.target);

			//end added by zz


