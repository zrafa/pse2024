inline void delay_10us(volatile unsigned char n)  // 0.91 + 9.87*n
{
        while(n>0){
                for(volatile unsigned char i = 0; i<35; i++){
                        asm volatile ("nop" "\n\t");
                }
                asm volatile ("nop" "\n\t"
                            "nop" "\n\t"
                            "nop" "\n\t"
                            "nop" "\n\t"
                            "nop" "\n\t"
                            "nop" "\n\t"
                            "nop" "\n\t"
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

