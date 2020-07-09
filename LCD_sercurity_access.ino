#include <LiquidCrystal.h>
#define pirSensor 13
LiquidCrystal lcd(12,11,5,4,3,2);

const int switchPin = 6;
int switchState = 0;
int prevSwitchState = 0;
int reply;

int reading;

void setup() {
  // put your setup code here, to run once:
lcd.begin(16,2);
pinMode(switchPin,INPUT);
lcd.print("Type Access Code:");

pinMode(pirSensor, INPUT);
Serial.begin(9600);

}

void loop() {

reading = digitalRead(pirSensor);

if(reading == HIGH)
{
  Serial.println("Motion");
  lcd.clear();
  lcd.print("Motion");
}else{
  Serial.println("0");
  lcd.print("Type Access Code:");
}
  
  // put your main code here, to run repeatedly:
  switchState = digitalRead(switchPin);

  if(switchState != prevSwitchState)
  {
    if(switchState == LOW)
    {
      reply = random(8);
    }
  }
}
