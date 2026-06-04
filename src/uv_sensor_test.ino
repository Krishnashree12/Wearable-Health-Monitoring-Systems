#define UV_SENSOR_PIN A0

void setup() {
  Serial.begin(9600);
}

void loop() {
  int uvAnalog = analogRead(UV_SENSOR_PIN);

  float uvVoltage = uvAnalog * (5.0 / 1023.0);

  Serial.print("UV Analog Value: ");
  Serial.print(uvAnalog);

  Serial.print(" | Voltage: ");
  Serial.print(uvVoltage);

  Serial.println(" V");

  delay(1000);
}
