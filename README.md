# spring2023-isaacPetersonKSU 


 
 
# Initial Write-up :  Mushroom Spawn Production Tool 
An embedded system to help mushroom growers manage their crops. The system will control fresh air exchange and humidity in a sterile  container without increasing the risk of contamination. The system is intended for grain spawn production, but could have other, more experimental applications.

###  What is Mushroom Spawn?
Mushroom Spawn is a energy-dense food source (usually grain) that has been colonized by a mushroom-producing fungus. It is used to give the mushrooms a head start against contamination when inoculating a larger substrate. Grain is extremely cheap, but grain spawn can be worth a lot of money, and mycelium grows at an exponential rate, so a system for producing it would theoretically scale extremely well. 

## Problem
Current practices do not scale well because they constrain the maximum size of a growing container too small to really take advantage of the exponential growth. Here's how the container size is limited:

* Lack of Fresh Air Exchange (FAE)
* Lack of real time moisture regulation
* Lack of reliable way to detect contamination early

### Lack of Fresh Air Exchange (FAE)
Each KG of grain requires 29.37 L of atmosphere to metabolize (1.39 gallons / 12 oz jar). Without a ventilation system, the maximum colonization rate is limited by whatever fresh air happens to (or not to) drift through the .3 micron hole in a filter. The obvious solution to this is a simple fan, but forcing air through will dry out the substrate and forcing more air than necessary though increases risk of contamination. 

### Lack of real time moisture regulation
Under the current system, the appropriate amount of moisture must be calculated and mixed before sterilization, at which point the container is sealed until fully colonized, an unknown amount of moisture will be lost to fresh air exchange, these calculations always involve at least some guesswork. Guesswork is not good considering how important it is to get this mixture right. 
#### **Insufficient moisture** 
* slows mycelial growth - wasting time.
* bottlenecks the digestion of available nutrients, wasting money 
#### **Too much moisture**
* makes the substrate more hospitable for a wider variety of microorganisms, increasing risk (and therefore frequency) of contamination - wasting time and money.

Larger grow containers mean more FAE, which means more drying, so this problem scales badly. 


### Lack of reliable way to detect contamination early
Early detection of contamination is essential for mitigating the harm they cause by removing the contamination before it spreads to another grow container. Early detection also reduces time and energy invested in crops that will ultimately fail. Contamination is often difficult to identify, and as container sizes increase, transparent containers become less practical, and more growth medium will be hidden on the container's interior. 

## Solution
My solution to these problems is a system that can regulate fresh air exchange and humidity. It will also log all sensor data. This easy consistent data collection will make it easier to 

### Hardware
* Cap clip (3-D printed PLA) - Mechanical structure
* Raspberry Pi pico W (RP-2040) - Microcontroller
* MQ135 - Gas Sensor
* DHT22 - Temperature and Humidity Sensor
* GDA8010 - Fan
* "Grove  ‐  Water  Atomization  v1.0" (ETA1617、NE555)

### Software
A C program running on the pi pico will regulate fresh air exchange and humidity by controlling the atomizer and fan according to inputs from relevant sensors. This part is easy. Log data will also be recorded. If multiple units are present, they will be able to request and send date to each other witlessly. This data will be used to implement a feature that automatically tunes environmental parameters to optimize yield. 

## Algorithmic Functionality 
### Simple Distributed Database 
All sensor data will be logged and saved to a database on a host machine (the pi pico w can connect to WIFI networks). The user will be responsible for inputting the yields of each harvest

### Auto-Tune 
For any parameter the system controls (just FAE and humidity for now), the user will manually set a starting point, say 75°F with 85% humidity. The controllers will be randomly split into 2 groups, half will try a value slightly lower than what the user specified, and half will try something higher. The results are recorded, and yield data is recorded and each parameter is adjusted based on which random group tended to perform better. Several factors will determine how much it is adjusted
* A parameter that just changed directions will change by half as much as last time
* A parameter that is moving the same direction as last time will move by twice as much. 

## Qualifications 
I have written thousands of lines of embedded C for my current employer, I should be allowed to write a few for myself. Admittedly, this project will put me on some unfamiliar territory, specifically CAD and mycology, but I'm picking these thing up quickly already in the week I've spent working so far, so I don't foresee any issues I can't handle. 


## Feature List

### Minimum Viable Product (MVP)
* Functional hardware prototype
* Fresh Air Exchange control from sensor input
* Humidity control from sensor input
* All sensor data is logged to microcontroller's local storage (2MB)
	* Accessible from computer via 

### Version 1.0
* Over-The-Air software updates 
* Simple distributed database (each device will need peripheral storage)
* CLI (cross-platform; written in C++) app to interface with one or several devices at a time
* Auto-tune feature as described above 

### Version 2.0
Contamination detection via sensor inputs
* WAN communication between systems to improve volume of grow data being collected.
* All plastic components can be injection-molded
* Electrical pulses to induce fruiting conditions
* Electrical control of other behavior may be possable, as well as data collection via the monitoring of electrical pulses within the mycelial network.
