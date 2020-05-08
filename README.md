# RobotCANControl Project

RobotCANcontrol is a free and open source robotic development software stack. The project has been under development at the University of Melbourne in partnership with Fourier Intelligence for use with their X2 exoskeleton. The software has been designed to be extensible to any embeeded linux and CANopen enabled Robotic platform.

## The Robot CANcontrol project is made up of:

- Extensible Framework to represent most multi body robotic systems.
- Event driven State machine to develop custom applications for your Robot.
- Implementation of [Canopen Socket](https://github.com/CANopenNode/CANopenSocket) to provide an interface between CAN enabled embedded linux system and Canopen configured motor drivers/sensors.
- Documentation
- Fully functional application examples.

## Getting started with RobotCANControl

We will be running through building and testing a simple test statemachine (ExoTestMachine.cpp), the source code can be found in the apps folder of the root directory.

The current recommened and tested environemnt is Debian jesse 9.5 on a Beagle Bone black [Firmware](http://beagleboard.org/latest-images). Theoretically, we can build on other distros and linux platforms as well, but they have not been testd.

We currently have two options for building RobotCANControl. Building (slowly) on the target platform or building on your host machine (depending on your platform).

- macOSx, linux or Windows: Docker - [docker cross tools](https://hub.docker.com/r/alejandro4siana/cross-bbb-debian/)
- Windows only: [ GNU cross tools](https://gnutoolchains.com/download/)

### How to get the Project

Clone the project and CANopenSocket from git repository(CANopenSocket used in robot homing sequence):

    $ git clone https://github.com/capstonealex/exo.git
    $ git clone https://github.com/CANopenNode/CANopenSocket.git
    $ cd CANopenSocket
    $ git submodule init
    $ git submodule update

### Build ExoTestMachine

    $ cd /GitHub/exo/Refactor/
    $ make exe

### Transfer files to Linux platform

- Download [FileZilla](https://filezilla-project.org/) and connect to Beagle bone.
  > Username: debian
  > Password: temppwd
  > Transfer executible, CANopenNode folder and initRobot folders.

## Run Virtual ExoTestMachine

- SSH into Beagle Bone [tutorial](https://elinux.org/Beagleboard:Terminal_Shells) or similar linux board, use same user and pswrd as above.

## Run ExoTestMachine on X2

<!-- ### Event Driven State machine
explain me -->

### Documentation

View our [detailed documentation](https://exoembedded.readthedocs.io/en/latest/#alex-embedded-system-documentation) on all aspects of Robot CANcontrol.

View our source code documenrtation [doxygen](https://capstonealex.github.io/exo/index.html)

## Developer Information

- Documentation: https://exoembedded.readthedocs.io/en/latest/
- Project Repository: https://github.com/capstonealex/exo
- CanOpen Socket: https://github.com/CANopenNode/CANopenSocket

## License

Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License.

## Maintainers
