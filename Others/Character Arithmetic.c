/*
https://www.geeksforgeeks.org/character-arithmetic-c-c/

A aritmética de caracteres é usada para implementar operações aritméticas como adição,
subtração, multiplicação, divisão em caracteres na linguagem C e C++.
Em caractere aritmético, o caractere converte em valor inteiro para executar a tarefa.
Para este valor ASCII é usado.
Ele é usado para executar a ação das strings.

*/

#include <stdio.h>

int main(void) {

    char ch1 = 125, ch2 = 10;
    ch1 = ch1 + ch2;
    printf("%d\n", ch1);
    printf("%c\n", ch1 - ch2 - 4);

    char value1 = 'a';
    char value2 = 'b';
    char value3 = 'z';

    char num1 = value1 + 3;
    char num2 = value2 - 1;
    char num3 = value3 + 2;
    
    printf("numerical value=%d\n", num1);
    printf("numerical value=%d\n", num2);
    printf("numerical value=%d\n", num3);
    return 0;
}