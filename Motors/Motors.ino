/*
	Arduino UNO Rev 3 Brushed DC Motor Control
	
	Requires two Cytron 10A Motor Driver Shields (Rev 2) and a 12V power source.
	
	The first board should have jumpers on pin D3 and pin D2.
	The second board should have jumpers on pin D5 and D4.

	Wire one motor opposite the other so that they spin in the same direction when facing opposite directions.
	
	Motors are currently controlled via serial as follows (until Bluetooth is implemented):
	
		0(ASCII 48) - Stop
		1(ASCII 49) - Forward
		2(ASCII 50) - Reverse
		3(ASCII 51) - Turn Right
		4(ASCII 52) - Turn Left
	
	Created by Mitchell Steffensen
	"https://github.com/CytronTechnologies/Cytron_ShieldMD10/blob/master/ShieldMd10Example/ShieldMd10Example.ino" used for reference.
*/

const int motorPWM[] = {3, 5}; //Motor PWM pins
const int motorDir[] = {2, 4}; //Motor direction pins

int incomingByte = 0; //Incoming serial data

void setup()
{
	Serial.begin(9600); //Open the serial port
	

	for(int i = 0; i < sizeof(motorPWM)/sizeof(int); i++) //Set all motor PWM pins to output
	{
		pinMode(motorPWM[i], OUTPUT);
	}
	
	for(int i = 0; i < sizeof(motorDir)/sizeof(int); i++) //Set all motor direction pins to output
	{
		pinMode(motorDir[i], OUTPUT);
	}
}

void loop()
{
	if(Serial.available() > 0) //There is available serial data
	{
		incomingByte = Serial.read(); //Read the incoming byte
		
		if(incomingByte == 48) //Stop
		{
			analogWrite(motorPWM[0], 0);
			analogWrite(motorPWM[1], 0);
		}
		else if(incomingByte == 49) //Forward
		{
			analogWrite(motorPWM[0], 255);
			digitalWrite(motorDir[0], LOW);
			analogWrite(motorPWM[1], 255);
			digitalWrite(motorDir[1], LOW);
		}
		else if(incomingByte == 50) //Reverse
		{
			analogWrite(motorPWM[0], 255);
			digitalWrite(motorDir[0], HIGH);
			analogWrite(motorPWM[1], 255);
			digitalWrite(motorDir[1], HIGH);
		}
		else if(incomingByte == 51) //Turn Right
		{
			analogWrite(motorPWM[0], 255);
			digitalWrite(motorDir[0], LOW);
			analogWrite(motorPWM[1], 255);
			digitalWrite(motorDir[1], HIGH);
		}
		else if(incomingByte == 52) //Turn Left
		{
			analogWrite(motorPWM[0], 255);
			digitalWrite(motorDir[0], HIGH);
			analogWrite(motorPWM[1], 255);
			digitalWrite(motorDir[1], LOW);
		}
	}
}
