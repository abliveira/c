/*  

Na linguagem C, a memória é dividida em duas partes:
    Stack: Espaço de memória de programa definido no momento da compilação
    Heap: Espaço de memória de programa não utilizado que é usado para alocar variáveis dinamicamente
        na memória durante o tempo de execução do programa
Quando não se sabe ao certo quanto de memória será usado durante a execução do programa, como a dependência
    de entrada pelo usuário, pode-se reservar dinamicamente a memória




Dynamic memory and heap contiguity
https://www.embedded.com/dynamic-memory-and-heap-contiguity/

Any kind of software needs memory to store data. How much data is stored, how it is accessed, and the processing performed on that data can vary greatly from one application to another.

In a desktop system, the approach to programming assumes that the system has infinite resources (memory) and that human intervention is a possibility. But most embedded applications have limited resources and may be deeply embedded, which means they need to be entirely self-sufficient.

Data Storage
Broadly speaking, in C/C++ data can be stored in three ways:

In static memory, where the storage is allocated at build time. Variables defined outside of functions are intrinsically static. Inside a function, variables may be directed to static storage using an explicit static declaration.
On the stack or in a CPU register. Variables defined inside functions are stored in this way by default.
Dynamically allocated and de-allocated, as required. This allocation and de-allocation is performed using the library functions malloc() and free() in C or the new and delete operators in C++.
The heap
The heap is an area of memory set aside to provide dynamically allocated storage. It is managed by the library functions malloc() and free() in C or the new and delete operators in C++. The size and location of the heap are application dependent and the means by which it is allocated is specific to a particular toolchain.


Dynamic = bad
When designing embedded software, if there is a choice between doing something statically or dynamically, the former should always be the first choice. This is because there are two distinct issues with most dynamic activities, such as resource allocation:

Determinism
Failure mode
Many, if not most, embedded applications are required to exhibit real time behavior. A key factor in achieving this goal is determinism – the predictable timing of a process. Dynamic memory allocation is typically non-deterministic. Although, as we shall see, this can be overcome.
As mentioned earlier, most embedded systems do not have a human operator who can make a decision if an exceptional event occurs. On a desktop computer a message of the form: “Blah blah not available. Please try later” may be inconvenient; on an embedded system it is probably not an option. Think heart pace-maker or automobile engine management unit.

Limitations of malloc()
The standard C library functions (and C++ operators) exhibit all the features that support the “dynamic = bad” rule. A normal malloc() implementation is not deterministic, which means that its use should be avoided in real time code. If a memory allocation is attempted and insufficient heap space is available, a NULL pointer is returned. This can be detected and evasive action taken, but this may be complex to implement.

Running out of heap space is an unsurprising failure mode. In theory, at least, a facility could be provided to show how much space is available. This would enable a failure to be predicted and possibly avoided. However, this does not take fragmentation into account.

If a series of calls are made to malloc() to grab some memory and the corresponding calls to free() are made in the reverse order, memory is gradually consumed from the top of the heap and then the allocated area is gradually reduced from the bottom. The code would look like this:

   p1 = malloc(1024);
   p2 = malloc(2048);
   p3 = malloc(1024);
   …
   free(p3);
   free(p2);
   free(p1);

As shown in Figure 1 , If the heap had a capacity for 8K of memory allocation, the malloc() calls would consume 4K, and 4K would still be available. At the end of this sequence, the state of the heap at the end of the code sequence would be the same as at the start, with all 8K available. However, real code is not like that. Consider this sequence:

   p1 = malloc(1024);
   p2 = malloc(2048);
   p3 = malloc(1024);
   …
   free(p2);

At the end of this sequence, 6K of memory is available. However, as illustrated in Figure 1, the largest contiguous area is only 4K. So, an allocation request for, say, 5K would fail, even though there is 6K free. This is memory fragmentation and can lead to unpredictable failures.

Block memory allocation
There is an alternative to malloc() that is commonly offered as a service with a real time operating system (RTOS): the allocation of memory in fixed size blocks. The idea is quite simple – one or more pools of memory blocks are defined; these have a specific, fixed block size and a defined number of blocks. Multiple pools facilitate a choice of block size.

It is quite straightforward to implement block memory allocation in a deterministic fashion. Also, this approach immediately eliminates fragmentation. Of course, there is still the possibility that an allocation will fail because there are no further blocks. However, this is entirely predictable and hence, can be mitigated. Additionally, RTOSes typically offer a “blocking” allocation call, which means the task requiring memory may be put to sleep if no blocks are available, and wakened when there is availability.

Reimplementing malloc()
Another creative way to implement dynamic memory allocation is to use block memory services to implement malloc() . The simple approach is to implement a series of block memory pools with sizes that are powers of two – maybe 16, 32, 64, 128 bytes, for example. It is then a simple matter to code malloc() so that a block which is large enough for the requested memory is allocated. This does lead to possible waste – what if an application needs a block of 33 bytes, for example? – but all the problems of determinism and failure modes are addressed.

Fixing fragmentation
Putting aside the problems of timing and resource exhaustion, is there a way to solve the problem of memory fragmentation while allowing malloc() to use a conventional heap?

Some languages – and Java is a notable example – address fragmentation using a garbage collector. From time to time, when a memory allocation is attempted, the garbage collection routine is run, which moves all the allocated blocks of memory around so that the free space is in a single contiguous block. There are actually more efficient ways to achieve a good result, but this gives the idea.
However, garbage collection has two major downsides:

Memory allocation becomes very non-deterministic, as it is not possible to predict when the garbage collector will be run or how long it might take. This may be addressed to some extent by executing the code at regular, defined intervals.
In C/C++, memory allocation results in a pointer being returned. This is the address of the allocated memory. If that memory is moved, the pointer is no longer valid. This could be solved by returning a pointer to a pointer, but this is non-standard and would lead to more complex application code.
I have wondered whether a memory management unit (MMU) might be used in a creative way. It would seem logical that the blocks of free space could be re-mapped so that they appear to be a single contiguous block. I would be interested to know whether this has ever been attempted.

Conclusion
The word “dynamic” should – and normally does – ring alarm bells with embedded software developers. The dynamic allocation/creation of anything is fraught with problems in real time and deeply embedded systems, so, wherever possible, static alternatives should be considered. Dynamic memory allocation is a good example of where this caution is wise, but a clear understanding of the issues can lead to implementations that are fit for purpose.

*/

#include <stdio.h>
#include <stdlib.h> // Necessário para funções de memória, como malloc, free

int main() {
    
    // A função sizeof() retorna o tamanho ocupado por uma variável (inclusive vetores) em bytes
    // Esta função na realidade é um operador, executado no momento da compilação e não durante o programa
    int x;
    int arr[10];
    printf("Tamanho de x (int) = %d bytes\n", sizeof(x)); /* output: 4 */
    printf("Tamanho de arr[10] (int) = %d bytes\n", sizeof(arr)); /* output: 40 */
    
    
    // A função  malloc  (memory allocation) aloca espaço para um bloco de bytes
    // consecutivos na memória e devolve o endereço desse bloco
    // O número de bytes é especificado no argumento da função
    
    char *ptr;
    ptr = malloc (1); // malloc aloca 1 byte:
    *ptr = 'a';
    
    
    int *ptr2;
    // Para alocar espaço para multiplos objetos, convém usar o sizeof(), que retornará o tamanho necessário
    ptr2 = malloc(10*sizeof(*ptr)); // Como queremos um vetor, multiplicamos a quantidade desejada
    // Se a alocação de memória for mal sucedida, é retornado o valor NULL
    if (ptr2 != NULL) {
        // Em vez de usar [] para se referir a elementos, é recomendável usar
        // aritmética para se referir aos elementos da matriz
        // Usar ++ ou + = altera o endereço armazenado pelo ponteiro.
        *(ptr2+2) = 50;  // Assinala 50 ao terceiro elemento int
    }
    printf("\nTerceiro elemento = %d\n", *(ptr2 + 2));
    
    // A função free() libera espaço ocupado dinamicamente pelo array
    free(ptr);
    /*
    Dangling Pointers
    The statement free(ptr) de-allocates the memory as shown in the below image with a cross sign, and 'ptr' pointer becomes dangling as it is pointing to the de-allocated memory.
    If we assign the NULL value to the 'ptr', then 'ptr' will not point to the deleted memory. Therefore, we can say that ptr is not a dangling pointer:
    */
    
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


    // Exemplo: Ocupando memória indefinidamente
    // while (1){
        //   char * pointer = (char*)malloc(10);
        //   i++;
    // }
    
    return 0;
}
