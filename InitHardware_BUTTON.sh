#!/bin/bash

#initialisation of Virtual CAN interface and CANopen nodes for 
#testing of socket connections.



#setting up CAN1 interface on BBB.
sudo config-pin p9.24 can
sudo config-pin p9.26 can
dmesg|grep can
sudo modprobe can
sudo modprobe can-dev
sudo modprobe can-raw
lsmod|grep can
mesg|grep raw
sudo ip link set can1 up type can bitrate 1000000
sudo ifconfig can1 up

sudo config-pin -a p8.7 in+
sudo config-pin -a p8.8 in+
sudo config-pin -a p8.9 in+
sudo config-pin -a p8.10 in+