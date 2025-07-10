#include "Arduino_SensorKit.h"
#include <Servo.h> 
Servo myServo;
int accelX = 0;
const int dc_driver = 3; 
const int servo_pin = 7;
cont int buzzer_pin = 5;   
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial);
  Accelerometer.begin();
  myServo.attach(servo_pin);
  pinMode(dc_driver, OUTPUT);
  Oled.begin(); // Start the OLED display
  Oled.setFlipMode(true); // Flip the display if needed (optional)
  Oled.setFont(u8x8_font_chroma48medium8_r);
}

void loop() {
  // put your main code here, to run repeatedly:
  // 3 axis
  buzzer_state = digitalRead(buzzer_pin);
  digitalWrite(dc_driver, HIGH);
  Serial.print("x:"); 
  Serial.print(Accelerometer.readX());
  accelX = Accelerometer.readX(); // Read the X-axis acceleration
  int servoAngle = map(accelX * 100, -100, 100, 0, 180); 
  myServo.write(servoAngle); // Map the acceleration to servo angle
  Serial.print("  ");
  Serial.print("y:"); 
  Serial.print(Accelerometer.readY());        
  Serial.print("  ");
  Serial.print("z:"); 
  Serial.println(Accelerometer.readZ());
  Oled.clear(); // Clear the OLED display
  Oled.setCursor(0, 0);
  Oled.print("The servo angle is: "); // Set cursor to the top-left corner
  Oled.print(servoAngle); // Display a label
  Oled.setCursor(0,2);
  Oled.print("The buzzer state is: ");
  Oled.print(buzzer_state);

}
