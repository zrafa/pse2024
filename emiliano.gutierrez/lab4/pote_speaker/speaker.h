
void tone_on(unsigned char pinx, float freq)
{   
    // dur entra en cantidad de mseg
    float T = 1000/freq; // en mseg           
    gpio_pin(pinx,"ON");
    delay_ms(T/2);
    gpio_pin(pinx,"OFF");
    delay_ms(T/2);
}
