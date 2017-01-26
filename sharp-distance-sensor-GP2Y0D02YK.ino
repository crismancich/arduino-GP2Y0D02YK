/*
SHARP Long Distance Measuring Sensor GP2Y0D02YK

Reads the digital sensor output to the pc console via serial output

 The circuit:
 * Sensor VCC to 5V
 * Sesnor GND to GND
 * Sensor VO to digital pin 7
 
 Library originally added 2017-01-26
 by Boris Crismancich

 This example code is in the public domain.

 */

const int inputPin = 7;
long pulseWidth, cm;

void setup() {
  // Open a serial connection to return the values to the pc console
  Serial.begin(9600);
}
void loop() {

  // Inititalize the pin as an input pin
  pinMode(inputPin, INPUT);
  
  // Measure the duration of the pulse from the sensor output
  pulseWidth = pulseIn(inputPin, HIGH);
  
  //Use a scale factor to convert the duration to distance in cm
  cm = pulseWidth/147;

  // Output the value to the pc console
  Serial.print(pulseWidth);
  Serial.println();
  Serial.print(cm);
  Serial.println();

  // Wait for 1 milliseconds
  delay(1);
}
