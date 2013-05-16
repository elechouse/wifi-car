# Wifi Car #

## Introduction ##

Easily build a Wi-Fi car with open source technologies

Harware

- a route - TP Link WR703N or Fast FWR171-3G 
- an Arduino board
- a car with motor driver
- a USB Hub(optional)
- a USB camera

Software

- OpenWrt, a GNU/Linux based firmware program for embedded devices such as residential gateways and routers.
- Arduino
- Android app to control the car remotely.
- Web browser to access web UI of the car.

![Hardware Overview](./doc/hardware_overview.png)

## How to ##

### Prepare ###

### Assemble ###

### Access WifiCar ###

#### Direct connect WifiCar ####



1. connect with the WiFi car through WiFi. The SSID of the WiFi car is 
"wifi-car".
2. access the WiFi car through web browser or android app - WiFi Car.

	a) web browser

		URL                                     Description
		----------------------------------------------------
		http://192.168.1.1/car                  web UI 
		http://192.168.1.1:8080?action=stream   camera
		http://192.168.1.1/cgi-bin/serial       cgi script to send data

    b) Android app - WiFi Car

        	just run the app.


#### Through another router ####

Control you WifiCar through another router, by this, you don't need to disconnect from your network, and you can control your car while surfing.


## **Technical Detail** ##

This section shows the curious man how **WifiCar** works.

The arduino board reads command from serial port. A command is a line end with
LF('\n').

	Commands        functions
	-----------------------------
	w               forward
	a               turn left
	s               backward
	d               turn right
	z               stop
	e               accelerate
	c               decelerate
	i               camera up
	k               camera down
	j               camera left
	l               camera right
	o               center camera
 
## **BUY** ##
[Wifi Car Kits](www.elechouse.com)