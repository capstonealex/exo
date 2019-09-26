# Canopend implementation for GPIO button read

1. To compile this, copy entire `BeagleNode` folder to BBB.
2. Change directory to canopend `cd BeagleNode/canopend`
3. Compile using `make`

# Modifying button read 

1. Button read function is located in `BeagleNode/canopend/app/application.cpp`
2. It currently reads BBB GPIO pin 9.15 and 9.23. Add more buttons as needed. Refer to BBB pinout to see which are available GPIO pins.
3. Do not using pins 9.24 and 9.26 as these are used for CANbus.
