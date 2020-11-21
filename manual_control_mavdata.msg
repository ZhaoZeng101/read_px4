uint64 timestamp			# time since system start (microseconds)

int16 x 				# X-axis, normalized to the range [-1000,1000]. A value of INT16_MAX indicates that
					# this axis is invalid. Generally corresponds to forward(1000)-backward(-1000) movement on a joystick
					# and the pitch of a vehicle.*/
int16 y 				# Y-axis, normalized to the range [-1000,1000].
int16 z 				# Z-axis, normalized to the range [-1000,1000].
int16 r 				# R-axis, normalized to the range [-1000,1000].
uint16 buttons 				# A bitfield corresponding to the joystick buttons' current state, 1 for pressed, 0 for released. The lowest bit corresponds to Button 1.*/
uint8 target 				# The system to be controlled.*/

