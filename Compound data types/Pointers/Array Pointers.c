/*
Referências:
  https://www.studytonight.com/c/pointers-with-array.php
  https://www.studytonight.com/c/programs/pointer/array-of-pointers
  https://www.studytonight.com/c/programs/pointer/pointer-increment-and-decrement


Function pointers apontam para código executável para uma função na memória
Os ponteiros de função podem ser armazenados em uma matriz ou transmitidos como
 argumentos para outras funções

*/

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


int main (void) {

    // Exemplo 1
    int a[3] = {1, 2, 3};
    int *p = a;    
    for (int i = 0; i < 3; i++) {
        printf("%d", *p);
        p++;
    }
    printf("\n\n");


    // Exemplo 2
    int var[]={10, 20, 30, 40, 50}; // initializing an array(here var) of int pointers

    //ptr is an array of int pointers i.e. it stores the address of each array element
    int *ptr[5];

    for(int i = 0; i < 5; i++) {
    // Assign the address of each of the array element to the ptr array
        ptr[i] = &var[i];
    }
    for(int i = 0; i < 5; i++) {
        /*
        ptr[i] stores the address of the element var[i]. 
        Hence, *ptr[i] returns the value of the element 
        stored at location ptr[i]
        */
        printf("Value of var[%d] = %i\n", i, *ptr[i]);
        //Here ptr[i] stores the address of the element var[i]. Hence,
        // *ptr[i] returns the value of the element stored at location var[i].
    }
    printf("\n");


    // Exemplo
    const int MAX = 3;
    int var2[] = {100, 200, 300};
    int *ptr2;

    // storing address of the first element of the array in pointer variable
    ptr2 = var2;

    for(int i = 0; i < MAX; i++) {
        printf("Address of var2[%d] = %x \n", i, ptr2);
        printf("Value of var2[%d] = %d \n", i, *ptr2);
        ptr2++; // move to the next location
    }
    printf("\n");

    // Exemplos
    int var3[] = {100, 200, 300};
    int *ptr3;

    // storing address of the last element of the array in pointer variable
    ptr3 = &var3[MAX-1];

	for(int i = MAX; i > 0; i--) {
    	printf("Address of var3[%d] = %x \n", i, ptr3);
        printf("Value of var3[%d] = %d \n", i, *ptr3);
        ptr3--; // move to the previous location
	}
    printf("\n");


    // Exemplo
    // Programa para acessar a matriz de Char Pointers
    // Matriz de Pointers Char é usado para acessar a string completa apenas usando
    // O endereço do primeiro char (endereço base) de cada string.

    char *names[] = {"Google", "Amazon", "Facebook", "Apple"}; // initializing an array(here names) of char pointers

    for(int i = 0; i < 4; i++) {
        printf("Value of names[%d] = %s\n", i, names[i]);
        // This statement is used for printing the complete name just using the
        // pointer to the first character of each element of the names array.
    }


    /*
    Pointer to Multidimensional Array -----------------------------------------
    Let's see how to make a pointer point to a multidimensional array. In a[i][j],
    a will give the base address of this array, even a + 0 + 0 will also give the
    base address, that is the address of a[0][0] element.

    Syntax:
    *(*(a + i) + j)
    */


    /* 
    Pointer and Character strings ---------------------------------------------
    Pointer is used to create strings. Pointer variables of char type are treated
    as string.

    char *str = "Hello";
    The above code creates a string and stores its address in the pointer variable
    str. The pointer str now points to the first character of the string "Hello".

    The string created using char pointer can be assigned a value at runtime.
    char *str;
    str = "hello";    
    The content of the string can be printed using printf() and puts().
    printf("%s", str);
    puts(str);
    str is a pointer to the string and also name of the string. Therefore we do not
    need to use indirection operator *.
    */


    /*
    Array of Pointers
    Pointers are very helpful in handling character arrays with rows of varying lengths.
    Pointer with character array in c
    In the second approach memory wastage is more, hence it is preferred to use pointer in such cases.
    */
    char *name1[3] = { 
        "Adam",
        "chris",
        "Deniel"
    };
    //without pointer
    char name2[3][20] = { 
        "Adam",
        "chris",
        "Deniel"
    };


    // Exemplo: Concatenate Strings using Pointer -----------------------------
    char jj[100], kk[100];

    printf("\nEnter the first string: ");
    gets(jj);   // inputting first string

    printf("Enter the second string to be concatenated: ");
    gets(kk);   // inputting second string

    char *j = jj;
    char *k = kk;

    // pointing to the end of the 1st string
    while(*j) {   // till it doesn't point to NULL-till string is not empty
        j++;    // point to the next letter of the string
    }
    while(*k) {   // till second string is not empty
        *j = *k;
        k++;
        j++;
    }
    *j = '\0';  // string must end with '\0'
    printf("The string after concatenation is: %s ", jj);


    // Exemplo: Program to Reverse a String using Pointer ---------------------
    char inpStr[100];
    char rev[100];
    char *sptr = inpStr; // sptr stores the base address of the inpStr
    char *rptr = rev; // rptr stores the base address of the reverse
    int ind = -1;

    printf("\n\nEnter a string: ");
    scanf("%s", inpStr);

    // storing the ending address of inpStr in sptr
    while(*sptr) {
        sptr++;
        ind++; // ind is the index of the end location
    }

    // storing the string inpStr in rev in reverse order
    while(ind >= 0) {
        /*
            First decrementing then using as it stores 
            the location after the end location due to above while loop
        */
        sptr--; 
        *rptr = *sptr;  // storing the value in sptr in rptr
        rptr++; // pointing to next location
        ind--;    // decrementing the index
    }
    /*
        String should always end with '\0' so explicitly 
        putting it at the end of the string
    */
    *rptr = '\0'; 
    rptr = rev; // restoring the base address of the reverse string

    // storing the reverse string in the original string
    while(*rptr) {
        *sptr = *rptr;
        sptr++;
        rptr++;
    }
    printf("Reverse of the string is: %s ", inpStr);

    // Exemplo ----------------------------------------------------------------
    int x, y, choice, result;
    // Um ponteiro de função é declarado no seguinte formato: return_type (*func_name)(parameters) 
    int (*op[4])(int, int) = {add, subtract, multiply, divide};
    // A associação ao ponteiro à função pode ser feita na declaração, como acima, ou após. Ex: ptr = func;
    
    printf("\n\nEnter two integers: ");
    scanf("%d%d", &x, &y);
    printf("Enter 0 to add, 1 to subtract, 2 to multiply, or 3 to divide: ");
    scanf("%d", &choice);
    result = op[choice](x, y); // Choice é o índice para o vetor de funções
    printf("\n %d", result);
      
    return 0;
}