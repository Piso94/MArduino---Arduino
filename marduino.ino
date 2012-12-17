/*

Author: Luca Pisoni
Date: 17/12/2012
Project Name: MArduino

*/

#include <SoftwareSerial.h> // Import library

SoftwareSerial BT(2, 3); // Use pins 2 and 3 as a RX and TX virtual

char serialread; // Initialize the variable serialread as char
char btread; // Initialize the variable btread as char
char serial; // Initialize the variable serial as char

void setup() {
BT.begin(9600); // Control Toy-Car
Serial.begin(9600); // Debug

pinMode(5, OUTPUT); // Set pin 5 as OUTPUT
pinMode(6, OUTPUT); // Set pin 6 as OUTPUT
pinMode(10, OUTPUT); // Set pin 10 as OUTPUT
pinMode(11, OUTPUT); // Set pin 11 as OUTPUT

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

if (btread != '') {
serial = btread;
} else {
serial = serialread;
}

// Left
if (serial == 'L') {
  	digitalWrite(5, LOW); // Set pin 5 as LOW
	digitalWrite(6, HIGH); // Set pin 6 as HIGH
}
// Right 
if (serial == 'R') {
	digitalWrite(5, HIGH); // Set pin 5 as HIGH
	digitalWrite(6, LOW); // Set pin 6 as LOW
}
// Forward
if (serial == 'F') {
	digitalWrite(10, LOW); // Set pin 10 as LOW
	digitalWrite(11, HIGH); // Set pin 11 as HIGH
}
// Back
if (serial == 'B') {
	digitalWrite(10, HIGH); // Set pin 10 as HIGH
	digitalWrite(11, LOW); // Set pin 11 as LOW
}
// Stop Left-Right
if (serial == 'D') {
        digitalWrite(5, HIGH); // Set pin 5 as HIGH
        digitalWrite(6, HIGH); // Set pin 6 as HIGH
}
// Stop Forward-Back
if (serial == 'P') {
        digitalWrite(10, HIGH); // Set pin 10 as HIGH
        digitalWrite(11, HIGH); // Set pin 11 as HIGH
}
delay(10); // Wait 10 milliseconds
}

