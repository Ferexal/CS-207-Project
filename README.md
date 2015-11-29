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

No special setup is required to compile and upload this code to an Arduino. Simply use the latest Arduino IDE.

### Servo Control

The servo control sketch uses three Hitec(HS-422 Deluxe) and two smaller generic servos with a Lynxmotion Pan/Tilt kit. The base servo should be wired to pin D9 and has a full operating range of 0 degrees to 180 degrees while the shoulder servo should be wired to pin D10 and has an operating range of 0 degrees to 135 degrees to avoid collisions with the tilt bracket. The elbow servo should be wired to D11 and has an operation range of 30 degrees to 180 degrees. FInally, the two claw servos should be wired to pins D12(right) and D13(left) with operating ranges of 1 degree to 125 degrees(right) and 55 degrees to 179 degrees(left).

This code allows you to control the five servos through the Ardunio IDE serial monitor by entering degree values in the following format:

		B#
		S#
		E#
		C#
		
Where B, S, E, C are the servo specifier characters with B being the base servo, S being the shoulder servo, E being the elbow servo and C being the claw servos. # represents the angle at which to set the servo and if it's out of range for the specified servo, it will be automatically adjusted.

The servos can also be controlled by the desktop application provided.

No special setup is required to compile and upload this code to an Arduino. Simply use the latest Arduino IDE.

### Controller Application

This applciation is written in Visual C++ and uses a CLI form for control. It uses the built in CLI serial object and allows you to connect to a serial port and control the arm with a slider for each servo.

To use this you can simply run the executable found in the debug folder or you can compile it with Visual Studio 2015 without any special setup. To use it simply connect your Arduino with the sevo code, launch the application, choose the COM port of the Arduino from the list and click "Set COM Port". The sliders will enable and you should be able to control the arm by moving them.


### Parts List

	1 x Arduino UNO Rev 3
	
	2 x Cytron 10A Motor Shield (http://www.robotshop.com/ca/en/10a-dc-motor-driver-arduino-shield.html)
	
	2 x 12V 50:1 170oz-inc Metal Gearmotor (http://www.robotshop.com/ca/en/12v-501-170oz-inc-metal-gearmotor.html)
	
	3 x Hitec HS-422 Deluxe Servo (http://www.robotshop.com/ca/en/hitec-hs422-servo-motor.html)
	
	Lynxmotion Pan/Tilt Kit (http://www.robotshop.com/ca/en/lynxmotion-pan-and-tilt-kit-aluminium2.html)
	
	2 x Generic Small Servo
