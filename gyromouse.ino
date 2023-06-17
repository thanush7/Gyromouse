
#include <I2Cdev.h>
#include <Wire.h>
#include <MPU6050.h>
#include <Mouse.h>
MPU6050 mpu;
int16_t ax, ay, az, gx, gy, gz;
int vx, vy; const int button1= 4; 
const int button2 = 5;
int responseDelay = 10; void
setup() { pinMode(button1,
INPUT); pinMode(button2,
INPUT);
 Serial.begin(9600);
 Wire.begin();
Mouse.begin();
mpu.initialize();
if(!mpu.testConnection()) {
while (1);
 }
}
void loop() {
  mpu.getMotion6(&ax, &ay, &az,
&gx, &gy, &gz);
 vx = (gx - 400) / 200; 
 vy = -(gz - 200) / 200; // same here about "-200"
int buttonState1 = digitalRead(button1);
int buttonState2 = digitalRead(button2); 
if(buttonState1 == HIGH) {
 Mouse.press(MOUSE_LEFT);
 delay(100);
 Mouse.release(MOUSE_LEFT);
 delay(200); } 
 else if(buttonState2 == HIGH) {
Mouse.press(MOUSE_RIGHT);
 delay(100);
 Mouse.release(MOUSE_RIGHT);
 delay(200); }
 Mouse.move(vx, vy);
delay(20);
}
