#include <MD_PWM.h>
#include <Servo.h>
Servo myServo;
int potentiometer_pin = A0; // Analog pin connected to the potentiometer
MD_PWM pwm(4);
int my_servopin = 7;             // PWM object for pin 4

void setup() {
  pinMode(potentiometer_pin, INPUT); // Set potentiometer pin as input
  pwm.begin(30);                     // Initialize PWM on pin 4 with 50 Hz frequency
  pwm.write(0);
  myServo.attach(my_servopin);                    // Start with 0% duty cycle (LED off)
  Serial.begin(9600);                // Initialize serial communication
}

void loop() {
  // Read the potentiometer value (0 to 1023)
  int pot_value = analogRead(potentiometer_pin);

  // Map the potentiometer value (0-1023) to a duty cycle (0-100)
  int duty_cycle = map(pot_value, 0, 1023, 0,255);
  int servo_angle = map(pot_value, 0, 1023, 0,179);
  // Set the PWM duty cycle to adjust LED brightness
  pwm.write(duty_cycle);
  myServo.write(servo_angle);
  delay(100);

  // Print the potentiometer value and duty cycle to the serial monitor
  Serial.print("Potentiometer Value: ");
  Serial.print(pot_value);
  Serial.print(" | Duty Cycle: ");
  Serial.println(duty_cycle);

  delay(100);}