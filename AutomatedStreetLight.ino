#include <Wire.h>
#include <TimeLib.h>
#include <DS1307RTC.h>
//----------PIR sensor----------//
int pirSensor = 8;
int relayInput = 7;
//----------timer----------//
int timeRelay = 4;

 tmElements_t t;
 
const int OnHour = 06;
const int OnMin = 00;
const int OffHour = 06;
const int OffMin = 01;

void setup(){
  Serial.begin(9600);

  pinMode(timeRelay,OUTPUT);
  digitalWrite(timeRelay,LOW);
  pinMode(pirSensor,INPUT);
  pinMode(relayInput,OUTPUT);
}

void loop(){
  Serial.print(t.Hour);
  Serial.print(" : ");
  Serial.print(t.Minute);
  Serial.print(" : ");
  Serial.println("  ");
  delay(2000);
  if(t.Hour == OnHour && t.Minute == OnMin){
    digitalWrite(timeRelay,HIGH);
    Serial.println("Light is on");
  }
  else if(t.Hour == OffHour && t.Minute == OffMin){
    digitalWrite(timeRelay,LOW);
    Serial.println("Light is off");
  }
  int sensorValue = digitalRead(pirSensor);
  if(sensorValue == 1){
    digitalWrite(relayInput,LOW);
  }
  
}
