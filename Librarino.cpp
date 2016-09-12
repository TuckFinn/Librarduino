// Librarino.cpp
//
// Librarino Programming Aid for Arduino IDE
//
// Author: Tucker Tyler (t.tyler@valleyofthetetonslibrary.org)
// Copyright (C) 2016 Tucker Tyler
// $Id: Funduino.cpp,v 1.0 2016/08/31$

#include<Arduino.h>
#include<Librarino.h>


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
  delay(abs(map(speedms,0,1000,-1000,0)));
  digitalWrite(_pin,LOW);
  delay(speedms);
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
void DOER::SING(int note)
{
  tone(_pin,note,200);
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

/*int Input::Print(){
  Serial.println(Input::Read());
}*/

SENSOR::SENSOR(int pin){
  _pin = pin;
}

int SENSOR::READ(){
  analogRead(_pin);
}

