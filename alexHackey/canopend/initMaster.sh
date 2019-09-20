#!/bin/bash
# Initialize virtual bbb master node on canopend process

sudo modprobe vcan
sudo ip link add dev vcan0 type vcan
sudo ip link set up vcan0

app/canopend vcan0 -i 100 -c ""

echo "Virtual Master node set up as node 100 using canopend process"

