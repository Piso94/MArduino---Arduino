/*

Author: Luca Pisoni
Date: 07/01/2013
File Name: motor.h
What it does: Includes basic commands to use the chip

*/

#ifndef MOTOR_H
#define MOTOR_H

#include "Arduino.h"

class MOTOR
{
   private:

   public:
      bool init (byte fpin, byte bpin, byte lpin, byte rpin);
      void command (byte pinHIGH, byte pinLOW);
      void stops (byte pinHIGH, byte pinHIGHS);
};

#endif
