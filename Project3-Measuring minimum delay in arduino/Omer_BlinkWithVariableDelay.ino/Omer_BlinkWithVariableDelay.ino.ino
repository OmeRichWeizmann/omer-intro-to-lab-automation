/* This code will blink the LED in an adjusted manner
modified by: Omer Richmond, 
6.7.2025
*/

int pin_leg = 4;
int led_delay = 1;
void setup() {
  // put your setup code here, to run once:
pinMode(pin_leg,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(pin_leg,HIGH);
delay(led_delay);
digitalWrite(pin_leg,LOW);
delay(led_delay);
}
