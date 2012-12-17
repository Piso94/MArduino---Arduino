/*

Author: Luca Pisoni
Date: 17/12/2012
Project Name: MArduino

*/

#include <SoftwareSerial.h> // Import library

SoftwareSerial BT(2, 3); // Use pins 2 and 3 as a RX and TX virtual

char serialread; // Initialize the variable serialread as char
char btread; // Initialize the variable btread as char

void setup() {
BT.begin(9600); // Control Toy-Car
Serial.begin(9600); // Debug

Serial.println("All Right!"); // Print on Serial
}

void loop() {
if (BT.available()) { // Check if BT data is available
btread = BT.read(); // Write read of BT on char
} else if (Serial.available()) { // Check if Serial data is available
serialread = Serial.read(); // Write read of Serial on char
} else { // Otherwise
setup(); // Return to setup
}


}

