inline void delay_100us(volatile unsigned char n) // 1.1 + 98.9*n
{ 
        while(n>0){
                for(volatile unsigned char i = 0; i<10; i++){
                        for(volatile unsigned char j = 0; j<35; j++){
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
                                    "nop" "\n\t"
                                    "nop" "\n\t");
                }
                n--;
        }
}

