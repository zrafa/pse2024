stty -F /dev/ttyUSB0 speed 9600
cat /dev/ttyUSB0 | while read -n 1 num; do
	sudo brightnessctl s $(($num*100))
	echo $num
done
