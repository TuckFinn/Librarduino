/* 

Librarino.h - Librarino is an easy Arduino programming implementation for Valley of the Tetons Library’s STEAM education initiatives

Author: Tucker Tyler (t.tyler@valleyofthetetonslibrary.org)
Released into the public domain

*/

#ifndef Librarino_h
#define Librarino_h

#include<Arduino.h>

//Constants Here:

#define A0 14
#define A1 15
#define A2 16
#define A3 17
#define A4 18
#define A5 19

//Functions Here:

class DOER

{
public:
  DOER(int pin);

  void ON();

  void OFF();

  void WAIT(int Time);

  void PAUSE(int Time);

  void FLASH(int speedms);

  void PULSE(int speedms);

  void PULSEUP(int speedms);

  void PULSEDOWN(int speedms);

  void SING(int note);

  void DIM(int brightness);

private:

int _pin;

};


class TOGGLE
{
public:
  TOGGLE(int pin);

  //int Check();
  
  int READ();

  //Print input value
  int PRINT(){
    Serial.println(READ());
  }

private:
  int _pin;
};

class SENSOR
{
public:
  SENSOR(int pin);

  int READ();

  int PRINT(){
    Serial.println(READ());
  }

private:
  int _pin;

};

#endif