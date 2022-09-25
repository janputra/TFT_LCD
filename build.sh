#!/bin/bash

make
st-flash write ./build/TFT_LCD.bin 0x08000000
st-flash reset
