// This file is meant to test and aquire pwm values for adjusting your main code.
// Written by Nnamdi Monwe 3/17/2019
// Courtesy of Wayne Robotics Club

byte pwm_pin1 = 2; // signal input from receiver (add as many channels as needed)
 
int pwm_value;
 
void setup() {
  pinMode(pwm_pin1, INPUT);
  Serial.begin(115200); // open seral monitor and set to this baud rate 
}
 
void loop() {
  pwm_value = pulseIn(pwm_pin1, HIGH);
  Serial.println(pwm_value);
}
