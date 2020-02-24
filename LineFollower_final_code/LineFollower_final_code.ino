//A simple Line Following robot 
// Author :- @Abhijeet_Kadam

#define LeftSensor 2         //left IR Sensor
#define RightSensor 3        //Right IR Sensor
#define CenterSensor 4       // Center IR Sensor
#define LeftForward 5
#define LeftBackward 10
#define RightForward 11
#define RightBackward 6

int var_speed = 180;         // Motor speed
void setup()
{
pinMode(LeftSensor, INPUT);
pinMode(RightSensor, INPUT);
pinMode(CenterSensor, INPUT);
pinMode(LeftForward, OUTPUT);
pinMode(LeftBackward, OUTPUT);
pinMode(RightForward, OUTPUT);
pinMode(RightBackward, OUTPUT);
}
void loop()
{
  if(!digitalRead(LeftSensor) && !digitalRead(RightSensor))//00
  {
    if(digitalRead(CenterSensor))                       
    {
      analogWrite(LeftForward, var_speed);
      analogWrite(RightForward, 0);
      analogWrite(LeftBackward, 0);
      analogWrite(RightBackward, var_speed);
    }
    else                                               
    {
      analogWrite(LeftForward, var_speed);
      analogWrite(RightForward, var_speed);
      analogWrite(LeftBackward, 0);
      analogWrite(RightBackward, 0);
    }
  }

  if(!digitalRead(LeftSensor) && digitalRead(RightSensor))//01
  {
    analogWrite(LeftForward, 0);
    analogWrite(RightForward, var_speed);
    analogWrite(LeftBackward, var_speed);
    analogWrite(RightBackward, 0);
  }

  if(digitalRead(LeftSensor) && !digitalRead(RightSensor))//10
  {
    analogWrite(LeftForward, var_speed);
    analogWrite(RightForward, 0);
    analogWrite(LeftBackward, 0);
    analogWrite(RightBackward, var_speed);
  }
  
  if(digitalRead(LeftSensor) && digitalRead(RightSensor))//11
  {
    analogWrite(LeftForward, var_speed);
    analogWrite(RightForward, var_speed);
    analogWrite(LeftBackward, 0);
    analogWrite(RightBackward, 0);
  }
}

