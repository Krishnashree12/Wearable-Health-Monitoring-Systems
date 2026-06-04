#include <Wire.h>
#include "MAX30100_PulseOximeter.h"

PulseOximeter pox;

void onBeatDetected() {
  Serial.println("Beat!");
}

void setup() {
  Serial.begin(9600);

  if (!pox.begin()) {
    while (1);
  }

  pox.setOnBeatDetectedCallback(onBeatDetected);
}

void loop() {
  pox.update();

  Serial.print("HR: ");
  Serial.print(pox.getHeartRate());

  Serial.print(" bpm | SpO2: ");
  Serial.println(pox.getSpO2());

  delay(1000);
}
