# Wifi Car #
Easily build a Wi-Fi car with open source technologies.

## Introduction ##

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

![Hardware Overview](./image/hardware_overview.png)

## How To ##
This section shows you how to build a WifiCar with Elechouse's WifiCar Kits.

### Prepare ###

- CarDriverShield with an Arduino Nano on it.
- A car with 4 motors on it
- An openwrt router (TP-Link WR703N or FAST FWR171-3G) with the firmware in this repository.
- A USB Hub
- A USB camera.
- Several USB cables and some wire.
- **Also a powerful battery**. (Elechouse's kits do not contain any battery)

### Assemble ###
(UNFINISHED)

### WifiCar Control ###

#### Direct connect WifiCar ####

This is the simplest way to control your WifiCar. Just connect your PC(or Android Mobile device) and control your WifiCar use browser(through App when using Android Mobile device).

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

Control you WifiCar through another router, by this, you don't need to disconnect from your LAN, and you can control your WifiCar while surfing.

1. After you assemble your WifiCar, power on your WifiCar
1. For first time using you need to configure your Tp-link WR703n(or FWR171-3G), connect your PC with the WifiCar Router(SSID: **wifi-car**, or you can connect your WifiCar through **network cable**).
1. Access **192.168.1.1** and you will see like the picture below, by default **no password**, click **Login** button to log in.
![openwrt-config](./image/openwrt-login.jpg)
1. Click **network** -> **wifi**, and click **Scan** button to search your WIFI. Here I select our wifi name **elechouse**. Click **Join Network**.
	![openwrt-config](./image/openwrt-network-wif.jpg)
	![openwrt-config](./image/openwrt-network-wif-scan.jpg)
1. Fill your Wifi information. Click **submit**.
	![openwrt-config](./image/openwrt-network-wif-scan.jpg)
1. In the new window click **save&apply**.
	![openwrt-config](./image/openwrt-network-wif-connect.jpg)
	![openwrt-config](./image/openwrt-network-wif-connect-wait.jpg)
1. Click **Network** check the configuration. Click **Status** to see your IP, my WifiCar IP is **192.168.1.107**.
	![openwrt-config](./image/openwrt-network-wif-connect-check.jpg)
	![openwrt-config](./image/openwrt-network-wif-connect-check-ip.jpg)
1. For avoiding IP address collision, change the **gateway** of your **WifiCar router** to **192.168.2.1** (or another except hostname of your **Wireless Router**). Click **Network** -> **Interfacea** -> **Edit**, fill the new **IPv4 Address**, and **Save&Apply**.
	![openwrt-config](./image/openwrt-network-wif-lan-config.jpg)
	![openwrt-config](./image/openwrt-network-wif-change-ip.jpg)

1. Now your **WifiCar router** has been configurated. Reconnect to your personal WIFI, access <http://192.168.1.107/car> (replace 192.168.1.107 with your WifiCar ip), if all things go well you can see this:
	![openwrt-config](./image/car-console.jpg )

1. Now you can control your WifiCar through browser. Usage: 
    - w --> forward
    - s --> backward
    - a --> turn left
    - d --> turn right
    - e --> accelerate
    - c --> decelerate
    - z --> stop
    - i --> up
    - k --> down
    - j --> left
    - l --> right
    - o --> center 


#### Through Internet ####

To control your WifiCar through Internet, you need set your Router **Port Forward** rule, this may be different between routers, here is an example of Openwrt router.

1. Log in your **Openwrt** router(**NOT WifiCar Router**).
1. **Network** -> **Firewall** -> **Port Forwards**. Add camera port(8080) forward :
	- **Name** -> camera
	- **Protocol** ->  TCP(TCP+UDP also work)
	- **External Port** -> **7879** 
	- **Internal IP address**(means LAN device ip) -> **Your WifiCar IP(Mine is 192.168.1.107)**
	- **Internal Port** -> 8080

	![PortForwards](./image/port-forwards.jpg)
1. Click **Add**.
1. Add www port(80) forward :
	- **Name** -> **www**
	- **Protocol** ->  TCP(TCP+UDP also work)
	- **External Port** -> **7878** 
	- **Internal IP address**(means LAN device ip) -> **Your WifiCar IP(Mine is 192.168.1.107)**
	- **Internal Port** -> **80**
1. Click **Add**
1. Click **Save&Apply**
1. To avoid unnecessary trouble,restart your router. 
1. Log in your router again, check your personal router IP address, **Status** -> **Network** -> **IPv4 WAN Status**, from the picture you can see my ip is **59.40.251.174**, then access <http://59.40.251.174:7878/wcar> to control your WifiCar.
	![PortForwards](./image/check-ip-address.jpg)
	![InternetControl](./image/internet-control.jpg)
## **Technical Detail** ##
This section shows the curious man how **WifiCar** works.

### Working principle ###


###Communication protocol ###

The Arduino board reads command from serial port, the command is sent by user through WIFI. A command consists with a character and a LF('\n'). At present **Arduino board** never send any data to the **wifi-car router**.

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
[Wifi Car Kits](http://www.elechouse.com)