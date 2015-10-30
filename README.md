# Copyright
   
    Copyright (C) 2015  Mitchell Steffensen, Thomas Fahlman, and Kevin Peterson

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

# Driveable Robotic Arm

This goal of this project is to have a control a four-wheeled, driveable robotic arm controlled over Bluetooth.

The motor and servo control code can be compiled and uploaded to an Arduino through the standard Arduino IDE (1.6.5).

The Android application code is currently untested but should compile within Eclipse or Android Studio. This code will be used to develop our own Android application for controlling the robot over Bluetooth.

### Motor Control

The motor control sketch requires two Cytron 10A Motor Shield boards stacked together on an Arduino (UNO Rev 3) as well as a 12V power source connected to each shield. The first board should have jumpers on pins D3 and D2 and the second board should have jumpers on pins D5 and D4. 

The motors used are 12V 50:1 170oz-inc Metal Gearmotors with one motor wired opposite the other so that they spin in the same direction when facing opposite directions.

This code allows you to control the two motors through the Ardunio IDE serial monitor with the following values:

		0(ASCII 48) - Stop
		1(ASCII 49) - Forward
		2(ASCII 50) - Reverse
		3(ASCII 51) - Turn Right
		4(ASCII 52) - Turn Left
		
Control of the two drive motors will be adapted to Bluetooth and will eventually have acceleration and deceleration implemented to smooth motion.


### Servo Control

The servo control sketch uses two Hitec HS-422 Deluxe servos with a Lynxmotion Pan/Tilt kit. The base servo should be wired to pin D9 and has a full operating range of 0 degrees to 180 degrees while the top servo should be wired to pin D10 and has an operating range of 0 degrees to 135 degrees to avoid collisions with the tilt bracket.

This code allows you to control the two servos through the Ardunio IDE serial monitor by entering degree values in the following format:

		0,0
		
The first value is the position of the base servo and the second value is the position of the top servo. If a specified value is out of the operating range of the servo, it is corrected and if a value is not specified for one the servos, it is defaulted to 0.

### Android Controller Application

This code is pulled from http://solderer.tv/cxemcar/ and has not yet been tested. It should compile and work on an Android device and will be adapted to our needs later.


### Parts List

	2 x Arduino UNO Rev 3
	
	2 x Cytron 10A Motor Shield (http://www.robotshop.com/ca/en/10a-dc-motor-driver-arduino-shield.html)
	
	2 x 12V 50:1 170oz-inc Metal Gearmotor (http://www.robotshop.com/ca/en/12v-501-170oz-inc-metal-gearmotor.html)
	
	Lynxmotion Pan/Tilt Kit (includes 2 x Hitec HS-422 Deluxe Servo) (http://www.robotshop.com/ca/en/lynxmotion-pan-and-tilt-kit-aluminium2.html)
