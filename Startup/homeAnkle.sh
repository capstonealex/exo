# Test to Copy-Paste into Terminal to run joints
cd /home/debian/CANopenSocket/canopencomm

./canopencomm [1] 6 write 0x2031 0 i8 0
./canopencomm [1] 5 write 0x2031 0 i8 0
#Command to switch current limit
./canopencomm [1] 5 write 0x2204 0 i8 30
./canopencomm [1] 6 write 0x2204 0 i8 30
#Commands to enable ankle actuators
./canopencomm [1] 5 write 0x6040 0 i16 6
./canopencomm [1] 5 write 0x6040 0 i16 15
./canopencomm [1] 6 write 0x6040 0 i16 6
./canopencomm [1] 6 write 0x6040 0 i16 15

#Change drive mode to position mode and drive to negative mechanical stops
./canopencomm [1] 6 write 0x6060 0 i8 1
./canopencomm [1] 6 write 0x6081 0 i32 100000
./canopencomm [1] 6 write 0x6083 0 i32 1000000
./canopencomm [1] 6 write 0x6084 0 i32 1000000
./canopencomm [1] 6 write 0x607A 0 i32 -- -1500000
./canopencomm [1] 6 write 0x6040 0 i16 47
./canopencomm [1] 6 write 0x6040 0 i16 63
./canopencomm [1] 5 write 0x6060 0 i8 1
./canopencomm [1] 5 write 0x6081 0 i32 100000
./canopencomm [1] 5 write 0x6083 0 i32 1000000
./canopencomm [1] 5 write 0x6084 0 i32 1000000
./canopencomm [1] 5 write 0x607A 0 i32 -- -1500000
./canopencomm [1] 5 write 0x6040 0 i16 47
./canopencomm [1] 5 write 0x6040 0 i16 63
# Wait for movement to complete
sleep 15s

#Command to reset the current home position
./canopencomm [1] 5 write 0x6060 0 i8 6
./canopencomm [1] 5 write 0x607C 0 i32 800000
./canopencomm [1] 5 write 0x6098 0 i8 35
./canopencomm [1] 5 write 0x6040 0 i16 47
./canopencomm [1] 5 write 0x6040 0 i16 63	
./canopencomm [1] 6 write 0x6060 0 i8 6
./canopencomm [1] 6 write 0x607C 0 i32 800000
./canopencomm [1] 6 write 0x6098 0 i8 35
./canopencomm [1] 6 write 0x6040 0 i16 47
./canopencomm [1] 6 write 0x6040 0 i16 63
#Set Joint Limits
./canopencomm [1] 5 write 0x2022 1 i32 -- -800000
./canopencomm [1] 5 write 0x2022 2 i32 800000
./canopencomm [1] 6 write 0x2022 1 i32 -- -800000
./canopencomm [1] 6 write 0x2022 2 i32 800000
# #Command to switch current limit
./canopencomm [1] 5 write 0x2204 0 i8 80
./canopencomm [1] 6 write 0x2204 0 i8 80
./canopencomm [1] 5 write 0x6040 0 i16 6
./canopencomm [1] 5 write 0x6040 0 i16 15
./canopencomm [1] 6 write 0x6040 0 i16 6
./canopencomm [1] 6 write 0x6040 0 i16 15
./canopencomm [1] 5 write 0x6060 0 i8 1
./canopencomm [1] 5 write 0x6081 0 i32 500000
./canopencomm [1] 5 write 0x6083 0 i32 1000000
./canopencomm [1] 5 write 0x6084 0 i32 1000000
./canopencomm [1] 5 write 0x607A 0 i32 0
./canopencomm [1] 5 write 0x6040 0 i16 47
./canopencomm [1] 5 write 0x6040 0 i16 63
./canopencomm [1] 6 write 0x6060 0 i8 1
./canopencomm [1] 6 write 0x6081 0 i32 500000
./canopencomm [1] 6 write 0x6083 0 i32 1000000
./canopencomm [1] 6 write 0x6084 0 i32 1000000
./canopencomm [1] 6 write 0x607A 0 i32 0
./canopencomm [1] 6 write 0x6040 0 i16 47
./canopencomm [1] 6 write 0x6040 0 i16 63
# Set encoder mode: position sync to encoder master
./canopencomm [1] 6 write 0x2031 0 i8 24
./canopencomm [1] 5 write 0x2031 0 i8 24