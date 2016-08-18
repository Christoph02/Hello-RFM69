# Project: BMP085, LEDs and Switches connected to Raspberry PI    
```
This project contains the core runtime package and several addons of openHAB.  
See https://github.com/openhab/openhab/wiki/Quick-Setup-an-openHAB-Server  
```
## Description
### Example using BMP085, LEDs and Switches
```
Clients:
- Webbrowser
- Openhab mobile App

1. View pressure, temperature, raspberry CPU and GPU temperature
```
![Openhab temp](mydocu/images/openhab-temp.png?raw=true)
```
2. Toggle LEDs (from Hello-World)
using clients or switches on Breadboard
```
#### Switches:
```
Button 1 - hold: Blue LED -> ON
Button 2 - pressed: Red LED -> toggle status
Button 1 pressed + Button 2 pressed: LEDs -> OFF
```

## Hardware:
- Raspberry PI 3 Model B
- BMP085 (low-power barometric pressure sensor)
- 3x LEDs (gn, bl, rd)
- 2x Switch
- Restistor: 3x250Ω, 2x1kΩ  
- Breadboard and cable  

## Setup
![Frizzing Setup](mydocu/images/project-setup.png?raw=true)
  
## Installation

### Install Oracle 8 JDK on raspbery pi
[Installing openHAB, Habmin and GreenT on a raspberry pi (Raspbian) - Steven Lazidis](http://www.addictedtopi.com/post/92932590168/installing-openhab-habmin-and-greent-on-a)

```
  apt-get install oracle-java8-jdk
```  
### Install MQTT broker "Mosquitto"
```
sudo apt-get install mosquitto mosquitto-clients python-mosquitto
```
### Install and run project
  Download [ZIP](https://gitlab.fritz.box/Smarthome/Hello-BMP085/repository/archive.zip?ref=master)  
  Extract ZIP to /opt 
  
### Start openhab with adminrights
```  
  cd /opt
  sudo ./start.sh 
```  
  
    
## Software used for Project
### Raspberry
[Raspian image](https://www.raspberrypi.org/downloads/)

### Openhab
[Openhab.org](http://www.openhab.org/)
[distribution-1.8.3-runtime] (https://bintray.com/artifact/download/openhab/bin/distribution-1.8.3-runtime.zip)
[distribution-1.8.3-addons] (https://bintray.com/artifact/download/openhab/bin/distribution-1.8.3-addons.zip)
### Addon builds 1.9.0, corrections for switch issues
[Raspian Jessie / GPIO input - Alejandro Guirao] (https://community.openhab.org/t/raspian-jessie-gpio-input/3448/40)
[org.openhab.binding.gpio-1.9.0-SNAPSHOT.jar] (https://www.dropbox.com/s/9iv1pq7da48zmwq/org.openhab.io.gpio-1.9.0-SNAPSHOT.jar?dl=0)
[org.openhab.io.gpio-1.9.0-SNAPSHOT.jar] (https://www.dropbox.com/s/r5uutaz2gbq8leo/org.openhab.binding.gpio-1.9.0-SNAPSHOT.jar?dl=0)

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