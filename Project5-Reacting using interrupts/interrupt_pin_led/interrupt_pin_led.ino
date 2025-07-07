int interruptPin = 2; // Pin 2 will act as the interrupt pin
int led_pin = 4;
int button_pin = 6;
volatile bool ledState = false;
void setup() {
  pinMode(interruptPin, INPUT_PULLUP); // Configure pin 2 as input with pull-up resistor
  pinMode(led_pin, OUTPUT); // Configure pin 13 as output (for LED)
  pinMode(button_pin, INPUT);
  // Attach interrupt to pin 2, triggering on FALLING edge
  attachInterrupt(digitalPinToInterrupt(interruptPin), toggleLED, CHANGE);

  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  // Simulate a long process to emphasize the benefit of interrupts
  for (int i = 0; i < 10000; i++) {
    Serial.println("Simulating a long process...");
  }

  
}

// Interrupt Service Routine (ISR)
// This function is triggered when the interrupt pin detects a change edge
void toggleLED() {
  ledState = !ledState; // Toggle the boolean value
  digitalWrite(led_pin, ledState); // Update the LED state
}