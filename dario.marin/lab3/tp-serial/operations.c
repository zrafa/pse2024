
unsigned char get_bit(unsigned char *reg, unsigned char n) {
  return (*reg & (1 << n)) ? 1 : 0;
}

void set_bit(unsigned char *reg, char n) { *reg |= (1 << n); }

void clear_bit(unsigned char *reg, char n) { *reg &= ~(1 << n); }

void toggle_bit(unsigned char *reg, unsigned char n) { *reg ^= (1 << n); }

void write_bits(unsigned char *reg, unsigned char n) { *reg = n; }