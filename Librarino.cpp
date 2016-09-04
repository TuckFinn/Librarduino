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

Output::Output(int pin)
{
  pinMode(pin,OUTPUT);

  _pin = pin;
}

void Output::On()
{
  digitalWrite(_pin,HIGH);
}

void Output::Off()
{
  digitalWrite(_pin,LOW);
}

void Output::Wait(int Time)
{
  delay(Time);
}

void Output::Flash(int speed){
  digitalWrite(_pin,HIGH);
  delay(speed);
  digitalWrite(_pin,LOW);
  delay(speed);
}

void Output::Pulse(int speed)
{
  for(int i = 0; i <= 255; i += speed){
    analogWrite(_pin, i);
  }
  for(int i = 255; i >= 0; i -= speed){
    analogWrite(_pin, i);
  }
}

void Output::Sing(int note)
{
  tone(_pin,note,200);
}



//Input Functions:


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

int Input::Check(){
  digitalRead(_pin);
}

int Input::Read(){
  analogRead(_pin);
}

/*int Input::Print(){
  Serial.println(Input::Read());
}*/
