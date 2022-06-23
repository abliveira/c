#include <stdio.h>

// (Não inclui a parte de ponteiro de estrutras nessa aula)

// Structs são um grupo de diferentes tipos de variáveis definidas pelo usuário
// São úteis para agrupar variáveis relacionadas entre si


// Ao criar uma struct declarando os seus membros e depois dando nome a ela, você cria uma variável tipo struct
struct {
    int day;
    char month [10];
    int year;
} date;

// Pode-se declarar múltiplas strucs de uma vez
struct {
    int day;
    char month [10];
    int year;
} date1, date2, date3;

// Ao criar uma struct dando nome a ela, você cria a struct como um tipo de variável, e deve ser declarado no main cada nova struct
struct student {
    int age;
    int grade;
    char name[40];
};


// Parte 2-----------------------------------------------------------------------------------------


// Criar uma estrutura com typedef permite que ela seja declarada no main com um tipo de sua escolha: "course", neste caso
typedef struct {
  int id;
  char title[40];
  float hours; 
} course;

typedef struct {
  int x;
  int y;
} point;

// É possível criar uma struct na qual um dos membros também é uma struct. Neste caso, "point" (deve já ter sido criada)
typedef struct {
  float radius;
  point center;
} circle; 


typedef struct {
  int h;
  int w;
  int l;
} box;



int main() {
    
    // Pode-se acessar os membros da struct individualmente
    date.day = 1;
    sprintf(date.month, "January");
    date.year = 2000;
    
    printf("Day: %d, Month: %s, Year: %d\n",  date.day, date.month, date.year);
    
    // Pode-se declarar quantas structs quanto quiser quando declarada como tipo:
    struct student s1;
    struct student s2;
    
    // As variáveis da struct podem ser individualmente manipuladas do seguinte modo:
    s1.age = 19;
    s1.grade = 9;
    sprintf(s1.name, "John Bighimer");
    
    // É possível assimilar uma struct a outra:
    s2 = s1;

    printf("Name: %s, Age: %d, Grade: %d\n", s1.name, s1.age, s1.grade);
    printf("Name: %s, Age: %d, Grade: %d\n", s2.name, s2.age, s2.grade);
    
    // Também podem ser declaradas já com valores para suas variáveis:
    struct student s3 = {20, 8, "Robin"};
    
    printf("Name: %s, Age: %d, Grade: %d\n", s3.name, s3.age, s3.grade);
    
    // É possível declarar referindo-se aos membros da estrutura:
    struct student s4 = { .grade = 9, .age = 19, .name = "John"}; 

    printf("Name: %s, Age: %d, Grade: %d\n", s4.name, s4.age, s4.grade);
    
    
    // Parte 2 -----------------------------------------------------------------------------------
    
    // Estruturas declaradas com typedef, são declaradas com o tipo definido ao invés de struct. No caso:
    course cs1 = {23, "Math", 44};
    course cs2 = {24, "Geo", 40};
    
    printf("Title: %s, id: %d, Hours: %f\n", cs1.title, cs1.id, cs1.hours);
    printf("Title: %s, id: %d, Hours: %f\n", cs2.title, cs2.id, cs2.hours);
    
    // Para declarar as varáveis de uma struct dentro de outra, basta utilizar as chaves corretamente
    circle c = {4.5, {1, 3}};
    printf("%3.1f %d,%d", c.radius, c.center.x, c.center.y);
    
    
    // Um vetor pode armazenar elementos de qualquer tipo de dados, incluindo structs
    // Depois de declarar um struct, um elemento é acessível com o número do índice
    // O operador de ponto é usado para acessar membros do elemento:
    
    box boxes[3] = {{2, 6, 8}, {4, 6, 6}, {2, 6, 9}};

    for (int k = 0; k < 3; k++) {
        int volume = boxes[k].h*boxes[k].w*boxes[k].l;
        printf("box %d volume %d\n", k, volume);
    }
    
    return 0;
}
