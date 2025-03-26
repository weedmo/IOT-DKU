# 🐾 IoT-Based Remote Pet Food Dispenser

**Duration**: May 2023 – June 2023  
**Project Title**: Remote Pet Food Dispenser Using IoT

---

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

- **Servo Motor 1** (food dispensing):  
  - VCC → 5V  
  - GND → GND  
  - Signal → D8  

- **Servo Motor 2** (food mixing):  
  - Signal → D5  

- **Bluetooth Module (HC-06)**:  
  - VCC → 5V  
  - GND → GND  
  - TXD → D10  
  - RXD → D9  

- **Ultrasonic Sensor (HC-SR04)**:  
  - VCC → 5V  
  - GND → GND  
  - Trig → D12  
  - Echo → D13  

- **Piezo Buzzer**:  
  - + → Arduino pin  
  - – → GND  

- **Arduino Uno**:  
  - Connected to PC via USB  
  - Power distributed via breadboard rails

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

## 📷 Images (Examples)

> 💡 Consider adding real photos or circuit diagrams here if using for GitHub or reports.

- Fig 1: Arduino Uno  
- Fig 2: Servo Motors  
- Fig 3: HC-06 Bluetooth  
- Fig 4: MIT App UI  
- Fig 5: HC-SR04 Ultrasonic Sensor  
- Fig 6: Piezo Buzzer  
- Fig 7–10: Full Wiring and Assembly

---

Let me know if you’d like this in **PDF**, or if you want a **poster/PPT version** for presentation!
