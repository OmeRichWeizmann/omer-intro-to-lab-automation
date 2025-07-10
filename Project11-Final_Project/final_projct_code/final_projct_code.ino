#include "Arduino_SensorKit.h"
#include <Servo.h> 
Servo myServo;
int accelX = 0;
const int dc_driver = 3; 
const int servo_pin = 7;
const int buzzer_pin = 5;
bool buzzer_state = false; 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial);
  Accelerometer.begin();
  myServo.attach(servo_pin);
  pinMode(dc_driver, OUTPUT);
  pinMode(buzzer_pin, OUTPUT);
  Oled.begin(); // Start the OLED display
  Oled.setFlipMode(true); // Flip the display if needed (optional)
  Oled.setFont(u8x8_font_chroma48medium8_r);
}

void loop() {
  // put your main code here, to run repeatedly:
  // 3 axis
  
  digitalWrite(dc_driver, HIGH);
  accelX = Accelerometer.readX(); // Read the X-axis acceleration
  int servoAngle = map(accelX * 100, -100, 100, 0, 180);
if (servoAngle > 120) {
  analogWrite(buzzer_pin, HIGH);
  digitalWrite(dc_driver,LOW);
  buzzer_state  = true;
} else if (servoAngle < 119) {
  analogWrite(buzzer_pin, LOW);
  digitalWrite(dc_driver,HIGH);
  buzzer_state  = false;
}
  unsigned long currentTime = millis(); // Time since program start in milliseconds
  Serial.print(currentTime); // Log time
  Serial.print(","); // CSV separator
  Serial.print(servoAngle); // Log servo angle
  Serial.print(","); // CSV separator
  Serial.println(buzzer_state);

  myServo.write(servoAngle); // Map the acceleration to servo angle
  Oled.clear(); // Clear the OLED display
  Oled.setCursor(0, 0);
  Oled.print("Servo angle: "); // Set cursor to the top-left corner
  Oled.print(servoAngle); // Display a label
  Oled.setCursor(0,2);
  Oled.print("Buzzer state: ");
  Oled.print(buzzer_state);

}
