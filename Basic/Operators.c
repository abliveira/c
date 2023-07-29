/*
    Algumas peculiaridades com operadores aritméticos
*/

#include<stdio.h>

int main (void) {


    // Arithmetic Operators -------------------------------

    // Resto de divisão (Modulo)
    int a = 10, b = 3;
    printf("Quociente = %d\n", a/b);
    printf("Resto = %d\n", a%b);
    // Se é par
    if (a%2==0)
        printf("A Par\n");
    if (b%2!=0)
        printf("B impar\n");
    printf("\n");

    // Operadores de incremento
    int x = 8;
    printf("%d\n", x); // x original, imprime 8
    printf("%d\n", x + 1); // não altera x, mas imprime 9
    printf("%d\n", x); // x original
    printf("%d\n", ++x); // altera x para 9 e retorna 9
    printf("%d\n", x);  // x foi incrementado para 9
    x = 8; // reseta
    printf("%d\n", x++); // primeiro retorna, depois incrementa. logo imprime 8
    printf("%d\n", x); // imprime 9, pois x foi incrementado para 9
    printf("\n");


    // Operador Not (!)
    // Poder ser usado para converter inteiros para 1, quando usado duas vezes:
    int y = 10;
    printf("y = %d\n", y); // y é convertido de 10 para 0
    printf("y = %d\n", !y); // y é convertido de 10 para 0
    printf("y = %d\n", !!y); // y é convertido de 10 para 0, e então, de 0 para 1

    return 0;
}