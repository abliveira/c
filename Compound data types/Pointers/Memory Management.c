#include <stdio.h>
#include <stdlib.h> // Necessário para funções de memória, como malloc, free

/*  Na linguagem C, a memória é dividida em duas partes:
        Stack: Espaço de memória de programa definido no momento da compilação
        Heap: Espaço de memória de programa não utilizado que é usado para alocar variáveis dinamicamente
            na memória durante o tempo de execução do programa
    Quando não se sabe ao certo quanto de memória será usado durante a execução do programa, como a dependência
        de entrada pelo usuário, pode-se reservar dinamicamente a memória */

int main() {
    
    // A função sizeof() retorna o tamanho ocupado por uma variável (inclusive vetores) em bytes
    // Esta função na realidade é um operador, executado no momento da compilação e não durante o programa
    int x;
    int arr[10];
    printf("Tamanho de x (int) = %d bytes\n", sizeof(x)); /* output: 4 */
    printf("Tamanho de arr[10] (int) = %d bytes\n", sizeof(arr)); /* output: 40 */
    
    
    // A função  malloc  (memory allocation) aloca espaço para um bloco de bytes consecutivos na memória e devolve o endereço desse bloco
    // O número de bytes é especificado no argumento da função
    // A seguir, malloc aloca 1 byte:
    char *ptr;
    ptr = malloc (1);
    *ptr = 'a';
    
    
    int *ptr2;
    // Para alocar espaço para multiplos objetos, convém usar o sizeof(), que retornará o tamanho necessário
    ptr2 = malloc(10*sizeof(*ptr)); // Como queremos um vetor, multiplicamos a quantidade desejada
    // Se a alocação de memória for mal sucedida, é retornado o valor NULL
    if (ptr2 != NULL) {
        // Em vez de usar [] para se referir a elementos, é recomendável usar aritmética para se referir aos elementos da matriz
        // Usar ++ ou + = altera o endereço armazenado pelo ponteiro.
        *(ptr2+2) = 50;  // Assinala 50 ao terceiro elemento int
    }
    printf("\nTerceiro elemento = %d\n", *(ptr2 + 2));
    
    // A função free() libera espaço ocupado dinamicamente pelo array
    free(ptr);
    
    
    // Função calloc() (contiguous allocation) também aloca a memória como malloc(), porém adicionalmente muda os valores do bloco para zero
    // Além disso, calloc() pede dois parâmetros: 
    //    a quantidade de blocos a serem alocados (em malloc geralmente é colocado junto multiplicando),
    //    e o tipo de dado
    // Novamente, se o retorno for NULL indica que houve erro na alocação
    int* vetor; 
    // malloc() allocate the memory containing garbage values 
    vetor = (int*)malloc(5 * sizeof(int)); // 5*4 bytes = 20 bytes 
    // Deallocates memory previously allocated by malloc() function 
    free(vetor); 
    // calloc() allocate the memory for 5 integers and 
    // set 0 to all of them 
    vetor = (int*)calloc(5, sizeof(int)); 
    // Deallocates memory previously allocated by calloc() function 
    free(vetor); 
    // We can achieve same functionality as calloc() by using malloc() followed by memset()
    
    
    // A função realloc() desaloca o objeto antigo apontado por ponteiro e retorna um ponteiro para um 
    //    novo objeto que tenha o tamanho desejado
    // O conteúdo do novo objeto é idêntico ao do objeto antigo antes da desalocação, mas
    //    quaisquer bytes no novo objeto além do tamanho do antigo têm valores indeterminados
    int *ptr3;
    ptr3 = malloc(10*sizeof(*ptr3));  /* a block of 10 ints */
    if (ptr3 != NULL) {
        *(ptr3+2) = 50;  /* assign 50 to third int */
    }
    ptr3 = realloc(ptr3, 100*sizeof(*ptr3)); /* 100 ints */
    *(ptr3+30) = 75;
    printf("\nValores realocados: %d %d\n", *(ptr3+2), *(ptr3+30));
    
    
    // Alocando memória para Strings:
    // Ao alocar memória para um ponteiro de string, convém usar o comprimento da string em vez do operador sizeof.
    // Assim não será alocado mais espaço do que o necessário para um ponteiro
    char str20[20];
    char *str = NULL;
    strcpy(str20, "12345");
    printf("\nstr20 size: %d\n", sizeof(str20));
    printf("str20 length: %d\n", strlen(str20));
    // Um char é sempre de um byte; portanto, não é necessário multiplicar sizeof()
    str = malloc(strlen(str20)+1); // Usando strlen(), deve-se incluir um byte extra para o caractere \0
    strcpy(str, str20);
    printf("%s\n", str);

    
    // Dynamic Arrays:
    // Static arrays ocupam memória já no momento da compilação (Stack)
    // A variável staticArray aloca estaticamente 20 ints, isso é, 80 bytes que não poderão ser realocados
    int staticArray[20];
    // Dynamic arrays podem salvar memória criando um ponteiro que armazena o começo do array
    int *dynamicArray = malloc(20 * sizeof(int)); // Como é um vetor, multiplicamos a quantidade desejada
    // Se o ponteiro fosse alocado antes, podeiramos escrever:
    //      ptr = malloc(10 * sizeof(*ptr));, assim o espaço seria alocado de acordo com o tipo de dado
    //      do ponteiro, e não de um tipo de dado específico (aumenta a chance de erro de programação)
    *dynamicArray = 10;
    printf("\nAddress %x stores value %d\n", dynamicArray, *dynamicArray);
    dynamicArray[1] = 20;
    printf("dynamicArray[1] stores value %d\n", dynamicArray[1]);
    printf("The size of dynamicArray is %d", sizeof(dynamicArray));
    
    free(dynamicArray);
    
    return 0;
}
