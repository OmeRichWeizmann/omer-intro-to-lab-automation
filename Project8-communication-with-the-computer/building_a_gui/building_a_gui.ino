#include <MsTimer2.h>

const int ledPin = 4;          // Pin connected to the LED
const int buttonPin = 2;       // Pin connected to the button (interrupt pin)
volatile bool ledState = false; // Tracks the LED state
volatile bool buttonPressed = false; // Tracks if the button was pressed
unsigned long timerDuration = 1000;  // Default timer duration in milliseconds

void setup() {
  pinMode(ledPin, OUTPUT);          // Set LED pin as output
  pinMode(buttonPin, INPUT_PULLUP); // Set button pin as input with pull-up resistor
  Serial.begin(9600);               // Initialize serial communication

  // Attach interrupt to the button pin, triggering on FALLING edge
  attachInterrupt(digitalPinToInterrupt(buttonPin), handleButtonPress, FALLING);

  // Initialize MsTimer2 with a dummy duration (will be updated dynamically)
  MsTimer2::set(1000, turnOffLED);
}

void loop() {
  // Check for incoming serial data
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n'); // Read input until newline character
    timerDuration = input.toInt();              // Convert input to integer
    if (timerDuration > 0) {
      Serial.print("I received: ");
      Serial.println(timerDuration);
      timerDuration += 1; // Add 1 ms to account for the bug in project 6
    } else {
      Serial.println("Invalid input. Please send a positive number.");
    }
  }

  // If the button was pressed, start the timer
  if (buttonPressed) {
    buttonPressed = false; // Reset the flag
    ledState = true;       // Turn on the LED
    digitalWrite(ledPin, HIGH);
    MsTimer2::set(timerDuration, turnOffLED); // Set the timer duration
    MsTimer2::start();                        // Start the timer
  }
}

// Interrupt Service Routine (ISR) for button press
void handleButtonPress() {
  buttonPressed = true; // Set the flag to indicate the button was pressed
}

// Function to turn off the LED when the timer expires
void turnOffLED() {
  digitalWrite(ledPin, LOW); // Turn off the LED
  ledState = false;          // Update the LED state
  MsTimer2::stop();          // Stop the timer
}