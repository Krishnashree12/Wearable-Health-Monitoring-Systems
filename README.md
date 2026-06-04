# Wearable-Health-Monitoring-System

## Project Team

- Krishnashree D
- Priyadharshan L
- Akshaiya S
- Vignesh B K


B.E. Electronics and Communication Engineering
College of Engineering Guindy, Anna University

## Project Overview

The Wearable Health Monitoring System is an IoT-based healthcare solution designed to continuously monitor vital health parameters in real time. The system integrates multiple sensors with an ESP32 microcontroller to measure heart rate, blood oxygen saturation (SpO₂), body temperature, physical activity, and UV exposure.

The collected data is processed by the ESP32 and transmitted wirelessly to the Blynk IoT platform, allowing users to monitor their health metrics through mobile and web dashboards. The system aims to provide an affordable, portable, and user-friendly approach to preventive healthcare and remote health monitoring.

### Objectives

- Monitor heart rate and SpO₂ levels in real time.
- Track body temperature and physical activity.
- Measure UV exposure and provide health awareness.
- Enable wireless health monitoring through IoT.
- Provide real-time visualization using the Blynk platform.
- Promote preventive healthcare through continuous monitoring.

---

## Features

- Real-Time Heart Rate Monitoring
- Blood Oxygen (SpO₂) Measurement
- Body Temperature Monitoring
- Step Counting and Activity Tracking
- UV Exposure Monitoring
- Wireless Data Transmission using Wi-Fi
- Mobile and Web Dashboard Access
- Blynk IoT Integration
- Rechargeable Battery Operation
- Portable and User-Friendly Design

## Hardware Components

| Component | Function |
|------------|------------|
| ESP32 | Main microcontroller for data processing and wireless communication |
| MAX30100 | Measures Heart Rate and SpO₂ levels |
| MPU6050 | Tracks motion, activity, and step count |
| HW-837 UV Sensor | Measures UV radiation intensity |
| Li-ion Battery | Portable power supply |
| Blynk IoT Platform | Real-time cloud monitoring and visualization |

---

## System Architecture

<img width="790" height="513" alt="image" src="https://github.com/user-attachments/assets/819f4ecb-a56b-4ab5-a1be-b718474dbad8" />

The system integrates multiple sensors with the ESP32 microcontroller to collect health and environmental data, which is transmitted wirelessly to the Blynk IoT platform for real-time monitoring.
## Software Stack

- Arduino IDE
- ESP32 Development Framework
- Blynk IoT Platform
- Wi-Fi Communication
- Embedded C/C++
- Sensor Libraries

---

## Working Principle

### 1. Data Acquisition

The ESP32 collects data from multiple sensors connected to the system:

- MAX30100 for Heart Rate and SpO₂ monitoring
- MPU6050 for motion tracking and step counting
- HW-837 for UV exposure monitoring

### 2. Data Processing

Raw sensor readings are processed by the ESP32 to obtain meaningful health metrics such as:

- Heart Rate (BPM)
- Blood Oxygen Saturation (SpO₂)
- Body Temperature
- Step Count
- UV Index

### 3. Wireless Communication

The processed data is transmitted to the Blynk IoT Cloud through Wi-Fi connectivity.

### 4. Real-Time Monitoring

Users can access live health information through:

- Blynk Mobile Application
- Blynk Web Dashboard

### 5. Health Awareness

The system continuously monitors health parameters and helps users stay informed about their physical activity, oxygen levels, heart rate, temperature, and UV exposure.

---

## Key Functionalities

✅ Heart Rate Monitoring
✅ SpO₂ Measurement
✅ Step Counting
✅ Temperature Monitoring
✅ UV Exposure Tracking
✅ Real-Time Cloud Monitoring
✅ Wireless Data Access

## Results

The developed wearable health monitoring system successfully monitored and transmitted the following parameters in real time:

- Heart Rate (BPM)
- Blood Oxygen Saturation (SpO₂)
- Body Temperature
- Step Count
- UV Exposure

The sensor data was processed by the ESP32 and displayed on the Blynk IoT dashboard through Wi-Fi communication, enabling real-time health monitoring through mobile and web interfaces.

## Future Scope

The current prototype demonstrates the feasibility of real-time health monitoring using IoT and embedded systems. Several enhancements can be incorporated in future versions to improve functionality, accuracy, and user experience:

- Design a custom PCB to reduce size, improve reliability, and enable wearable form factors such as smart bands or health-monitoring rings.
- Integrate additional health sensors, including ECG, blood pressure, and GSR sensors, for more comprehensive health monitoring.
- Implement cloud-based data storage using platforms such as Firebase or AWS IoT for long-term health record management.
- Develop a doctor/caregiver dashboard to enable remote patient monitoring and health analysis.
- Incorporate machine learning algorithms to detect anomalies and provide predictive health insights.
- Add GPS and emergency alert features for elderly care and patient safety applications.
- Improve power management techniques to increase battery life and support continuous monitoring.
- Develop a dedicated mobile application with personalized health recommendations and alerts.
