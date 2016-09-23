/* 

Librarino.h - Librarino is an easy Arduino programming implementation for Valley of the Tetons Library’s STEAM education initiatives

Author: Tucker Tyler (t.tyler@valleyofthetetonslibrary.org)
Released into the public domain

*/

#ifndef Librarduino_h
#define Librarduino_h

#include<Arduino.h>
#include<pitches.h>

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
// GENERAL OUTPUT FUNCTIONS

  void ON();

  void OFF();

  void WAIT(int Time);

  void PAUSE(int Time);

  int PIN();

//LED SPECIFIC FUNCTIONS

  void FLASH(int speedms);

  void FLASHREPEAT(int speedms, int num);

  void DIM(int brightness);

  void PULSE(int speedms);

  void PULSEREPEAT(int speedms, int num);

  void PULSEUP(int speedms);

  void PULSEDOWN(int speedms);

// SPEAKER SPECIFIC FUNCTIONS

  void SING(int note = 440);

  void SINGSONG(int note1, int note2, int note3, int note4);


private:

int _pinD;

};


class TOGGLE
{
public:
  TOGGLE(int pin);
  
  int READ();

  void PRINT();

  void WAIT();

  int PIN();

  void LIGHT(DOER pin);

  void FLASH(DOER pin, int speedms = 10);

  void PULSE(DOER pin, int speedms = 10);

  void SING(DOER pin, int freq = 440);

private:
  int _pinT;
};

class SENSOR
{
public:
  SENSOR(int pin);

  int READ();

  void PRINT();

  int PIN();

  void LIGHT(DOER pin);

  void FLASH(DOER pin);

  void SING(DOER pin);

private:
  int _pinS;

};

#endif