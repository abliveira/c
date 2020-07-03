#include <stdio.h>

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
  int (*op[4])(int, int) = {add, subtract, multiply, divide};  // Declara o vetor de ponteiros de função
  printf("Enter two integers: ");
  scanf("%d%d", &x, &y);
  printf("Enter 0 to add, 1 to subtract, 2 to multiply, or 3 to divide: ");
  scanf("%d", &choice);
  result = op[choice](x, y); // Choice é o índice para o vetor de funções
  printf("\n %d", result);
    
  return 0;
}
