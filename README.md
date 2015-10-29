# Driveable Robotic Arm

This goal of this project is to have a control a four-wheeled, driveable robotic arm controlled over Bluetooth.

The motor and servo control code can be compiled and uploaded to an Arduino through the standard Arduino IDE (1.6.5).

The Android application code is currently untested but should compile within Eclipse or Android Studio. This code will be used to develop our own Android application for controlling the robot over Bluetooth.

## Motor Control

The motor control sketch requires two Cytron 10A Motor Shield boards, stacked together on an Arduino (UNO Rev 3) as well as a 12V power source to allow the motors to reach full speed. The first board should have jumpers on pims D3 and D2 and the second board should have jumpers on pins D5 and D4.
Wire one motor opposite the other so that they spin in the same direction when facing opposite directions.

This code allows you to control the two motors through the Ardunio IDE serial monitor with the following values:

		0(ASCII 48) - Stop
		1(ASCII 49) - Forward
		2(ASCII 50) - Reverse
		3(ASCII 51) - Turn Right
		4(ASCII 52) - Turn Left
		
Control of the two drive motors will be adapted to Bluetooth and will eventually have acceleration and deceleration implemented to smooth motion.


## Servo Control

The servo control sketch uses two Hitec HS-422 Deluxe servos with a Lynxmotion Pan/Tilt kit. The base servo should be wired to pin D9 and the top servo should be wired to pin D10. The base servo has a full operating range of 0 degrees to 180 degrees while the to servo has an operating range of 0 degrees to 135 degrees to avoid collisions with the tilt bracket.

This code allows you to control the two servos through the Ardunio IDE serial monitor by entering degree values in the following format:

		0,0
		
The first value is the position of the base servo and the second value is the position of the top servo. If a specified value is out of the operating range of the servo, it is corrected. If a value is not specified for one the servos, it is defaulted to 0.

## Android Controller Application

This code is pulled from http://solderer.tv/cxemcar/ and has not yet been tested. It should compile and work on an Android device and will be adapted to our needs later.


