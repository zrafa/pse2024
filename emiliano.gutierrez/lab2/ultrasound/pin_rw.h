
/*
En este archivo tengo dos funciones: una para escribir un pin digital y otra para 
realizar la lectura de una entrada digital
*/
inline unsigned char read_pin(unsigned char pinx,volatile unsigned char * dir_pin)
{
    /*
    pinx es el numero de pin que quiero leer, sin importar el puerto al que pertenece.
    
    *dir_pin es la direccion del registro de lectura del puerto correspondiente al
    pin definido con pinx.
    
    */
    unsigned char input = (*dir_pin & pinx)>>(pinx-1);
    return input;
}

inline unsigned char write_pin(unsigned char value, unsigned char pinx,volatile unsigned char * dir_port)
{
    /*
    value es el valor booleano que quiero escribir en el pin (1 o 0)
    
    pinx es el numero de pin que quiero escribir, sin importar el puerto al que pertenece.
    
    *dir_port es la direccion del registro de lectura del puerto correspondiente al
    pin definido con pinx.
     
    */
    if (value == 1)
        *dir_port = *dir_port | pinx;
    else 
        *dir_port = *dir_port & ~pinx;
}
