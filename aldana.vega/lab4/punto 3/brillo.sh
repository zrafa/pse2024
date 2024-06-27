#!/bin/bash

cat /dev/ttyUSB0 | while read -n 1 num; do
    echo $num;
    sudo brightnessctl s $((${num}*100/9))%;
done