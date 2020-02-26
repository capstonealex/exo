#!/bin/bash

#Power on with knee and hip fully bent back. Let go.

cd /home/debian/CANopenSocket/canopencomm

#Go from preop to start mode
./canopencomm 2 start
./canopencomm 1 start
./canopencomm 3 start
./canopencomm 4 start
#MOVING

#Change drive mode to homing mode (mode 6).
./canopencomm [1] 2 write 0x6060 0 i8 6
./canopencomm [1] 1 write 0x6060 0 i8 6
./canopencomm [1] 3 write 0x6060 0 i8 6
./canopencomm [1] 4 write 0x6060 0 i8 6

#homing mode of operation: Home is current position. 
./canopencomm [1] 2 write 0x6098 0 i8 0
./canopencomm [1] 1 write 0x6098 0 i8 0
./canopencomm [1] 3 write 0x6098 0 i8 0
./canopencomm [1] 4 write 0x6098 0 i8 0

#Set home offset
./canopencomm [1] 1 write 0x607C 0 i32 115000
./canopencomm [1] 2 write 0x607C 0 i32 -- -335000
./canopencomm [1] 3 write 0x607C 0 i32 115000
./canopencomm [1] 4 write 0x607C 0 i32 -- -335000

#Set software joint limits
./canopencomm [1] 1 write 0x607D 1 i32 -- -110000 #Lhip lower limit
./canopencomm [1] 1 write 0x607D 2 i32 310000 #Lhip upper limit
./canopencomm [1] 2 write 0x607D 1 i32 2000 #Lknee lower limit
./canopencomm [1] 2 write 0x607D 2 i32 3350000 #Lknee upper limit
./canopencomm [1] 3 write 0x607D 1 i32 -- -110000 #Rhip lower limit
./canopencomm [1] 3 write 0x607D 2 i32 310000 #Rhip upper limit
./canopencomm [1] 4 write 0x607D 1 i32 2000 #Rknee lower limit
./canopencomm [1] 4 write 0x607D 2 i32 3350000 #Rknee upper limit

#Control word flip
./canopencomm [1] 2 write 0x6040 0 i16 15
./canopencomm [1] 2 write 0x6040 0 i16 31
./canopencomm [1] 2 write 0x6040 0 i16 15

./canopencomm [1] 4 write 0x6040 0 i16 15
./canopencomm [1] 4 write 0x6040 0 i16 31
./canopencomm [1] 4 write 0x6040 0 i16 15

./canopencomm [1] 3 write 0x6040 0 i16 15
./canopencomm [1] 3 write 0x6040 0 i16 31
./canopencomm [1] 3 write 0x6040 0 i16 15

./canopencomm [1] 1 write 0x6040 0 i16 15
./canopencomm [1] 1 write 0x6040 0 i16 31
./canopencomm [1] 1 write 0x6040 0 i16 15

#Move Hips to signal end
#Change drive mode to position mode.
./canopencomm [1] 1 write 0x6060 0 i8 1
./canopencomm [1] 3 write 0x6060 0 i8 1
#Set current profile velocity
./canopencomm [1] 1 write 0x6081 0 i32 100000
./canopencomm [1] 3 write 0x6081 0 i32 100000
#Set current profile acceleration
./canopencomm [1] 1 write 0x6083 0 i32 30000
./canopencomm [1] 3 write 0x6083 0 i32 30000
#Set current profile deceleration
./canopencomm [1] 1 write 0x6084 0 i32 30000
./canopencomm [1] 3 write 0x6084 0 i32 30000
#set Target position
./canopencomm [1] 1 write 0x607A 0 i32 -- -60000
./canopencomm [1] 3 write 0x607A 0 i32 -- -60000
#move Hips
./canopencomm [1] 1 write 0x6040 0 i16 47
./canopencomm [1] 1 write 0x6040 0 i16 63
./canopencomm [1] 1 write 0x6040 0 i16 47
./canopencomm [1] 3 write 0x6040 0 i16 47
./canopencomm [1] 3 write 0x6040 0 i16 63
./canopencomm [1] 3 write 0x6040 0 i16 47
# Wait for movements
sleep 5s

#set all motors to not active
./canopencomm [1] 1 write 0x6040 0 i16 0
./canopencomm [1] 2 write 0x6040 0 i16 0
./canopencomm [1] 3 write 0x6040 0 i16 0
./canopencomm [1] 4 write 0x6040 0 i16 0

# Do not disable drive on tracking error
./canopencomm [1] 1 write 0x2182 0 i32 159
./canopencomm [1] 2 write 0x2182 0 i32 159
./canopencomm [1] 3 write 0x2182 0 i32 159
./canopencomm [1] 4 write 0x2182 0 i32 159

# Increase Tracking Error Window
./canopencomm [1] 1 write 0x2120 0 i32 200000
./canopencomm [1] 2 write 0x2120 0 i32 200000
./canopencomm [1] 3 write 0x2120 0 i32 200000
./canopencomm [1] 4 write 0x2120 0 i32 200000

pkill canopend

sleep 5s
cd /home/debian/
#./ALEX_APP