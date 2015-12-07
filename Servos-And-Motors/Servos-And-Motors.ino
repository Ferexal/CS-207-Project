/*
	Multiple Servo Arm Control
	
	Requires five servos. Two for pan and tilt (base and shoulder), one for the elbow and two for the claw.
    - Motor Left Direction on pin 2
    - Motor Left PWM on pin 3
    - Motor Right Direction on pin 4
    - Motor Right PWM on pin 5
		- Base servo on pin 9
		- Shoulder servo on pin 10
		- Elbow servo on pin 11
		- Claw right servo on pin 12
		- Claw left servo on pin 13

    The first board should have jumpers on pin D3 and pin D2.
    The second board should have jumpers on pin D5 and D4.
	
	Servo characters:
		B = Base
		S = Shoulder
		E = Elbow
		C = Claw
    Y = Forward/Backwards Movement
    X = Left/Right turrning
	
	To control each servo you simply send the servo character for the servo followed by a value.
	Example: "E180" will set the elbow servo to 180 degrees.
	Values that are out of range for the specified servo are checked and adjusted accordingly.
	Values for the claw range between 0 and 105 degrees
	Values for the motor range from -254 to + 254 degrees

	Created by Mitchell Steffensen and Kevin Peterson
*/

#include <Servo.h> 
#include "Settings.h"

byte incomingByte;
int incomingInt;


void setup() 
{ 
	Serial.begin(9600); //Open the serial port

	//Attach the servo's to their objects
	base.servo.attach(base.PIN);
	shoulder.servo.attach(shoulder.PIN);
	elbow.servo.attach(elbow.PIN);
	clawRight.servo.attach(clawRight.PIN);
	clawLeft.servo.attach(clawLeft.PIN);

	//Move the servos to their default positions
	base.servo.write(base.currPos);
	shoulder.servo.write(shoulder.currPos);
	elbow.servo.write(elbow.currPos);
	clawLeft.servo.write(clawLeft.currPos);
	clawRight.servo.write(clawRight.currPos);

	pinMode(motors.RIGHT_PWM_PIN, OUTPUT);
	pinMode(motors.LEFT_PWM_PIN, OUTPUT);
	pinMode(motors.RIGHT_DIRECTION_PIN, OUTPUT);
	pinMode(motors.LEFT_DIRECTION_PIN, OUTPUT);
} 

//for timing of each part
long prevTime[4];
 
void loop() 
{ 	
	if(Serial.available() >= 2) //wait until there is enough serial data to do an action (1 byte char identifier, 1, 2, or 4 byte integer)
	{
		incomingByte = Serial.read();
		incomingInt = Serial.parseInt();
		
		switch(incomingByte) //Read the first byte of the serial data to determine which servo(s) or motors to adjust values of
		{ 
			case 'B': 
				base.toPos = incomingInt;
				//Serial.println("B");////---------------------------------------------debug
				break;
			
			case 'S': 
				shoulder.toPos = incomingInt;
				//Serial.println("S");////---------------------------------------------debug
				break;
			
			case 'E': 
				elbow.toPos = incomingInt;
				//Serial.println("E");////--------------------------------------------debug
				break;
			
			case 'C': 
				clawRight.currPos = incomingInt;
				moveClaw(clawRight, clawLeft);
				//Serial.println("C");////---------------------------------------------debug
				break;

			case 'X':
				motors.X = incomingInt;
				//Serial.println(motors.X);
				Serial.println("X");////-----------------------------------------------debug
				break;

			case 'Y':
				motors.Y = incomingInt;
				//Serial.println(motors.Y);
				Serial.println('Y'); ////--------------------------------------------debug
				break;
			
			default: //invalid data, clear the buffer, then continue
				while(Serial.available()){
				  Serial.read();
				}
				break;
		}
  }
  
	//Move all things 1 step closer to their target
	if(millis() - prevTime[0] >= base.DELAY)
	{
		prevTime[0] = millis();
		moveServo(base);
	}

	if(millis() - prevTime[1] >= shoulder.DELAY)
	{
		prevTime[1] = millis();
		moveServo(shoulder);
	}

	if(millis() - prevTime[2] >= elbow.DELAY)
	{
		prevTime[2] = millis();
		moveServo(elbow);
	}

	if(millis() - prevTime[3] >= motors.DELAY)
	{
		prevTime[3] = millis();
		controlMotors(motors);
	}
  
  //Serial.println("--------------");////--------------------------------------------------------------debug
}

void moveServo(ServoInfo& servo)
{
	//If input is out of the possible range for the servo, adjust it accordingly
	if(servo.currPos < servo.MIN)
	{
		servo.currPos = servo.MIN;
	}
	else if(servo.currPos > servo.MAX)
	{
		servo.currPos = servo.MAX;
	}

	if(servo.toPos > servo.currPos) //The new position is greater than the current position
	{
		servo.servo.write(servo.currPos++);
		//Serial.println(servo.currPos);////--------------------------------------------------------------------debug
	}
	else if(servo.toPos < servo.currPos) //The new position is less than the current position
	{
		servo.servo.write(servo.currPos--);
		//Serial.println(servo.currPos);////----------------------------------------------------------------------debug
	}
}


void moveClaw(ServoInfo& rightClaw, ServoInfo& leftClaw)
{
	//The input is out of the possible range for the servo so adjust it accordingly
	if(rightClaw.currPos < rightClaw.MIN)
	{
		rightClaw.currPos = rightClaw.MIN;
	}
	else if(rightClaw.currPos > rightClaw.MAX)
	{
		rightClaw.currPos = rightClaw.MAX;
	}

	leftClaw.currPos = 180 - rightClaw.currPos; //Invert the value for the right claw

	//Move both sides of the claw
	//Serial.println(rightClaw.currPos); ////---------------------------------------------------------------------debug
	//Serial.println(leftClaw.currPos);////------------------------------------------------------------------------debug
	rightClaw.servo.write(rightClaw.currPos);
	leftClaw.servo.write(leftClaw.currPos);
}

void controlMotors(Motors& motors)
{
	//Calculate left and right motor speeds for a differential style drive

	//Algorithm 1
	//motors.toValRight = (motors.Y * (1.0 + ((float)motors.X / 254.0)));
	//motors.toValLeft = (motors.Y * (1.0 - ((float)motors.X / 254.0)));

	//Algorithm 2
	motors.toValRight = motors.Y;
	motors.toValLeft = motors.Y;
	
	if(motors.X > 0)
	{
		motors.toValRight = motors.toValRight * (1.0 - (abs((float)motors.X / 254.0)));
	}
	else if(motors.X < 0)
	{
		motors.toValLeft = motors.toValLeft * (1.0 - (abs((float)motors.X / 254.0)));
	}

	//Serial.println(motors.toValRight);////----------------------------------------------------------------------------debug
	//Serial.println(motors.toValLeft);////----------------------------------------------------------------------------debug

	//Crrect the values if needed
	motors.toValRight = constrain(motors.toValRight, -254, 254);
	motors.toValLeft = constrain(motors.toValLeft, -254, 254);

	if(motors.toValRight != motors.currValRight || motors.toValLeft != motors.currValLeft)
	{
		//Save curr values for direction logic
		motors.prevValRight = motors.currValRight;
		motors.prevValLeft = motors.currValLeft;  


		//Right motor speed and direction control
		if(motors.toValRight < motors.currValRight)
		{
			motors.currValRight--; //Accelerate backwards
		}
		else if (motors.toValRight > motors.currValRight)
		{
			motors.currValRight++; //Accelerate forwards
		}

		//Left motor speed and direction control
		if(motors.toValLeft < motors.currValLeft)
		{
			motors.currValLeft--; //Accelerate backwards
		}
		else if (motors.toValLeft > motors.currValLeft)
		{
			motors.currValLeft++; //Accelerate forwards
		}

		//If the motors have moved to either side of 0, set the direction to the correct value
		if(motors.prevValRight == 0)
		{
			if( motors.currValRight < motors.prevValRight)
			{
				digitalWrite(motors.RIGHT_DIRECTION_PIN, HIGH); //Backwards
			}
			else if(motors.currValRight > motors.prevValRight)
			{
				digitalWrite(motors.RIGHT_DIRECTION_PIN, LOW); //Forwards
			}
		}

		//Check for the other motor
		if(motors.prevValLeft == 0)
		{
			if(motors.currValLeft < motors.prevValLeft)
			{
				digitalWrite(motors.LEFT_DIRECTION_PIN, HIGH); //Backwards
			}
			else if(motors.currValLeft > motors.prevValLeft)
			{
				digitalWrite(motors.LEFT_DIRECTION_PIN, LOW); //Forwards
			}
		}

		//Drive the PWM for the motors
		analogWrite(motors.RIGHT_PWM_PIN, abs(motors.currValRight));
		analogWrite(motors.LEFT_PWM_PIN, abs(motors.currValLeft));

		//Serial.println(motors.currValRight);////------------------------------------------------------------debug
		//Serial.println(motors.currValLeft);////--------------------------------------------------------------debug
	}
}

