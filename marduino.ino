/*

Author: Luca Pisoni
Date: 17/12/2012
Project Name: MArduino

*/

#include <SoftwareSerial.h> // Import library

SoftwareSerial BT(2, 3); // Use pins 2 and 3 as a RX and TX virtual

int serialread; // Initialize the variable serialread as char
int btread; // Initialize the variable btread as char
int serial; // Initialize the variable serial as char

void setup() {
BT.begin(9600); // Control Toy-Car
Serial.begin(9600); // Debug

if (init(11, 10, 6, 5)) {
Serial.println("All Right"); // Print on Serial
}
}

void loop() {
if (BT.available()) { // Check if BT data is available
btread = BT.read(); // Write read of BT on char
} else if (Serial.available()) { // Check if Serial data is available
serialread = Serial.read(); // Write read of Serial on char
}

if (btread != -1) { // Check if btread value is not -1
serial = btread; // Write value of btread in serial
Serial.end(); // If Serial is not used is disabled
} else { // Otherwise
serial = serialread; // Write value of serialread in serial
}

// Left
if (serial == 4) {
  	command(6, 5);
        Serial.println("Left");
}
// Right 
if (serial == 3) {
	command(5, 6);
        Serial.println("Right");
}
// Forward
if (serial == 2) {
	command(11, 10);
        Serial.println("Forward");
}
// Back
if (serial == 1) {
	command(10, 11);
        Serial.println("Back");
}
// Stop Left-Right
if (serial == 6) {
        stop(5, 6);
        Serial.println("Stop Left-Right");
}
// Stop Forward-Back
if (serial == 5) {
        stop(10, 11);
        Serial.println("Stop Forward-Back");
}
delay(33); // Wait 33 milliseconds
serial = -1; // Write -1 in serial
}
