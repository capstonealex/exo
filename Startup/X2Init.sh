#!/bin/bash

#initialisation of Virtual CAN interface and CANopen nodes for 
#testing of socket connections.

#echo "Enter name for prev log file (don't enter extension)"
#read newname

#filename="/home/debian/CANopenSocket/canopend/X2_log.txt"

#mv $filename /home/debian/CANopenSocket/canopend/$newname.txt

#setting up CAN1 interface on BBB.
sudo config-pin p9.24 can
sudo config-pin p9.26 can
#dmesg|grep can
#sudo modprobe can
#sudo modprobe can-dev
#sudo modprobe can-raw
#lsmod|grep can
#mesg|grep raw
sudo ip link set can1 up type can bitrate 1000000
sudo ifconfig can1 up

#Setting up GPIO buttons for hand controller
config-pin -a p8.7 in+
config-pin -a p8.8 in+
config-pin -a p8.9 in+
config-pin -a p8.10 in+

cd /home/debian
echo - > od4_storage
echo - > od4_storage_auto

#Setting up slave nodes
cd /home/debian/CANopenSocket/canopend

#Setting up master node
echo - > od4_storage
echo - > od4_storage_auto
app/canopend can1 -i 100 -s od4_storage -a od4_storage_auto -c "" &
