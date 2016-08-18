# Project: RFM69W, connected to Arduino   
## Description
### Data Transfer Example with RFM69W using two Arduinos
```
Clients:
- putty serial monitor
- arduino serial monitor

1. Send data from Arduino Pro Mini to Arduino Uno using RFM69W at 433 Mhz

## Hardware:
- Arduino Pro Mini
- Arduino UNO
- FTDI Basic Breakout 5V/3.3V - Micro USB
- 2 x RFM69W-433S2 transceiver

## Setup
![Frizzing Setup](mydocu/images/project-setup_pcb.png?raw=true)
  
## Installation
### Install and run project
  Download [ZIP](https://gitlab.fritz.box/Smarthome/Hello-BMP085/repository/archive.zip?ref=master)  
  Extract ZIP  
  Using Arduino.exe or Fritzing to upload Sketches to Arduino:
  ```
  Upload Sketch "\Arduino\Transmitter\Transmitter.ino" to Arduino Pro Mini
  Upload Sketch "\Arduino\Receiver\Receiver.ino" to Arduino UNO
  ```
  
    
## Software used for Project
### Arduino
[ARDUINO] (https://www.arduino.cc/en/Main/Software)
[Putty] (http://portableapps.com/de/apps/internet/putty_portable)

---
## CE (Community Edition) Software for Development 

#### Python
[PyCharm-CE](http://www.jetbrains.com/pycharm/download/#section=windows)

#### PCB (Printed Circuit Board) Design
[Fritzing](http://fritzing.org/home/)

#### Software Containerization
[Docker-CE for Ubuntu](https://docs.docker.com/engine/installation/linux/ubuntulinux/)

#### Version control
[Git --fast-version-control](https://git-scm.com/about)  
[Gitlab-CE on Docker](https://hub.docker.com/r/gitlab/gitlab-ce/)

## References
[Uber](http://www.instructables.com/id/Uber-Home-Automation-w-Arduino-Pi/?ALLSTEPS)  Home Automation w/ Arduino & Pi