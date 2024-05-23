stty -F /dev/ttyUSB0 speed 9600  # o 2400 la que necesiten
stdbuf -i0 -o0 cat /dev/ttyUSB0 | while read -n 1 tecla; do
xdotool key $tecla
done
