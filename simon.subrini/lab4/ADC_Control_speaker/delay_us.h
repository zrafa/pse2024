inline void delay_us(volatile unsigned char n){
        while(n>0){
                asm volatile ("nop" "\n\t"
                              "nop" "\n\t"
                              "nop" "\n\t"
                              "nop" "\n\t"
                              "nop" "\n\t"
                              "nop" "\n\t"
                              "nop" "\n\t"
                              "nop" "\n\t");
                n--;
        }
}

