// Librarino.cpp
//
// Librarino Programming Aid for Arduino IDE
//
// Author: Tucker Tyler (t.tyler@valleyofthetetonslibrary.org)
// Copyright (C) 2016 Tucker Tyler
// $Id: Funduino.cpp,v 1.0 2016/08/31$

#include<Arduino.h>
#include<pitches.h>
#include<Librarduino.h>


//Output Functions:

//Sets PinMode
DOER::DOER(int pin)
{
  pinMode(pin,OUTPUT);

  _pinD = pin;
}

//Turns output on
void DOER::ON()
{
  digitalWrite(_pinD,HIGH);
}

//Turns output off
void DOER::OFF()
{
  digitalWrite(_pinD,LOW);
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
  digitalWrite(_pinD,HIGH);
  delay(2000/speedms);
  digitalWrite(_pinD,LOW);
  delay(2000/speedms);
}

void DOER::FLASHREPEAT(int speedms, int num){
  for(int i = 0; i < num; i++){
    digitalWrite(_pinD,HIGH);
    delay(2000/speedms);
    digitalWrite(_pinD,LOW);
    delay(2000/speedms);
  }
}

//Set output brightness
void DOER::DIM(int brightness){
  analogWrite(_pinD, map(brightness,0,100,0,255));
}

//Output pulses on and off
void DOER::PULSE(int speedms)
{
  for(int i = 0; i < 255; i = i + speedms){
    analogWrite(_pinD, i);
    delay(20);
  }
  for(int i = 255; i > 0; i = i - speedms){
    analogWrite(_pinD, i);
    delay(20);
  }
  digitalWrite(_pinD, LOW);
}

void DOER::PULSEREPEAT(int speedms, int num){
  for(int i = 0; i < num; i++){
    for(int i = 0; i < 255; i = i + speedms){
    analogWrite(_pinD, i);
    delay(20);
    }
    for(int i = 255; i > 0; i = i - speedms){
      analogWrite(_pinD, i);
      delay(20);
    }
  digitalWrite(_pinD, LOW);
  }
}

//Output pulses up
void DOER::PULSEUP(int speedms)
{
  for(int i = 0; i < 255; i = i + speedms){
    analogWrite(_pinD, i);
    delay(20);
  }
}

//Output pulses down
void DOER::PULSEDOWN(int speedms)
{
  	for(int i = 255; i > 0; i = i - speedms){
    	analogWrite(_pinD, i);
  		delay(20);
  	}
}

//Output plays note
void DOER::SING(int note){
  	tone(_pinD,note,200);
}

void DOER::SINGSONG(int note1, int note2, int note3, int note4){
	tone(_pinD,note1,250);
	delay(10);
	tone(_pinD,note2,250);
	delay(10);
	tone(_pinD,note3,250);
	delay(10);
	tone(_pinD,note4,250);
	delay(10);
}

int DOER::PIN(){
  return _pinD;
}


//Input Functions:

//Sets input pinMode
TOGGLE::TOGGLE(int pin){
  Serial.begin(9600);
  pinMode(pin, INPUT_PULLUP);
  _pinT = pin;
}

//Get digital value
/*int Input::Check(){
  digitalRead(_pin);
}*/

//Get analog value
int TOGGLE::READ(){
  digitalRead(_pinT);
}

void TOGGLE::PRINT(){
    Serial.println(READ());
  }

void TOGGLE::WAIT(){
	while (digitalRead(_pinT) == 1){
		delay(1);
	}
}

void TOGGLE::LIGHT(DOER pin){
  	if (digitalRead(_pinT) == 0){
    	digitalWrite(pin.PIN(), HIGH);
  	}
  	else{
    	digitalWrite(pin.PIN(),LOW);
  	}
}

void TOGGLE::FLASH(DOER pin, int speedms){
	if (digitalRead(_pinT) == 0){
		digitalWrite(pin.PIN(),HIGH);
		digitalWrite(pin.PIN(),HIGH);
  		delay(2000/speedms);
  		digitalWrite(pin.PIN(),LOW);
  		delay(2000/speedms);
	}
}

void TOGGLE::FLASHREPEAT(DOER pin, int speedms, int num){
  if (digitalRead(_pinT) == 0){
    for(int i = 0; i < num; i++){
    digitalWrite(pin.PIN(),HIGH);
    delay(2000/speedms);
    digitalWrite(pin.PIN(),LOW);
    delay(2000/speedms);
    }
  }
}

void TOGGLE::PULSE(DOER pin, int speedms){
	if (digitalRead(_pinT) == 0){
		for(int i = 0; i < 255; i = i + speedms){
    		analogWrite(pin.PIN(), i);
    		delay(20);
  		}
  		for(int i = 255; i > 0; i = i - speedms){
    		analogWrite(pin.PIN(), i);
    		delay(20);
  		}
  		digitalWrite(pin.PIN(), LOW);
	}
}

void TOGGLE::PULSEREPEAT(DOER pin, int speedms, int num){
  if (digitalRead(_pinT) == 0){
    for(int i = 0; i < num; i++){
      for(int i = 0; i < 255; i = i + speedms){
        analogWrite(pin.PIN(), i);
        delay(20);
      }
      for(int i = 255; i > 0; i = i - speedms){
      analogWrite(pin.PIN(), i);
      delay(20);
      }
      digitalWrite(pin.PIN(), LOW);
    }
  }
}

void TOGGLE::SING(DOER pin, int freq){

	if (digitalRead(_pinT) == 0){
    	tone(pin.PIN(), freq, 200);
  	}
}

/*int Input::Print(){
  Serial.println(Input::Read());
}*/

SENSOR::SENSOR(int pin){
  _pinS = pin;
}

int SENSOR::READ(){
  analogRead(_pinS);
}

void SENSOR::PRINT(){
    Serial.println(READ());
  }

void SENSOR::LIGHT(DOER pin){
  int val = map(analogRead(A0), 250, 950, -255, 0);
  analogWrite(pin.PIN(),abs(val));
}

void SENSOR::FLASH(DOER pin){
	int val = map(analogRead(A0), 250, 950, 0, 100);
	digitalWrite(pin.PIN(),HIGH);
	delay(2000/val);
	digitalWrite(pin.PIN(),LOW);
	delay(2000/val);
}

void SENSOR::SING(DOER pin){
  int val = analogRead(_pinS);
  val = map(val, 0, 1023, 200, 500);
  tone(pin.PIN(), val, 200);
}
