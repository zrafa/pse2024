inline void delay_us(volatile int us) {
  // PARA 16MHZ
  if(us<=40){
    while (us--) {
    asm volatile(
        "nop"
        "\n\t"
        "nop"
        "\n\t"
        "nop"
        "\n\t"
        "nop"
        "\n\t"
        "nop"
        "\n\t"
        "nop"
        "\n\t"
        "nop"
        "\n\t");
  }
  asm volatile(
    "nop"
    "\n\t"
    "nop"
    "\n\t"
    "nop"
    "\n\t"
    "nop"
    "\n\t"
    "nop"
    "\n\t"
    "nop"
    "\n\t"
    "nop"
    "\n\t"
    "nop"
    "\n\t"
    "nop"
    "\n\t"
    "nop"
    "\n\t"
    "nop"
    "\n\t"
    "nop"
    "\n\t"
    "nop"
    "\n\t"
    "nop"
    "\n\t"
  );
  }else{
    while (us--) {
    asm volatile(
        "nop"
        "\n\t"
        "nop"
        "\n\t"
        "nop"
        "\n\t"
        "nop"
        "\n\t"
        "nop"
        "\n\t"
        "nop"
        "\n\t"
        "nop"
        "\n\t"
        "nop"
        "\n\t"
        "nop"
        "\n\t");
  }
  }
  
  
 
}