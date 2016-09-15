// Librarino.cpp
//
// Librarino Programming Aid for Arduino IDE
//
// Author: Tucker Tyler (t.tyler@valleyofthetetonslibrary.org)
// Copyright (C) 2016 Tucker Tyler
// $Id: Funduino.cpp,v 1.0 2016/08/31$

#include<Arduino.h>
#include<Librarduino.h>


//Output Functions:

//Sets PinMode
DOER::DOER(int pin)
{
  pinMode(pin,OUTPUT);

  _pin = pin;
}

//Turns output on
void DOER::ON()
{
  digitalWrite(_pin,HIGH);
}

//Turns output off
void DOER::OFF()
{
  digitalWrite(_pin,LOW);
}

//Output waits in current state
void DOER::WAIT(int Time)
{
  delay(Time);
}

void DOER::PAUSE(int Time)
{
  delay(Time);
}

//Output flashes on and off
void DOER::FLASH(int speedms){
  digitalWrite(_pin,HIGH);
  delay(2000/speedms);
  digitalWrite(_pin,LOW);
  delay(2000/speedms);
}

void DOER::FLASHREPEAT(int speedms, int num){
  for(int i = 0; i < num; i++){
    digitalWrite(_pin,HIGH);
    delay(2000/speedms);
    digitalWrite(_pin,LOW);
    delay(2000/speedms);
  }
}

//Set output brightness
void DOER::DIM(int brightness){
  analogWrite(_pin, map(brightness,0,100,0,255));
}

//Output pulses on and off
void DOER::PULSE(int speedms)
{
  for(int i = 0; i < 255; i = i + speedms){
    analogWrite(_pin, i);
    delay(20);
  }
  for(int i = 255; i > 0; i = i - speedms){
    analogWrite(_pin, i);
    delay(20);
  }
  digitalWrite(_pin, LOW);
}

void DOER::PULSEREPEAT(int speedms, int num){
  for(int i = 0; i < num; i++){
    for(int i = 0; i < 255; i = i + speedms){
    analogWrite(_pin, i);
    delay(20);
  }
  for(int i = 255; i > 0; i = i - speedms){
    analogWrite(_pin, i);
    delay(20);
  }
  digitalWrite(_pin, LOW);
  }
}

//Output pulses up
void DOER::PULSEUP(int speedms)
{
  for(int i = 0; i < 255; i = i + speedms){
    analogWrite(_pin, i);
    delay(20);
  }
}

//Output pulses down
void DOER::PULSEDOWN(int speedms)
{
  for(int i = 255; i > 0; i = i - speedms){
    analogWrite(_pin, i);
    delay(20);
  }
}

//Output plays note
void DOER::SING(int note){
  tone(_pin,note,200);
}

int DOER::PIN(){
  return _pin;
}


//Input Functions:

//Sets input pinMode
TOGGLE::TOGGLE(int pin){
  Serial.begin(9600);
  if(pin <= 13){
    pinMode(pin, INPUT_PULLUP);
    _pin = pin;
  }
  else{
    _pin = pin;
  }
}

//Get digital value
/*int Input::Check(){
  digitalRead(_pin);
}*/

//Get analog value
int TOGGLE::READ(){
  digitalRead(_pin);
}

void TOGGLE::PRINT(){
    Serial.println(READ());
  }

void TOGGLE::LIGHT(DOER pin){
  if (READ() == 1){
    digitalWrite(pin.PIN(),LOW);
  }
  else{
    digitalWrite(pin.PIN(),HIGH);
  }
}

void TOGGLE::SING(DOER pin, int freq = 440){
  if (digitalRead(pin.PIN()) == 0){
    tone(pin.PIN(), freq, 200);
  }
}

/*int Input::Print(){
  Serial.println(Input::Read());
}*/

SENSOR::SENSOR(int pin){
  _pin = pin;
}

int SENSOR::READ(){
  analogRead(_pin);
}

void SENSOR::PRINT(){
    Serial.println(READ());
  }

void SENSOR::LIGHT(DOER pin){
  int val = analogRead(_pin);
  val = map(val, 0, 1023, 0, 255);
  analogWrite(pin.PIN(),val);
}

void SENSOR::SING(DOER pin){
  int val = analogRead(PIN());
  val = map(val, 0, 1023, 200, 500);
  tone(pin.PIN(), val, 200);
}
