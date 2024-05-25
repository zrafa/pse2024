#!/bin/bash

stdbuf -i0 -o0 cat /dev/ttyUSB0 | while read -n 1 num; do
    ((num++))
    echo $num;
    brightnessctl s $(($num * 10))%;
done