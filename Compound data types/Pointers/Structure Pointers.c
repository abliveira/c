/*
Referências:
    https://www.studytonight.com/c/pointers-to-structure-in-c.php

Se tivermos uma variedade de estruturas, cada estrutura pode
potencialmente ser muito grande.
Para classificar essa matriz, muita cópia de memória e
Os movimentos são necessários, o que pode ser caro.
Para eficiência, podemos usar uma variedade de indicadores

Pointer to Array of Structures in C
Like we have array of integers, array of pointers etc, we can also have array
of structure variables. And to use the array of structure variables efficiently,
we use pointers of structure type. We can also have pointer to a single structure
variable, but it is mostly used when we are dealing with array of structure variables.

*/
// Exemplo 1
struct Book {
    char name[10];
    int price;
};


// Exemplo 2
struct my_structure {
    char name[20];
    int age;
    int id;
};


int main() {

    // Exemplo 1
    struct Book a;      //Single structure variable
    struct Book* ptr;   //Pointer of Structure type
    ptr = &a;
 
    struct Book b[10];  //Array of structure variables
    struct Book* p;     //Pointer of Structure type
    p = &b;


    // Exemplo 2
    // Accessing Structure Members with Pointer
    // To access members of structure using the structure variable, we used the
    // dot . operator. But when we have a pointer of structure type, we use 
    // arrow -> to access structure members.
    struct my_structure variable = {"JOHN", 35, 1};
    struct my_structure *ptr2;
    ptr2 = &variable;

    printf("NAME: %s\n", ptr2->name);
    printf("AGE: %d\n", ptr2->age);
    printf("ID: %d\n", ptr2->id);
    
    // Outra forma de acessar é usando parenteses mais o operador
    printf("NAME: %s\n", (*ptr2).name);
    return 0;
}