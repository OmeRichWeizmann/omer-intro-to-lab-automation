  int button_pin = 6;
  int led_pin = 4;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Define pin numbers

  // Set pin modes
  pinMode(button_pin, INPUT);
  pinMode(led_pin, OUTPUT);
}

void loop() {
  // Read the button state
  int button_val = digitalRead(button_pin);
  for (int i = 0; i< 10000; i++){
    Serial.println("calculating...");
}

  // If the button is pressed (HIGH)
  while (button_val == HIGH) {
    digitalWrite(led_pin, HIGH); // Turn on the LED
    button_val = digitalRead(button_pin); // Update button state
    Serial.println(button_val);
    delay(1000);
  }

  // Turn off the LED when the button is released
  digitalWrite(led_pin, LOW);
  Serial.println(button_val);
  delay(1000);
}