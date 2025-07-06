/* This code will blink the LED in an adjusted manner
modified by: Omer Richmond, 
6.7.2025
*/
int ayel_cham = 2;
int pin_leg = 12;
int pin_leg2 = 13;
int led_delay = 1;
void setup() {
  // put your setup code here, to run once:
pinMode(pin_leg,OUTPUT);
pinMode(pin_leg2,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(pin_leg,HIGH);
ayel_cham = ayel_cham+1;
digitalWrite(pin_leg2,HIGH);
delay(led_delay);
digitalWrite(pin_leg,LOW);
ayel_cham = ayel_cham+1;
digitalWrite(pin_leg2,LOW);
delay(led_delay);
}
