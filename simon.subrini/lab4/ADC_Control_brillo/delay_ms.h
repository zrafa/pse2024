inline void delay_ms(volatile unsigned int n)
{
        while(n>0){
                for(volatile unsigned char i = 0; i<100; i++){
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
