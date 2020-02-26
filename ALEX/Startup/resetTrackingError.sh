    
#!/bin/bash

cd /home/debian/CANopenSocket/canopencomm

#echo "Clearing Knee Error"
./canopencomm [1] 1 write 0x2183 0 i32 512
./canopencomm [1] 2 write 0x2183 0 i32 512
./canopencomm [1] 3 write 0x2183 0 i32 512
./canopencomm [1] 4 write 0x2183 0 i32 512
