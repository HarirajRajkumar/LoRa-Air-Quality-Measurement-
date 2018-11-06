# LoRa-Air-Quality-Measurement-

This project aims on developing a solar powered air quality monitoring IoT system which will read real time environmental data like temperature, humidity, smoke, C02, etc and transmit the data over long distance using a very efficient sub 1Ghz RF communication technique.

## Problem Statement

In order to scale the Internet-of-Things (IoT) to hundreds of billions of devices, efficient operations for IoT must be improved significantly – particularly for low-power, wide-area networking (LPWAN) for sending little, but important data.


## Methodology

Consider the data is transmitted through channel (i.e. air) to a receiver located at a distance D from the transmitter. The transmitter is kept constant in a location and receiver is moved away in the distance of metres. So therefore, calculating the RSSI Value, gain, Packet collision simulation.


## Technical Details

The underlying principle is to use the popular Sub 1Ghz frequency bands RF modules to transmit the sensor data for the air quality monitoring systems. It monitors the real time data such as humidity, temperature using DHT22 Sensor and MQ-135 for detecting of NH3, N0x, alcohol, Benzene, Smoke, CO2, etc. As this will be placed in a remote area, it also uses solar power to charge the battery.

Note: There exists many other modulation techniques using sub 1Ghz carrier frequency like sigfox and etc.

In this project we wanted to use of the technique which is LoRa (“Long Range”) using Sub 1Ghz Modules available in the market. LoRa uses license-free sub-gigahertz radio frequency bands like 169 MHz,433 MHz, 868 MHz and 915 MHz enabling very-long-range transmission (more than 10km in rural areas) with low power consumption. This facilitate us to transmit air quality data using very low power (in terms of uA and mA) for longer range.

This system will provide collection, evaluation and storage of environmental data for the sake of air quality and environment measurement. It helps to measure air quality inside or outside a factory/buildings/manufacturing plant.

Under the hood, system is run by an ESP32 (for prototype) by periodically reading data from DHT22 and MQ-135 sensors and transmit the data using the LoRa transmitter node to a LoRa receiver node (or) a LoRA gateway for a multipoint measurement.

Once the data is received from various strategically placed transmission nodes it can be further processed, analysed and accordingly required action can be taken.

Current Status of Development / Usage

Air pollution is currently monitored by environmental or government authorities using static monitoring stations, which are equipped with instruments for measuring regulatory pollutants. The air pollutant analysers are relatively bulky, heavy and expensive with price ranges between 4,30,000 INR and 26,00,000 INR.


Advantage of developing and deploying this system are
·         Low Cost
·         Easily installable
·         Long Range coverage of 10km to 15km
·         Less power consumption
·         High Data Rate
·         Can be scaled up easily by adding multiple node

## Features of LoRa

Modulation
SS Chirp
Data Rate
290bps – 50kbps
Max Msgs/day
Unlimited
Max output power
20 dbm

Link Budget
154 db
Battery Lifetime-2000mAh
105 months

Power Efficiency
Very High
Interface immunity
Very High
Security
Yes
Mobility
Yes


## Expected Results

Should provide data transmission range in distance of 5 Km with tentative minimalist loss.

## Measured Results

By use of this module we were possibly able to achieve range of 4 to 5 Km at current range of mA. As the receiver moved away from the receive the 868 MHz 2 Dipole Antenna measured RSSI value of less than -180 dBm (depends upon the obstacle present).

