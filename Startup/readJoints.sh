#!/bin/bash

cd /home/debian/CANopenSocket/canopencomm


echo "Lhip Lknee RHip Rknee LAnkle RAnkle"
echo "Current Position"
./canopencomm [1] 1 read 0x6063 0 i32
./canopencomm [1] 2 read 0x6063 0 i32
./canopencomm [1] 3 read 0x6063 0 i32
./canopencomm [1] 4 read 0x6063 0 i32
./canopencomm [1] 5 read 0x6063 0 i32
./canopencomm [1] 6 read 0x6063 0 i32
echo "Status Word"
./canopencomm [1] 1 read 0x6041 0 i16
./canopencomm [1] 2 read 0x6041 0 i16
./canopencomm [1] 3 read 0x6041 0 i16
./canopencomm [1] 4 read 0x6041 0 i16
./canopencomm [1] 5 read 0x6041 0 i16
./canopencomm [1] 6 read 0x6041 0 i16
echo "Control Word"
./canopencomm [1] 1 read 0x6040 0 i16
./canopencomm [1] 2 read 0x6040 0 i16
./canopencomm [1] 3 read 0x6040 0 i16
./canopencomm [1] 4 read 0x6040 0 i16
./canopencomm [1] 5 read 0x6040 0 i16
./canopencomm [1] 6 read 0x6040 0 i16