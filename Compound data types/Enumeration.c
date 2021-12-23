#include <stdio.h>

/* Na programação C, um tipo de enumeração (também chamado de enum) é um tipo de dados que consiste em constantes inteiras. 
Para definir enums, a palavra-chave enum é usada.

Há duas formas de construir um objecto enum; uma é declarar cada membro sem atribuir valor explícito mas 
deduzindo automaticamente valores com base na posição; a outra é declarar os membros e atribuir os valores explícitos. 

enums podem ser usados para substituir enumeração feita por macros:
   #define STOP 0
   #define CAUTION 1
   #define GO 2
*/

// enum flag {const1, const2, ..., constN};
enum flag {flag1, flag2, flag3};

/* Por padrão, const1 é 0, const2 é 1 e assim por diante. Você pode alterar os valores padrão dos elementos 
enum durante a declaração (se necessário). */
enum week {Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday};

// Changing default values of enum constants
enum suit {
    club = 0,
    diamonds = 10,
    hearts = 20,
    spades = 3,
};

// O valor do elemento seguinte se não especificado é o anterior +1
enum Foo { A, B, C=10, D, E=1, F, G=F+C };
// A=0, B=1, C=10, D=11, E=1, F=2, G=12

typedef enum{
    RUNNING = 49,
    STOPPED = 50,
    FAILED = 51,
    HIBERNATING = 52
} MACHINE_STATE;


int main() {

    // creating today variable of enum week type
    enum week today;
    today = Wednesday;
    printf("Today is Day %d\n\n",today+1);

    printf("A %d B %d C %d D %d E %d F %d G %d\n\n",A, B, C, D, E, F, G);
    
    int input1;
    MACHINE_STATE state;

    printf("Please provide integer in range [1-4]: ");
    input1 = getchar();
    state = input1;

    switch (state) {
        case RUNNING:
            printf("Machine is running\n");
            break;
        case STOPPED:
            printf("Machine is stopped\n");
            break;
        case FAILED:
            printf("Machine is in failed state\n");
            break;
        case HIBERNATING:
            printf("Machine is hibernated\n");
            break;
        default:
            break;
    }


    return 0;
}