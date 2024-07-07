#stty -F /dev/ttyUSB0 speed 9600
cat /dev/ttyUSB0 | while read -n1 num; do 
    brightnessctl s $(($num*10000));
    #echo $num;
done
