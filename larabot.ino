
#include <Servo.h>

Servo tiltServo;
Servo panServo;


void setup()
{
  Serial.begin(9600);

  tiltServo.attach(9);
  panServo.attach(10);

  tiltServo.write(140);
  panServo.write(90);
}


void loop()
{
  while (Serial.available() > 0 )
  {
    int axis = Serial.parseInt();
    int degr = Serial.parseInt();

    if (Serial.read() == '\r')
    {
      if (axis == 0 )
      {
        tiltServo.write(degr);
      }
      else if (axis == 1)
      {
        panServo.write(degr);
      }
    }
  }
}
