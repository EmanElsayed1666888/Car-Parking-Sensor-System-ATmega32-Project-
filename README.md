# Car-Parking-Sensor-System-ATmega32-Project-
Car Parking Sensor System (ATmega32 Project)
📌 Project Overview

The Car Parking Sensor System is designed using the ATmega32 microcontroller and an HC-SR04 ultrasonic sensor to assist drivers in detecting obstacles while parking. The system provides real-time distance measurement on an LCD and uses LED indicators and a buzzer to warn drivers of nearby obstacles, ensuring safety and precision while parking.

This project integrates ultrasonic sensing, LCD interfacing, LED indication, and buzzer alerts with a layered driver-based architecture in embedded C.

✨ Features

Ultrasonic Distance Measurement – Calculates distance between the car and an obstacle using HC-SR04.

LCD Display – Shows distance in cm, displays “Stop” if ≤ 5 cm.

LED Indicators – Visual guidance:

≤ 5 cm → All LEDs flashing (Red, Green, Blue).

6–10 cm → All LEDs ON.

11–15 cm → Red + Green ON, Blue OFF.

16–20 cm → Only Red ON.

20 cm → All LEDs OFF.

Buzzer Alerts – Sounds when object is ≤ 5 cm.

🛠️ Hardware Components

Microcontroller: ATmega32 (16 MHz)

Ultrasonic Sensor: HC-SR04 (Trigger: PD7, Echo: PD6)

Display: 16x2 LCD (4-bit mode, PA1–PA6)

LEDs: Red (PC0), Green (PC1), Blue (PC2)

Buzzer: PC5 (transistor controlled)

📂 Software Architecture

Drivers Implemented:

GPIO Driver

ICU Driver (for ultrasonic sensor timing)

LCD Driver (4-bit mode)

Ultrasonic Sensor Driver

Buzzer Driver

LED Driver

Core Functions:

Ultrasonic_init() → Initializes ultrasonic sensor with ICU.

Ultrasonic_Trigger() → Sends trigger pulse.

Ultrasonic_readDistance() → Returns measured distance in cm.

Ultrasonic_edgeProcessing() → Callback for pulse timing.

Buzzer_on() / Buzzer_off() → Controls alarm.

LCD_display() → Shows distance and warnings.

⚡ System Operation

Ultrasonic sensor continuously measures distance.

LCD shows real-time distance; displays “Stop” if ≤ 5 cm.

LEDs light up progressively as the object approaches.

Buzzer activates when distance ≤ 5 cm.
