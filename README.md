# 🐾 IoT-Based Remote Pet Food Dispenser

**Duration**: May 2023 – June 2023  
**Project Title**: Remote Pet Food Dispenser Using IoT

---
<p align="center">
  <img src="https://github.com/user-attachments/assets/9a2f0433-20d5-4f2c-bf30-6b98e8cd173b" width="50%" style="margin-right: 10px;">
  <img src="https://github.com/user-attachments/assets/c6633e39-38e8-4793-b7b1-9a94a9daf279" width="40%">
</p>


## 📌 Overview

As the number of pet owners increases, one common issue is feeding pets while away from home. This project aims to solve that problem by creating a **smart IoT-based system** that remotely dispenses food only when the pet is nearby.

Additionally, to maintain food freshness and reduce waste, the system provides food only when needed and allows mixing two types of pet food based on the owner’s preference.

---

## ❓ Problem Statement & Changes from Previous Proposal

### Problem
- Pets are often left alone at home, and feeding schedules can be missed.
- Unattended food gets stale when left out too long, especially if the pet isn't hungry.
- Most commercial dispensers don’t support **food mixing** or **intelligent feeding based on pet presence**.

### Key Features
- Remote control of food quantity and mix ratio via smartphone.
- Dispensing occurs only when the pet is detected near the bowl.
- Plays a melody (e.g., birthday song) when food is being served.
- Allows **diet control** (no food if not approved by the owner).
- Additional access to YouTube or pet food shopping links in the app.

### Changes from Previous Proposal
Initially, we planned to use a **load cell** to measure food weight, but due to difficulties in securely fixing the sensor, it was removed from the design. To compensate, the following features were added:

1. In-app links to YouTube or pet food websites.
2. Support for **two food types** to be mixed in variable ratios.
3. Buzzer alert to indicate when food is actually being dispensed.

---

## 🛠 Components Used

| Component           | Purpose |
|---------------------|---------|
| Arduino Uno         | Main controller |
| Servo Motor (2x SG-90) | Dispensing and mixing food |
| Bluetooth Module (HC-06) | Wireless communication with the app |
| Ultrasonic Sensor (HC-SR04) | Detects pet presence near the bowl |
| Piezo Buzzer        | Melody when food is dispensed |
| MIT App Inventor    | Tool for developing the smartphone control app |

---

## 🔄 Operation Workflow

1. The owner sets food quantity (for 2 types) and sends the command via smartphone.
2. The Bluetooth module receives the command on the Arduino.
3. If the pet approaches the dispenser, it is detected by the ultrasonic sensor.
4. A melody is played through the buzzer as food is being dispensed.
5. Two types of food are mixed in the set ratio and dispensed into the bowl.

---

## 🔌 Circuit Diagram & Connections

![image](https://github.com/user-attachments/assets/3f541c81-83f3-4879-82fe-95f49c30e78d)


---

## 📱 App Design (MIT App Inventor)

- User-friendly interface to select:
  - Type A and B food quantity
  - Mix ratio
  - Dispense now button
- Buttons for YouTube/pet store access

---

## ✅ Expected Benefits

- Helps maintain a healthy feeding schedule for pets
- Prevents overfeeding and keeps food fresh
- Supports dietary variation with two types of food
- Pet learns when food is actually being dispensed through sound cues
- Owners can manage feeding remotely, even while away

---
<h3>🐶 Feeding Condition Comparison</h3>

<p align="center">
  <a href="https://youtu.be/vuacu80U3gY?si=HfdGNGmQD7qi5-7F" target="_blank">
    <img src="https://img.youtube.com/vi/vuacu80U3gY/0.jpg" width="45%" alt="No Food">
  </a>
  <a href="https://youtu.be/LXwTHvFJSxg?si=M2wRbNMIxq01AL5A" target="_blank">
    <img src="https://img.youtube.com/vi/LXwTHvFJSxg/0.jpg" width="45%" alt="Food Dispensed">
  </a>
</p>

<p align="center">
  <span style="color: red; font-weight: bold;">🔴 No Food Available</span>
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
  <span style="color: green; font-weight: bold;">🟢 Food Dispensed</span>
</p>

---

For more details, please use pdf and ppt.
