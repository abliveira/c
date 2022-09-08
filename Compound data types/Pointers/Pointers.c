/*
Referências:
    https://www.studytonight.com/c/programs/pointer/pointer-comparison-program

- Os ponteiros são mais eficientes no manuseio de matrizes em C e estruturas em C.
- Os ponteiros permitem que as referências funcionem e, assim, ajudam a passar da função como argumentos para outras funções.
- Os ponteiros também fornecem meios pelos quais uma função em C pode alterar seus argumentos de chamada.
- Reduz a duração do programa e seu tempo de execução também.
- Ele permite que a linguagem C suporte o gerenciamento dinâmico de memória.
- As variáveis de ponteiro devem sempre apontar para variáveis do mesmo tipo de dados.
- Por exemplo, se tivermos uma variável do tipo float e um ponteiro do tipo int, o C Compiler dará erro.

*/

#include<stdio.h>


int main (void) {

    int a = 10;
    
    int *ptr;   // declara um ponteiro
    ptr = &a;   // atribui valor ao ponteiro fornecendo o endereço da variável

    printf("Value at ptr is: %d \n", *ptr);
    printf("Address pointed by ptr is: %p \n\n", ptr);

    // Ao declarar uma variável de ponteiro, se não for atribuída a nada, ela conterá um valor lixo.
    // e isso pode levar a erros inesperados em seu programa. Portanto, é recomendável atribuir um valor nulo a ela.
    // Quando atribuímos Null a um ponteiro, isso significa que ele não aponta para nenhum endereço válido.
    // Nulo indica o valor 'zero'.
    int *ptr2 = NULL;

    // Pointer to Pointer Assignment in C
    // Podemos usar um operador de atribuição para atribuir valor a um ponteiro a outro
    // variável de ponteiro. Porém os tipos de ambos o ponteiro devem ser iguais.

    float b = 10;

    // declare two pointers
    int *p1, *p2;

    // assign value to pointer
    p1 = &b;    // Sim, está errado
    // assign value from one pointer to another
    p2 = p1;

    printf("Value at p1 and p2: %d %d \n", *p1, *p2);
    printf("Address pointed by p1 and p2: %p %p \n\n", p1, p2);


    // Pointer Type Conversion in C ----------------------------------------------
    // We can assign a pointer of one type to a pointer of another type by doing pointer type conversion.

    // 1. void * pointer
    // The pointers of type void * are known as Generic pointers, and they can be assigned to any other type
    // of pointer. Also, any other type of pointer can be assigned to a void * pointer.

    // 2. Pointer type conversion
    // For pointer type other than void *, we have to explicitly cast pointer from one type to another.
    // But this can lead to unexpected behaviour for incompatible datatypes.

    // For example, if we have a variable of type double, and we want to use a
    // pointer of type int to point to this variable. Even after using explicit cast,
    // the pointer will work as if it is pointing to a int type value. Now, a double
    // type is of 8 bytes whereas an int type is of 4 bytes, hence, 4 bytes of
    // information will be lost.

    // Let's see how we can use explicit cast for pointer conversion.

    double d = 1000.10;
    double e;
    int *p3;    // declara um ponteiro
    p3 = (int *) &d;   // Atribui valor ao ponteiro com cast
    e = *p3;    // valor de 'e' deveria ser o mesmo que 'd', mas não será

    printf("Value of d is: %f \n\n", e);  // Value of a is: -858993459.000000


    // Derefrencing Pointer in C ----------------------------------------------
    // Once a pointer has been assigned the address of a variable, the pointer is
    // dereferenced, using the indirection operator or dereferencing operator, which
    // is a *, to access the value of the variable.

    // For example, if we have,

    // int a  = 5;
    // int *ptr1 = &a;
    // float b = 5.5;
    // float *ptr2 = &b;

    // *ptr1 = 2 is equivalent to a = 2
    // (*ptr1)++ is equivalent to a++
    // float z = *ptr2 + 4.2 is equivalent to float z = b + 4.2;
    // Here is one complete program,

    int c;  
    c = 10;
    int *p = &c;     // declaring and initializing the pointer

    //prints the value of 'c'
    printf("%d\n", *p);  
    printf("%d\n", *&c);  
    //prints the address of 'c'
    printf("%u\n", &c);    
    printf("%u\n", p);     
    //prints address of 'p'
    printf("%u\n", &p);

    /*
    Ponteiro para um ponteiro em C (Double Pointer) -----------------------------------------------
    Ponteiros são usados para armazenar o endereço de outras variáveis de dados de dados semelhantes
    Mas se você deseja armazenar o endereço de uma variável de ponteiro, então você precisa
    um ponteiro para armazená -lo.Assim, quando uma variável de ponteiro armazena o endereço de outro
    Variável de ponteiro, é conhecida como ponteiro de variável de ponteiro ou ponteiro duplo.

    Syntax:
    int **p1;
    Here, we have used two indirection operator(*) which stores and points to the address of
     a pointer variable i.e, int *. 
    
    If we want to store the address of this (double pointer) variable p1, then the syntax would become:
    int ***p2
    */

    int  f = 10;
    int  *p4;       //this can store the address of variable f
    int  **p5; 
    /*
        this can store the address of pointer variable p4 only. 
        It cannot store the address of variable 'f' 
    */

    p4 = &f; // Obtém o endereço de f e o atribui ao ponteiro p4
    p5 = &p4; // Obtém o endereço de p4 e o atribui ao ponteiro p5

    printf("\nAddress of f = %u\n", &f);
    printf("Address of p4 = %u\n", &p4);
    printf("Address of p5 = %u\n", &p5);
    printf("Value at the address stored by p5 = %u (Adress of f)\n", *p5);
    printf("Value at the address stored by p4 = %d (Value of f)\n", *p4);
    printf("Value of **p5 = %d\n", **p5); //read this *(*p5)

    /*
    This is not allowed, it will give a compile time error-
    p5 = &f;
    printf("%u", p5);
    */


    // Exemplo: Pointer Comparison in C ---------------------------------------
    // In C language pointers can be compared if the two pointers are pointing to the same array.
    // All relational operators can be used for pointer comparison, but a pointer cannot Multiplied or Divided.
    // Below is a program on pointer comparison for same type of pointer:

	int *p6,*p7;
    p6 = (int *)1;
    p7 = (int *)2;
    
    if(p7 > p6)
        printf("\np7 is greater than p6\n");

	// Below is a program on pointer comparison for different type of pointer:
    int *p8;
    float *p9;
    p8 = (int *)1000;
    p9 = (float *)2000;
    
    if(p9 > p8)
       printf("p9 is greater than p8\n");

    return 0;
}