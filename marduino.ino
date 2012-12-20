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

pinMode(5, OUTPUT); // Set pin 5 as OUTPUT
pinMode(6, OUTPUT); // Set pin 6 as OUTPUT
pinMode(10, OUTPUT); // Set pin 10 as OUTPUT
pinMode(11, OUTPUT); // Set pin 11 as OUTPUT

Serial.println("All Right"); // Print on Serial
}

void loop() {
if (BT.available()) { // Check if BT data is available
btread = BT.read(); // Write read of BT on char
} else if (Serial.available()) { // Check if Serial data is available
serialread = Serial.read(); // Write read of Serial on char
}

if (btread != -1) {
serial = btread;
} else {
serial = serialread;
}

// Left
if (serial == 4) {
  	digitalWrite(5, LOW); // Set pin 5 as LOW
	digitalWrite(6, HIGH); // Set pin 6 as HIGH
        Serial.println("Left");
}
// Right 
if (serial == 3) {
	digitalWrite(5, HIGH); // Set pin 5 as HIGH
	digitalWrite(6, LOW); // Set pin 6 as LOW
        Serial.println("Right");
}
// Forward
if (serial == 2) {
	digitalWrite(10, LOW); // Set pin 10 as LOW
	digitalWrite(11, HIGH); // Set pin 11 as HIGH
        Serial.println("Forward");
}
// Back
if (serial == 1) {
	digitalWrite(10, HIGH); // Set pin 10 as HIGH
	digitalWrite(11, LOW); // Set pin 11 as LOW
        Serial.println("Back");
}
// Stop Left-Right
if (serial == 6) {
        digitalWrite(5, HIGH); // Set pin 5 as HIGH
        digitalWrite(6, HIGH); // Set pin 6 as HIGH
        Serial.println("Stop Left-Right");
}
// Stop Forward-Back
if (serial == 5) {
        digitalWrite(10, HIGH); // Set pin 10 as HIGH
        digitalWrite(11, HIGH); // Set pin 11 as HIGH
        Serial.println("Stop Forward-Back");
}
delay(10); // Wait 10 milliseconds
serial = -1;
}
