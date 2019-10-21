#!/bin/bash

cd /home/debian/CANopenSocket/canopencomm

#Go from preop to start mode
./canopencomm 1 start

#Change drive mode to position mode.
./canopencomm [1] 1 write 0x6060 0 i8 1

#Display current drive mode
./canopencomm [1] 1 read 0x6061 0 i8

#display current knee value
echo "current knee value"
./canopencomm [1] 1 read 0x6063 0 i32

#Set target position
echo "Enter target absolute position (0 is full extended, 240,000 is bent):"
read target
./canopencomm [1] 1 write 0x607A 0 i32 $target
echo "Target relative position is:"
./canopencomm [1] 1 read 0x607A 0 i32

#display status
echo "status word"
./canopencomm [1] 1 read 0x6041 0 i16


#move knee
./canopencomm [1] 1 write 0x6040 0 i16 47
./canopencomm [1] 1 write 0x6040 0 i16 63

#display current knee value
echo "current knee value"
./canopencomm [1] 1 read 0x6063 0 i32