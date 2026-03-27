This repository contains multiple Arduino-based projects:

# Projects:
1. DC Voltmeter
2. Temperature Monitoring System and its modified version 
3. Metal Detector
4. Smart Energy Meter (In Progress)

# Tools Used:
- Arduino
- Embedded C
- KiCad (PCB Design)
  

# Basic description of every project :

## Smart Energy Meter (Arduino + KiCad
Designed and developed a smart energy meter using Arduino to measure voltage, current, and power consumption. Interfaced sensors for real-time monitoring and displayed output on Serial Monitor. Designed PCB using KiCad for circuit implementation. Project currently under development.

## DC Voltmeter
Developed a DC voltmeter using Arduino and a voltage divider circuit to measure input voltage. Converted analog signals into digital values using ADC. Displayed output on LCD/Serial Monitor. Achieved stable and accurate readings.

## Temperature Monitoring System
Built a temperature monitoring system using LM35 sensor and Arduino. Measured real-time temperature and displayed it on LCD/Serial Monitor. Implemented analog signal processing for accurate readings. System responds effectively to temperature variations.

## Modified Temperature Monitoring System
Modified the previous temperature system bt adding some components , added relay module for automatic switching when the real time temperature hits above the threshold temperature set by the potentiometer . added a external fan to make the temp of the surrounding cool and also added the hystresis control to avoid the flickering of switching neear around the threshold temparature 

## Metal Detector
Designed a metal detector using a coil-based sensing mechanism and Arduino. Detected changes in magnetic field caused by nearby metal objects. Triggered a buzzer as an alert on detection. Demonstrated basic electromagnetic sensing principles.
