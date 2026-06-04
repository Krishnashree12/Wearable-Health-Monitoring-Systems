#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

void setup() {
  Serial.begin(9600);
  Wire.begin();

  if (!mpu.testConnection()) {
    while (1);
  }
}

void loop() {
  int16_t ax, ay, az;

  mpu.getAcceleration(&ax, &ay, &az);

  Serial.print("Accel: ");
  Serial.print(ax);
  Serial.print(" ");

  Serial.print(ay);
  Serial.print(" ");

  Serial.println(az);

  delay(500);
}
