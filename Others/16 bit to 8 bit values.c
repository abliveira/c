#include <stdio.h>

int main() {

  for (int i = 0; i < 10000; i++) {

    int sixteen_bit_val = i;
    printf("%d\t", sixteen_bit_val);

    short int lo_byte = sixteen_bit_val & 0xFF;
    short int hi_byte = sixteen_bit_val >> 8;

    printf("%d\t", lo_byte);
    printf("%d\t", hi_byte);

    int restored_sixteen_bit_val = (hi_byte << 8) | (lo_byte & 0xff);
    printf("%d\n", restored_sixteen_bit_val);
  }
  
  return 0;
}
