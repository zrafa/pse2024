
inline unsigned char gpio_pin (unsigned char pin,char operation[])
{
    volatile unsigned char * DIR_PORT;
    volatile unsigned char * DIR_PIN;
    unsigned char pin_b = 0;
    unsigned char input = 0;
    
    switch (pin) {
        case 0 ... 7:
            DIR_PORT = (unsigned char *) 0x2B; //DIR_PORTD
            DIR_PIN = (unsigned char *) 0x29; //PIND
            break;
        case 8 ... 13:
            DIR_PORT = (unsigned char *) 0x25; //DIR_PORTB
            DIR_PIN = (unsigned char *) 0x23; //PINB
            pin -= 8;
            break;
        case 14 ... 19:
            DIR_PORT = (unsigned char *) 0x28; //DIR_PORTC
            DIR_PIN = (unsigned char *) 0x26; //PINC
            pin -= 14;
            break;
        default:
            break;   
    } 

    pin_b = 1 << pin;
    
    if (operation == "ON")
        *DIR_PORT = *DIR_PORT | pin_b;
    else if (operation == "OFF")
        *DIR_PORT = *DIR_PORT & ~pin_b;
    else if (operation == "TOGGLE")
        *DIR_PORT = *DIR_PORT ^ pin_b;
    else if (operation == "GET")
        input = (*DIR_PIN & pin_b) >> pin;
        return input;   
}

inline void gpio_mode(unsigned char pin,char inout[])
{
    volatile unsigned char * DIR_PORT;
    volatile unsigned char * DIR_DDR;
    unsigned char pin_b = 0;
    
    switch (pin) {
        case 0 ... 7:
            DIR_PORT = (unsigned char *) 0x2B; //DIR_PORTD
            DIR_DDR = (unsigned char *) 0x2A; //DIR_DDRD
            break;
        case 8 ... 13:
            DIR_PORT = (unsigned char *) 0x25; //DIR_PORTB        
            DIR_DDR = (unsigned char *) 0x24; //DIR_DDRB
            pin -= 8;
            break;
        case 14 ... 19:
            DIR_PORT = (unsigned char *) 0x28; //DIR_PORTC        
            DIR_DDR = (unsigned char *) 0x27; //DIR_DDRC
            pin -= 14;
            break;
        default:
            break;
    }    
    
    pin = 1 << pin;
    
    if (inout == "INPUT") {
        *DIR_DDR = *DIR_DDR & ~pin;
        *DIR_PORT = *DIR_PORT | pin; //Activo resistencia de pull up     
    }
    else if (inout == "OUTPUT") {
        *DIR_PORT = *DIR_PORT & ~pin; //Siempre inicializo en 0 las salidas
        *DIR_DDR = *DIR_DDR | pin;        
    }
}

inline void gpio_write (char PORT[],char value)
{
    volatile unsigned char * DIR_PORT;
    
    if (PORT == "B") {
        DIR_PORT = (unsigned char *) 0x25; //DIR_PORTB
    }
    else if (PORT == "C") {
        DIR_PORT = (unsigned char *) 0x28; //DIR_PORTC
    }
    else if (PORT == "D") {
        DIR_PORT = (unsigned char *) 0x2B; //DIR_PORTD
    }
    
    *DIR_PORT = value;
}

inline unsigned char gpio_read (char PORT[])
{
    volatile unsigned char * DIR_PIN;
    unsigned char input = 0;
        
    if (PORT == "B") {
        DIR_PIN = (unsigned char *) 0x23; //DIR_PINB
    }
    else if (PORT == "C") {
        DIR_PIN = (unsigned char *) 0x26; //DIR_PINC
    }
    else if (PORT == "D") {
        DIR_PIN = (unsigned char *) 0x29; //DIR_PIND
    }
    
    input = *DIR_PIN;
    return input;  
}
