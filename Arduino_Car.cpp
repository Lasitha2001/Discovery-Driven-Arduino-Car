#include <Arduino.h>
#include <RC_Receiver.h>

void mpower(int motor, int spd);

RC_Receiver receiver(A0, A1);

int minMax[2][2] =
    {
        {-255, 255},
        {-255, 255},
};

int enA = 5;
int in1 = 2;
int in2 = 3;
int enB = 6;
int in3 = 4;
int in4 = 7;

void setup()
{
  Serial.begin(115200);
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  receiver.setMinMax(minMax); // set the min and max value for each channels

  Serial.println("Ready");
}

void loop()
{
  int forwardSpeed = map(receiver.getRaw(2), 1989, 1015, -255, 255); // Forward/Backward
  int turnSpeed = map(receiver.getRaw(1), 1983, 1000, -255, 255);    // Left/Right

   // Control the motors based on joystick input
  int leftMotorSpeed = forwardSpeed + turnSpeed;
  int rightMotorSpeed = forwardSpeed - turnSpeed;

  mpower(1, rightMotorSpeed);  // Control left motors
  mpower(2, leftMotorSpeed); // Control right motors

  Serial.println(receiver.getRaw(1));
}

void mpower(int motor, int spd)
{
  int rotation = 0;
  if (spd > 0)
  {
    rotation = 1;
  }
  else if (spd < 0)
  {
    rotation = -1;
    spd *= -1;
  }
  if (spd > 255)
  {
    spd = 255;
  }
  int pwm;
  int pA;
  int pB;
  if (motor == 1)
  {
    pwm = enA;
    pA = in1;
    pB = in2;
  }
  else if (motor == 2)
  {
    pwm = enB;
    pA = in3;
    pB = in4;
  }
  else
  {
    return;
  }
  if (rotation == 0)
  {
    digitalWrite(pA, LOW);
    digitalWrite(pB, LOW);
  }
  else if (rotation == 1)
  {
    digitalWrite(pA, HIGH);
    digitalWrite(pB, LOW);
  }
  else if (rotation == -1)
  {
    digitalWrite(pA, LOW);
    digitalWrite(pB, HIGH);
  }
  analogWrite(pwm, spd);
}
