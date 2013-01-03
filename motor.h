/*

Author: Luca Pisoni
Date: 17/12/2012
File Name: motor.h
What it does: Includes basic commands to use the chip

*/

bool init (int fpin, int bpin, int lpin, int rpin) {
  pinMode (fpin,OUTPUT);
  pinMode (bpin,OUTPUT);
  pinMode (lpin,OUTPUT);
  pinMode (rpin,OUTPUT);

  return true;
}

void command (int pinHIGH, int pinLOW) {
  digitalWrite(pinHIGH, HIGH);
  digitalWrite(pinLOW, LOW); 
}


