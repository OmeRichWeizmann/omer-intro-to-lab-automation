int interruptPin = 2; // Pin 2 will act as the interrupt pin
int led_pin = 4;
int button_pin = 6;
volatile bool ledState = false;
int startTime = 0; 
int current_time = 0;
#include <MsTimer2.h>
void setup() {
  pinMode(interruptPin, INPUT_PULLUP); // Configure pin 2 as input with pull-up resistor
  pinMode(led_pin, OUTPUT); // Configure pin 13 as output (for LED)
  pinMode(button_pin, INPUT);
  // Attach interrupt to pin 2, triggering on FALLING edge
  attachInterrupt(digitalPinToInterrupt(interruptPin), toggleLED, RISING);
  MsTimer2::set(30, turnOffLED);
  Serial.begin(9600); // Initialize serial communication
}

void loop() {
    for (int i = 0; i< 10000; i++){
    Serial.println("calculating...");
    }
}

// Interrupt Service Routine (ISR)
// This function is triggered when the interrupt pin detects a change edge
void toggleLED() {
   
  ledState = !ledState; // Toggle the boolean value
  digitalWrite(led_pin, ledState); // Update the LED state
  MsTimer2::start(); 
}
void turnOffLED() {
  digitalWrite(led_pin, LOW); // Turn off the LED
  ledState = false;
  MsTimer2::stop();           // Stop the timer
}