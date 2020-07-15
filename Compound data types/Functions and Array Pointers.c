#include <stdio.h>

// Function pointers apontam para código executável para uma função na memória
// Os ponteiros de função podem ser armazenados em uma matriz ou transmitidos como argumentos para outras funções

int add (int x, int y) {
  return(x + y);
}

int subtract (int x, int y) {
  return(x - y);
}

int multiply (int x, int y) {
  return(x * y);
}

int divide (int x, int y) {
  if (y != 0)
    return (x / y);
  else
    return 0;
} 

int main() {
  int x, y, choice, result;
  
  // Um ponteiro de função é declarado no seguinte formato: return_type (*func_name)(parameters) 
  int (*op[4])(int, int) = {add, subtract, multiply, divide};
  // A associação ao ponteiro à função pode ser feita na declaração, como acima, ou após. Ex: ptr = func;
  
  printf("Enter two integers: ");
  scanf("%d%d", &x, &y);
  printf("Enter 0 to add, 1 to subtract, 2 to multiply, or 3 to divide: ");
  scanf("%d", &choice);
  result = op[choice](x, y); // Choice é o índice para o vetor de funções
  printf("\n %d", result);
    
  return 0;
}
