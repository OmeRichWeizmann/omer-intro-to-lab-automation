/* This code will blink the LED in an adjusted manner
modified by: Omer Richmond, 
6.7.2025
*/
int ayel_cham = 2;
int led_delay = 1;

void setup() {
  // put your setup code here, to run once:
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  PORTB |= (1 << PB4) | (1 << PB5); // Set pins 12 and 13 HIGH simultaneously
  ayel_cham = ayel_cham + 1;
  delay(led_delay);
  PORTB &= ~((1 << PB4) | (1 << PB5)); // Set pins 12 and 13 LOW simultaneously
  ayel_cham = ayel_cham + 1;
  delay(led_delay);
}