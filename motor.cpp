/*

Author: Luca Pisoni
Date: 07/01/2013
File Name: motor.cpp
What it does: Includes basic commands to use the chip

*/

#include "motor.h"

bool MOTOR::init (byte fpin, byte bpin, byte lpin, byte rpin) {
  pinMode (fpin,OUTPUT);
  pinMode (bpin,OUTPUT);
  pinMode (lpin,OUTPUT);
  pinMode (rpin,OUTPUT);

  return true;
}

void MOTOR::command (byte pinHIGH, byte pinLOW) {
  digitalWrite(pinHIGH, HIGH);
  digitalWrite(pinLOW, LOW); 
}

void MOTOR::stops (byte pinHIGH, byte pinHIGHS) {
  digitalWrite(pinHIGH, HIGH);
  digitalWrite(pinHIGHS, HIGH);
}
