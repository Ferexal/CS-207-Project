struct ServoInfo{
  const int PIN; // pin on which the servo is on
  const int MAX; // maximum range of the servo in degrees
  const int MIN; // minimum range of the servo in degrees
  const int DELAY; // the delay controlling the acceleration, higher values == slower acceleration, will trigger 1 step every DELAY milliseconds(approximately, will likely be slightly higher);
  int toPos;
  int currPos; // the current position of the servo in degrees
  int prevPos; // the last position the servo was in
  Servo servo; // the servo object
};

// base servo, that rotates the arm providing horizontal rotational motion
ServoInfo  base = {
  9, //PIN
  180, //MAX
  0, //MIN
  20, //DELAY
  90, //toPos
  90, //currPos
};

// shoulder servo, provides vertical rotation motion
ServoInfo  shoulder = {
  10, //PIN
  135, //MAX
  0, //MIN
  20, //DELAY
  90, //toPos
  90, //currPos
};

// elbow servo, provides additional vertical rotation motion
ServoInfo  elbow = {
  11, //PIN
  180, //MAX
  30, //MIN
  20, //DELAY
  120,  //toPos
  120, //currPos
};

ServoInfo clawRight = {// right claw, allows the arm to grip objects in conjunction with the left claw
  12, //PIN
  105, //MAX
  0, //MIN
  0,//DELAY, not used
  0, //toPos, not used
  0, //currPos
};

// left claw, allows the arm to grip objects in conjunction with the right claw
ServoInfo  clawLeft = {
  13, //PIN
  179, //MAX
  75, //MIN
  0, //DELAY, not used
  0,  //toPos, not used
  179, //currPos
};


struct Motors {
  //settings
  const int RIGHT_PWM_PIN = 5;
  const int RIGHT_DIRECTION_PIN = 4;
  const int LEFT_PWM_PIN = 3;
  const int LEFT_DIRECTION_PIN = 2;
  const int MAX_Y = 254;
  const int MAX_X = 254;
  const int MIN_Y = -254;
  const int MIN_X = -254;
  const int DELAY = 20;// 
  //end of settings
  int Y = 0;
  int X = 0;
  bool directionRight = 1;//HIGH
  bool directionLeft = 1; //HIGH
  int currValRight = 0;
  int currValLeft = 0;
  int toValRight = 0;
  int toValLeft = 0;
  int prevValRight = 0;
  int prevValLeft = 0;
}motors;

