# Raspberry Pi Pico and ROS 2

[![License](https://img.shields.io/badge/License-Apache%202.0-blue.svg)](https://opensource.org/licenses/Apache-2.0)

## Getting Started

Here is a quick way to compile the example given in this repository.

### 1. Install Pico SDK

First, make sure the Pico SDK is properly installed and configured:

```bash
# Install dependencies
sudo apt install cmake gcc-arm-none-eabi doxygen libnewlib-arm-none-eabi
git clone --recurse-submodules https://github.com/raspberrypi/pico-sdk.git $HOME/pico-sdk

# Configure environment
echo "export PICO_SDK_PATH=$HOME/pico-sdk" >> ~/.bashrc
source ~/.bashrc
```

### 2. Compile Example

Once the Pico SDK is ready compile the example: 

```bash
mkdir build
cd build
cmake ..
make
```

To flash, hold the boot button, plug the USB and run:
```
cp pico_micro_ros_example.uf2 /media/$USER/RPI-RP2
```

### 3. Start Micro-ROS Agent
Micro-ROS follows the client-server architecture, so you need to start the Micro-ROS Agent:

```bash
docker run -it --rm -v /dev:/dev --privileged --net=host microros/micro-ros-agent:foxy serial --dev /dev/ttyACM0 -b 115200
```

## What files are relevant?
- `pico_ros.c`: Contains the board specific implementation of the serial transport (no change needed).
- `CMakeLists.txt`: CMake file.
- `pico_micro_ros_example.c`: The actual ROS 2 publisher.

## How Micro-ROS is compiled?

Micro-ROS is precompiled for Raspberry Pi Pico in [`uros_ws/firmware/build`](uros_ws/firmware/build).
If you want to compile it by yourself then check the [`uros_ws`](uros_ws) directory.

## How to use Pico SDK?

Here is a Raspberry Pi Pico C/C++ SDK documentation:  
https://datasheets.raspberrypi.org/pico/raspberry-pi-pico-c-sdk.pdf
## Purpose of the Project

This software is not ready for production use. It has neither been developed nor
tested for a specific use case. However, the license conditions of the
applicable Open Source licenses allow you to adapt the software to your needs.
Before using it in a safety relevant setting, make sure that the software
fulfills your requirements and adjust it according to any applicable safety
standards, e.g., ISO 26262.

## License

This repository is open-sourced under the Apache-2.0 license. See the [LICENSE](LICENSE) file for details.

For a list of other open-source components included in this repository,
see the file [3rd-party-licenses.txt](3rd-party-licenses.txt).

## Known Issues/Limitations

There are no known limitations.
