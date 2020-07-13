#include <stdio.h>

// Uma Union permite armazenar diferentes tipos de dados no mesmo local de memória. 
// É como uma estrutura porque tem membros. No entanto, uma variável de união usa o mesmo local de memória 
//   para todos os seus membros e apenas um membro por vez pode ocupar o local de memória.
//Os membros da união podem ser de qualquer tipo de dados, incluindo tipos básicos, seqüências de caracteres, 
//   matrizes, ponteiros e estruturas.
// O membro com o maior tipo de dado determina o tamanho da memória da Union. 
// Unions ajudam a limitar a fragmentação da memória.

union val {
    int int_num;
    float fl_num;
    char str[20]; 
};

// Unions podem estar presentes dentro de Structs
typedef struct {
    char make[20];
    int model_year;
    int id_type; /* 0 for id_num, 1 for VIN */
    union {
        int id_num;
        char VIN[20]; 
    } id;
} vehicle;


union type {
    int i_val;
    float f_val;
    char ch_val;
};



int main() {
    union val u1;
    union val u2;
    u1.int_num = 42;
    
    // É possível atribuir o valor de uma Union a outra:
    u2 = u1;
    
    printf("%d\n\n", u2.int_num);
    
    
    // Para acessar os membros de uma variável Union, deve se usar o operador ponto entre o nome da variável e o nome do membro
    //  Quando a atribuição é realizada, o local da memória de união será usado para esse membro até que outra atribuição seja realizada
    // Tentar acessar um membro que não está ocupando o local da memória provoca resultados inesperados

    union val test;
    
    test.int_num = 123;
    test.fl_num = 98.76;
    strcpy(test.str, "hello");
    
    printf("%d\n", test.int_num);
    printf("%f\n", test.fl_num);
    printf("%s\n", test.str);
    
    
    // Para acessar a variável Union dentro da Struct, são necessários dois operadores ponto
    vehicle car1;
    strcpy(car1.make, "Ford");
    car1.model_year = 2017;
    car1.id_type = 0;
    car1.id.id_num = 123098;
    
    printf("Car %s, %d", car1.make, car1.model_year);
    
    
    // Um vetor ma matriz pode armazenar elementos de qualquer tipo de dados, incluindo Unions
    // É importante ter em mente que apenas um membro da Union pode armazenar dados para cada elemento do vetor
    // Após declarar um vetor de Unions, um elemento é acessível com o número do índice
    // O operador de ponto é então usado para acessar membros da união
    // Um vetor armazena valores de apenas mesmo tipo de dado. Vetores de Unions permitem armazenar valores de diferentes tipos
    union type arr[3];
    arr[0].i_val = 42;
    arr[1].f_val = 3.14;
    arr[2].ch_val = 'x';
    printf("1st element is %d, 2nd is %f, and the 3rd is %c", arr[0].i_val, arr[1].f_val, arr[2].ch_val);
    
    return 0;
}
