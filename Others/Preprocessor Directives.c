#include <string.h>

// Diretivas de pré-processador podem ser usadas para facilitar alterações no códigos antes do momento da compilação. São distinguidas pelo operador #

// A diretiva #include permite incluir o conteúdo de um arquivo específico em tal ponto do código. Pode ser usado de dois modos:
#include <stdio.h>
#include "stdlib.h"

// A diretiva #define permite criar um macro, que, associado a um valor, criará uma constante que substituirá o texto no momento da compilação
#define DEZ 10 // Quando DEZ aparecer no código, será o mesmo que o valor declarado 10

//A diretiva #undef desfaz a definição. Sendo assim, ocorrências subsequentes são ignoradas pelo pré-processador
#undef DEZ

// A diretiva #define também pode ser usada para operações de lógica if. O macro declarado equivale a 1, e não declarado equivale 0
#define ABC
#ifdef ABC
  // O código aqui será compilado
#elif BCD
  // O código aqui não será compilado
#else
  // O código aqui não será compilado
#endif

// Ao contrário: "if not defined"
#ifndef BCD
  // O código aqui será compilado
#else
  // O código aqui não será compilado
#endif

// Operações condicionais do pré processador também podem utilizar valores
#define LEVEL 4
#if LEVEL == 3
  // O código aqui não será compilado
#elif LEVEL > 5
  // O código aqui não será compilado
#elif LEVEL > 4
  // O código aqui não será compilado
#else
  // O código aqui será compilado
#endif

// É possível pular a linha da diretiva e continuar na próxima, usando o operador "\"
#define VERY_LONG_CONSTANT \
23.678901

// É possível utilizar define com funções
#define PI 3.14
#define AREA(r) (PI*(r)*(r)) // Aqui o "r", trata-se do argumento onde a função será substituída. No caso, "radius" e "radius+1"

int main() {

    float radius = 2;
    printf("%3.2f\n", PI);
    printf("Area is %5.2f\n", AREA(radius));
    printf("Area with radius + 1: %5.2f\n", AREA(radius+1));
  
    // Na linguagem C, também há macros já pré definidos que podem ser usados:
    char curr_time[10];
    char curr_date[12];
    int std_c;
    
    strcpy(curr_time, __TIME__);
    strcpy(curr_date, __DATE__);
    printf("%s %s\n", curr_time, curr_date);
    printf("This is line %d\n", __LINE__);    
    std_c = __STDC__;
    printf("STDC is %d", std_c);  
  
  return 0;
}
