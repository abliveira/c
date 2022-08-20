#include <stdio.h>

// Um Void Pointer é um ponteiro que não possui nenhum tipo de dado associado
// Um ponteiro nulo pode conter endereço de qualquer tipo e pode ser transmitido para qualquer tipo


// Parte 2
// Uma função declarada com retorno void * permite qualquer tipo de retorno
// Da mesma forma, os parâmetros que são void * aceitam qualquer tipo de argumento. 
void* square (const void* num);


int main() {
    
    // A seguir, um mesmo ponteiro nulo é usado para três diferentes tipos de dados:
    int x = 33;
    float y = 12.4;
    char c = 'a';
    void *ptr;
    ptr = &x;
    printf("void ptr points to %d\n", *((int *)ptr));
    ptr = &y;
    printf("void ptr points to %f\n", *((float *)ptr));
    ptr = &c;
    printf("void ptr points to %c", *((char *)ptr));
    // Obs: Para dereferenciar um ponteiro nulo, deve-se colocar o tipo de dados antes do operador *
    
    
    // Parte 2
    
    int z;
    int * sq_int;
    z = 6;
    sq_int = (int *) square(&z);
    printf("\n\n%d squared is %d\n", z, *sq_int);
    
    /*float z;
    float * sq_int;
    z = 6;
    sq_int = (float *) square(&z);
    printf("\n\n%f squared is %f\n", z, *sq_int);*/

    return 0;
}


// Esta função foi escrita para multiplicar ints, e é por isso que o ponteiro num void é convertido em int
// Se a implementação tiver que ser alterada para permitir que square () multiplique floats, 
//    somente a definição precisará ser alterada sem a necessidade de fazer alterações na declaração.
void* square (const void *num) {
  static int result;
  result = (*(int *)num) * (*(int *)num);
  return &result;
}
/*void* square (const void *num) {
  static float result;
  result = (*(float *)num) * (*(float *)num);
  return &result;
}*/
