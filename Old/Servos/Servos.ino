/*
	Multiple Servo Arm Control
	
	Requires five servos. Two for pan and tilt (base and shoulder), one for the elbow and two for the claw.
		- Base servo on pin 9
		- Shoulder servo on pin 10
		- Elbow servo on pin 11
		- Claw right servo on pin 12
		- Claw left servo on pin 13
	
	Servo characters:
		B(66) = Base
		S(83) = Shoulder
		E(69) = Elbow
		C(67) = Claw
	
	To control each servo you simply send the servo character for the servo followed by a value.
	Example: "E180" will set the elbow servo to 180 degrees.
	Values that are out of range for the specified servo are checked and adjusted accordingly.

	Created by Mitchell Steffensen
*/

#include <Servo.h> 

//Servo pins
const int BASE_SERVO_PIN = 9;
const int SHOULDER_SERVO_PIN = 10;
const int ELBOW_SERVO_PIN = 11;
const int CLAW_RIGHT_SERVO_PIN = 12;
const int CLAW_LEFT_SERVO_PIN = 13;

//Servo ranges
const int BASE_SERVO_MAX = 180;
const int BASE_SERVO_MIN = 0;
const int SHOULDER_SERVO_MAX = 135;
const int SHOULDER_SERVO_MIN = 0;
const int ELBOW_SERVO_MAX = 180;
const int ELBOW_SERVO_MIN = 30;
const int CLAW_RIGHT_SERVO_MAX = 125;
const int CLAW_RIGHT_SERVO_MIN = 1;
const int CLAW_LEFT_SERVO_MAX = 179;
const int CLAW_LEFT_SERVO_MIN = 55;

const int SERVO_SPEED = 20; //Servo speed (Delay between each servo movement)
 
//Servo objects
Servo baseServo;
Servo shoulderServo;
Servo elbowServo;
Servo clawRightServo;
Servo clawLeftServo;

//Current servo positions
long baseServoPos = 90;
long shoulderServoPos = 90;
long elbowServoPos = 120;
long clawRightServoPos = 1;
long clawLeftServoPos = 179;

int servoByte = 0; //First byte of serial data to check which servo(s) to control

void setup() 
{ 
	Serial.begin(9600); //Open the serial port
	
	//Attach the servo's to their objects
	baseServo.attach(BASE_SERVO_PIN);
	shoulderServo.attach(SHOULDER_SERVO_PIN);
	elbowServo.attach(ELBOW_SERVO_PIN);
	clawRightServo.attach(CLAW_RIGHT_SERVO_PIN);
	clawLeftServo.attach(CLAW_LEFT_SERVO_PIN);
	
	//Move the servos to their default positions
  	baseServo.write(baseServoPos);
	shoulderServo.write(shoulderServoPos);
	elbowServo.write(elbowServoPos);
	clawLeftServo.write(clawLeftServoPos);
	clawRightServo.write(clawRightServoPos);
} 
 
void loop() 
{ 	
	if(Serial.available() > 0) //There is available serial data
	{
		servoByte = Serial.read(); //Read the first byte of the serial data to determine which servo(s) to control
		
		if(servoByte == 66) //Base
		{
			moveServo(baseServo, baseServoPos, BASE_SERVO_MAX, BASE_SERVO_MIN, SERVO_SPEED);
		}
		else if(servoByte == 83) //Shoulder
		{
			moveServo(shoulderServo, shoulderServoPos, SHOULDER_SERVO_MAX, SHOULDER_SERVO_MIN, SERVO_SPEED);
		}
		else if(servoByte == 69) //Elbow
		{
			moveServo(elbowServo, elbowServoPos, ELBOW_SERVO_MAX, ELBOW_SERVO_MIN, SERVO_SPEED);
		}
		else if(servoByte == 67) //Claw
		{
			clawRightServoPos = Serial.parseInt(); //Read input for the servo position
			
			//The input is out of the possible range for the servo so adjust it accordingly
			if(clawRightServoPos < CLAW_RIGHT_SERVO_MIN)
			{
				clawRightServoPos = CLAW_RIGHT_SERVO_MIN;
			}
			else if(clawRightServoPos > CLAW_RIGHT_SERVO_MAX)
			{
				clawRightServoPos = CLAW_RIGHT_SERVO_MAX;
			}
	
			clawLeftServoPos = 180 - clawRightServoPos; //Invert the value for the left claw
			
			//Move both sides of the claw
			clawRightServo.write(clawRightServoPos);
			clawLeftServo.write(clawLeftServoPos);
		}
	}
}

void moveServo(Servo servo, long &lastPos, int max, int min, int moveDelay)
{
	long newPos = Serial.parseInt(); //Read input for the servo position
	
	//The input is out of the possible range for the servo so adjust it accordingly
	if(newPos < min)
	{
		newPos = min;
	}
	else if(newPos > max)
	{
		newPos = max;
	}
	
	if(newPos > lastPos) //The new position is greater than the last position
	{
		//Loop up from the old position to the new position, moving the servo 1 degree at a time with a delay in between each movement
		for (int i = lastPos; i <= newPos; i++)
		{
			servo.write(i);
			delay(moveDelay);
		}
	}
	else //The new position is less than the last position
	{
		//Loop down from the old position to the new position, moving the servo 1 degree at a time with a delay in between each movement
		for (int i = lastPos; i >= newPos; i--)
		{
			servo.write(i);
			delay(moveDelay);
		}
	}
	
	lastPos = newPos; //Update the last known position
}