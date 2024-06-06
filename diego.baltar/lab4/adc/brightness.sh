#!/usr/bin/env bash

sudo cat /dev/ttyUSB0 | while read -n 1 num; do
  brightnessctl s $(($num*100))
done
