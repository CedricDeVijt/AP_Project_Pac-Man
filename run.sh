#!/bin/bash

# Build
mkdir -p build
cd build
cmake ..
make

# Run
cd ..
./build/AP_Project_Pac_Man