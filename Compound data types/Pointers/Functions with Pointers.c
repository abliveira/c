/*
Referências:
    https://www.studytonight.com/c/pointer-with-function-in-c.php

Function pointers apontam para código executável para uma função na memória

Maneiras seguras de retornar um ponteiro válido.
- Use o argumento utilizado pelas funções. Como o argumento passado para as
 funções é declarado dentro da função de chamada, eles também viverão fora da função.
- Ou use variáveis locais estáticas dentro da função e retorne -as.Como as variáveis
 estáticas têm uma vida útil até que a função main() saia, elas estarão
 disponíveis durante o programa.

Obs: Passagem de arrays para funções em "Array Pointers.c"

*/


#include <stdio.h>

/*
Ponteiros como argumento da função em c
O parâmetro de ponteiro como função é usado para manter endereços de argumentos
 aprovados durante a chamada de função.Isso também é conhecido como chamado por
 referência.Quando uma função é chamada por referência, qualquer alteração feita
 na variável de referência afetará a variável original.
Exemplo: Swapping two numbers using Pointer

    pointer 'a' and 'b' holds and 
    points to the address of 'm' and 'n'
*/
void swap(int *a, int *b) { // Cria ponteiros que são associados aos endereços recebidos

    int temp = *a; // Guarda o valor apontado por a
    *a = *b;    // O valor apontado por a passa a ser o valor apontado por b
    *b = temp;  // O valor apontado por b passa a ser o valor anteriormente apontado por a

}

/* Funções de retorno de variáveis de ponteiro
Uma função também pode retornar um ponteiro para a função de chamada. É preciso
 ter cuidado, porque as variáveis locais de função não vivem fora da função. Eles
 têm escopo apenas dentro da função. Portanto, se você retornar um ponteiro conectado
 a uma variável local, esse ponteiro estará apontando para nada quando a função terminar.
*/
int* larger(int *x, int *y) {
    if(*x > *y)
        return x;
    else
        return y;
}

/*
Ponteiro para funções
É possível declarar um ponteiro apontando para uma função que pode ser usada
 como argumento em outra função.
Um ponteiro para uma função é declarado da seguinte maneira:
type (*pointer-name)(parameter);

Exemplo:
int (*sum)();   //legal declaration of pointer to function
int *sum();     //This is not a declaration of pointer to function
A function pointer can point to a specific function when it is assigned the name of
 that function.

int sum(int, int);
int (*s)(int, int);
s = sum;
Here s is a pointer to a function sum. Now sum can be called using function pointer
 s along with providing the required argument values.

s (10, 20);
*/
int sum(int x, int y) {

    return x+y;
}

// Exemplo 4
void* function(int *x) {

    printf("*x = %d", *x);
}

int main() {
    
    // Exemplo 1
    int m = 10, n = 20;
    printf("m = %d\n", m);  // m = 10
    printf("n = %d\n", n);  // n = 20

    swap(&m, &n);    //passing address of m and n to the swap function
    printf("After Swapping:\n");
    printf("m = %d\n", m);      // m = 20
    printf("n = %d\n\n", n);    // n = 10


    // Exemplo 2
    int a = 15;
    int b = 92;
    int *p;
    p = larger(&a, &b);         // Envia os endereços das variáveis a e b
    printf("%d is larger\n\n", *p); // Imprime o valor apontado por p: 92 is larger


    // Exemplo 3
    int (*fp)(int, int);
    fp = sum; // o ponteiro criado é associado à função
    int s = fp(10, 15); // o ponteiro pode ser usado da mesma forma da função
    printf("Sum is %d\n\n", s); // Imprime 25


    // Exemplo 4
    // Algumas declarações podem ficar complicadas. Por exemplo:
    void *(*foo) (int*);
    // parece complexo, mas é muito simples. Nesse caso (*foo) é um ponteiro
    // para a função, cujo argumento é do tipo int* e o tipo de retorno é void*.
    foo = function; // o ponteiro criado é associado à função
    void* k = foo(&m);

    return 0;
}