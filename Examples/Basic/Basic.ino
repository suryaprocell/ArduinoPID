#include <PID.h>
#include <encoder1.h>
#include <Servo.h>

encoder myencoder(3,4); // pin 3 , pin 4

Servo myservo;
int centerServo = 90;

PID myPID(2,0,2); // KP, KI, KD

String string;
char karakter;

double setpoint,input,pwm;

void setup()
{
  Serial.begin(115200);
  myservo.attach(7); 
  myPID.LimitP(6,-6); //Pmax , Pmin
  myPID.LimitI(0,0); //Imax , Imin
}

void loop()
{
  cek_serial();
  input = myencoder.baca();
  pwm = centerServo + myPID.Calculate(setpoint, input);
  myservo.write(pwm);
  //myservo.writeMicroseconds(pwm);
   
  Serial.print("setpoint: ");
  Serial.print(setpoint);
  Serial.print(" encoder: ");
  Serial.print(input);
  Serial.print(" error: ");
  Serial.print(setpoint-input);
  Serial.print(" pwm: ");
  Serial.println(pwm);
}

void cek_serial()
{
  while(Serial.available())
  {
    karakter = Serial.read();
    if(karakter != '\n')
    {
      string += karakter;
    }
    else
    {
      setpoint = string.substring(0).toInt();
      string = "";
    }
  }
}

