#include <stdio.h>

int main() {

  for (int i = 0; i < 10000; i++) {
    
    // Gera uma variável de exemplo do tipo int (16 bit)
    int sixteen_bit_val = i;
    printf("%d\t", sixteen_bit_val);

    // Quebra a variável 16 bit em duas de 8 bit (2 bytes)
    short int lo_byte = sixteen_bit_val & 0xFF;
    short int hi_byte = sixteen_bit_val >> 8;
    printf("%d\t", lo_byte);
    printf("%d\t", hi_byte);
    
    // Concatena as duas variáveis em uma novamente
    int restored_sixteen_bit_val = (hi_byte << 8) | (lo_byte & 0xff);
    printf("%d\n", restored_sixteen_bit_val);
  }
  
  return 0;
}
