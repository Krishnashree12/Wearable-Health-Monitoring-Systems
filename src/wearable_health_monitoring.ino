#define BLYNK_TEMPLATE_ID "YOUR_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "Wearable Health Monitoring System"
#define BLYNK_AUTH_TOKEN "YOUR_BLYNK_AUTH_TOKEN"

#include <Wire.h>
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include "MAX30100_PulseOximeter.h"
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

// ESP32 I2C Configuration
#define I2C_SDA 21
#define I2C_SCL 22
#define REPORTING_PERIOD_MS 1000

// WiFi Credentials
#define WIFI_SSID "YOUR_WIFI_SSID"
#define WIFI_PASSWORD "YOUR_WIFI_PASSWORD"

// UV Sensor Pin
#define UV_SENSOR_PIN 36

// Sensor Objects
Adafruit_MPU6050 mpu;
PulseOximeter pox;

// NTP Client
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", 19800);

// Variables
int stepCount = 0;
float stepThreshold = 1.2;
float lastAccelZ = 0;

unsigned long lastStepTime = 0;
unsigned long debounceDelay = 250;

unsigned long lastUploadTime = 0;
unsigned long uploadInterval = 15000;

uint32_t tsLastReport = 0;

void onBeatDetected()
{
  Serial.println("Heartbeat detected!");
}

void setup()
{
  Serial.begin(115200);

  analogReadResolution(12);

  Wire.begin(I2C_SDA, I2C_SCL, 400000);

  // MAX30100 Initialization
  if (!pox.begin())
  {
    Serial.println("MAX30100 not found!");
    while (1);
  }

  pox.setIRLedCurrent(MAX30100_LED_CURR_7_6MA);
  pox.setOnBeatDetectedCallback(onBeatDetected);

  // MPU6050 Initialization
  if (!mpu.begin())
  {
    Serial.println("MPU6050 not found!");
    while (1);
  }

  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

  // WiFi Connection
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi Connected!");

  Blynk.config(BLYNK_AUTH_TOKEN);

  timeClient.begin();
  timeClient.update();
}

void loop()
{
  Blynk.run();

  pox.update();

  timeClient.update();

  int currentHour = timeClient.getHours();

  sensors_event_t accel, gyro, temp;
  mpu.getEvent(&accel, &gyro, &temp);

  float currentAccelZ = accel.acceleration.z;

  float uvIndex = 0;

  if (currentHour >= 6 && currentHour < 18)
  {
    float uvVoltage = analogRead(UV_SENSOR_PIN) * (3.3 / 4095.0);

    uvIndex = constrain(map(uvVoltage * 100, 0, 100, 0, 15), 0, 15);
  }

  // Step Counting Logic
  if (abs(currentAccelZ - lastAccelZ) > stepThreshold &&
      (millis() - lastStepTime > debounceDelay))
  {
    stepCount++;
    lastStepTime = millis();
  }

  lastAccelZ = currentAccelZ;

  // Serial Monitor Output
  if (millis() - tsLastReport > REPORTING_PERIOD_MS)
  {
    Serial.print("Heart Rate: ");
    Serial.print(pox.getHeartRate());

    Serial.print(" bpm | SpO2: ");
    Serial.print(pox.getSpO2());

    Serial.print("% | Steps: ");
    Serial.print(stepCount);

    Serial.print(" | Temp: ");
    Serial.print(temp.temperature);

    Serial.print(" C | UV Index: ");
    Serial.println(uvIndex);

    tsLastReport = millis();
  }

  // Upload to Blynk
  if (millis() - lastUploadTime > uploadInterval)
  {
    Blynk.virtualWrite(V0, stepCount);
    Blynk.virtualWrite(V1, temp.temperature);
    Blynk.virtualWrite(V2, uvIndex);
    Blynk.virtualWrite(V3, pox.getHeartRate());
    Blynk.virtualWrite(V4, pox.getSpO2());

    lastUploadTime = millis();
  }
}
