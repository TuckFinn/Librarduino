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

class Output

{
public:
  Output(int pin);

  void On();

  void Off();

  void Wait(int Time);

  void Pause(int Time)

  void Flash(int speedms);

  void Pulse(int speedms);

  void PulseUp(int speedms);

  void PulseDown(int speedms);

  void Sing(int note);

  void Dim(int brightness);

private:

int _pin;

};


class Input
{
public:
  Input(int pin);

  //int Check();
  
  int Read();
  
  int Print(){
    Serial.println(Read());
  }

private:
  int _pin;
};

#endif