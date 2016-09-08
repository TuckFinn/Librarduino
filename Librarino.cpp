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
Output::Output(int pin)
{
  pinMode(pin,OUTPUT);

  _pin = pin;
}

//Turns output on
void Output::On()
{
  digitalWrite(_pin,HIGH);
}

//Turns output off
void Output::Off()
{
  digitalWrite(_pin,LOW);
}

//Output waits in current state
void Output::Wait(int Time)
{
  delay(Time);
}

void Output::Pause(int Time)
{
  delay(Time);
}

//Output flashes on and off
void Output::Flash(int speedms){
  digitalWrite(_pin,HIGH);
  delay(abs(map(speedms,0,1000,-1000,0)));
  digitalWrite(_pin,LOW);
  delay(speedms);
}

//Set output brightness
void Output::Dim(int brightness){
  analogWrite(_pin, map(brightness,0,100,0,255));
}

//Output pulses on and off
void Output::Pulse(int speedms)
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
void Output::PulseUp(int speedms)
{
  for(int i = 0; i < 255; i = i + speedms){
    analogWrite(_pin, i);
    delay(20);
  }
}

//Output pulses down
void Output::PulseDown(int speedms)
{
  for(int i = 255; i > 0; i = i - speedms){
    analogWrite(_pin, i);
    delay(20);
  }
}

//Output plays note
void Output::Sing(int note)
{
  tone(_pin,note,200);
}


//Input Functions:

//Sets input pinMode
Input::Input(int pin){
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
int Input::Read(){
  if(_pin >= 14){
    analogRead(_pin);
  }
  else if(_pin <= 13){
    digitalRead(_pin);
  }
}

/*int Input::Print(){
  Serial.println(Input::Read());
}*/
