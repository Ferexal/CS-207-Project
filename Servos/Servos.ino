/*
	Multiple Servo Control
	
	Requires two servos assembled together with a Lynxmontion Pan/Tilt Kit.

	Wire the base servo to pin 9 and the top servo to pin 10.
	
	Servos are currently controlled via serial as follows (until Bluetooth is implemented):
	
		Values are entered as "0,0" (Servo 1 position, Servo 2 position)
		
		Servo 1 range: 0 degrees - 180 degrees
		Servo 2 range: 0 degrees - 135 degrees (to avoid collision with bracket)

	Created by Mitchell Steffensen
*/

#include <Servo.h> 
 
Servo servo1; //Base servo object
Servo servo2; //Top servo object

long servo1Pos = 0; //Default starting position for the base servo
long servo2Pos = 90; //Default starting position for the top servo
 
void setup() 
{ 
	Serial.begin(9600); //Open the serial port
	
	//Attach the servo's to their objects
	servo1.attach(9);
	servo2.attach(10);
	
	//Move the servos to their default positions
  	servo1.write(servo1Pos);
	servo2.write(servo2Pos);
} 
 
void loop() 
{ 	
	if(Serial.available() > 0) //There is available serial data
	{
		//Read input for the servo positions
		servo1Pos = Serial.parseInt();
		servo2Pos = Serial.parseInt();
		
		//The input is out of the possible range for the servo so adjust it accordingly
		if(servo1Pos < 0)
		{
			servo1Pos = 0;
		}
		else if(servo1Pos > 180)
		{
			servo1Pos = 180;
		}
		
		//The input is out of the possible range for the servo so adjust it accordingly
		if(servo2Pos < 0)
		{
			servo2Pos = 0;
		}
		else if(servo2Pos > 135)
		{
			servo2Pos = 135;
		}
		
		//Change the position of each servo
		servo1.write(servo1Pos);
		servo2.write(servo2Pos);
	}
} 
