#include <stdio.h>
#include <stdlib.h>

/* Uma exceção (exception) é qualquer situação que faça com que seu programa pare a execução normal.
O tratamento de exceções (exception handling), ou tratamento de erros, é uma abordagem para processar erros de tempo de execução
A linguagem C não suporta diretamente tratamento de erros, mas há algumas técnicas:
- Previnir que erros não aconteçam, como checar entrada de dados, tamanho de variáveis, checar se é 0 antes de divir...
- Usar a função exit encerrar normalmente a execução do programam, ao invés de deixar que um erro faça travar o programa
- Usar exit é uma boa prática porque fecha todas as conexões e processos de arquivos abertos
- É possível retornar qualquer valor no exit(), mas os típicos são 0 para sucesso e -1 para falha. Tambpem há EXIT_SUCCESS e EXIT_FAILURE
- Estes valores poderiam ser retornados a um processo que chamou o programa em questão
*/

#define EXAMPLE1 // Rodar um exemplo trecho de código por compilação



#ifdef EXAMPLE2// Bibliotecas para erros
#include <errno.h>
#include <string.h>
extern int errno;
#endif

#ifdef EXAMPLE3
#include <errno.h>
#include <string.h>
#include <math.h>
#endif

#ifdef EXAMPLE4
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#endif


int main() {
    
    #ifdef EXAMPLE1
    // Prevenção de erro:
    int x = 10;
    int y = 0;
    if (y != 0)
        printf("x / y = %d", x/y);
    else {
        printf("Divisor is 0. Program exiting.");
       exit(EXIT_FAILURE);
    }
    #endif
  
  
  #ifdef EXAMPLE2
  
    /* Para produzir o código de erro armazenado em errno, você usa fprintf para imprimir no fluxo de arquivo stderr, a saída de erro padrão para a tela. 
    Usar o stderr é uma questão de convenção e uma boa prática de programação.*/

  /* Algumas funções como fopen () podem setar códigos de erro quando não executadas conforme o esperado
    O código é definido em uma variável global errno, do arquivo errno.h. Deve-se declara-la como externa
    Ao usar errno, deve-se configurá-lo como 0 antes de chamar uma função de biblioteca.*/
    // Todos códigos de erro descritos, usando strerror:
    for (int i = 0; i < 135; i++)
        fprintf(stderr, "%d: %s\n", i, strerror(i));
        
    FILE *fptr;
    errno = 0;
    fptr = fopen("c:\\nonexistantfile.txt", "r");
    if (fptr == NULL) {
        perror("Error"); // perror permitir imprimir um mensagem mais descritiva sobre o erro
        fprintf(stderr, "Error code: %d\n", errno);
        fprintf(stderr, "Error description %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    } 
        
    #endif
    
    
    
    #ifdef EXAMPLE3
    /* A biblioteca math.h também utiliza errno para lidar com códigos de erros. 
    Algumas das funções matemáticas definem errno para o valor macro EDOM definido, quando um domínio está fora do intervalo
    E o valor da macro ERANGE é usado quando há um erro de intervalo*/
    
    float k = -5;
    float num = 1000;
    float result;
    
    errno = 0;
    result = sqrt(k);
    if (errno == 0)
        printf("%f ", result);
    else if (errno == EDOM)
        fprintf(stderr, "%s\n", strerror(errno));
    
    errno = 0;
    result = exp(num);
    if (errno == 0)
        printf("%f ", result);
    else if (errno == ERANGE)
        fprintf(stderr, "%s\n", strerror(errno));
        
    #endif
    
    
    
    
    #ifdef EXAMPLE4
    
    /* As funções feof () e ferror () podem ser usadas para verificar se há um ponteiro de arquivo NULL e usar errno, e ainda determinar erros de I/O de arquivo:
    feof(fptr) Retorna um valor diferente de 0 se o final do fluxo foi alcançado, 0 caso contrário. Também define EOF
    ferror(fptr) Retorna um valor diferente de zero se houver um erro, 0 para nenhum erro.
    O programa a seguir incorpora várias técnicas de tratamento de exceção: */
    
    FILE *fptr;
    int c;
    errno = 0;
    //fptr = fopen("myfile.txt", "w"); // Descomentar essa e a próxima linha para avançar para os próximos tratamentos
    //fclose(fptr);
    fptr = fopen("myfile.txt", "r");
    if (fptr == NULL) {
        fprintf(stderr, "Error opening file. %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    
    while ((c = getc(fptr)) != EOF) /* read the rest of the file */
        printf("%c", c);
    
    if (ferror(fptr)) {
        printf("I/O error reading file.");
        exit(EXIT_FAILURE);
    }
    else if (feof(fptr))
        printf("End of file reached.");
    fclose(fptr);
    
    #endif
    
  
  return 0;
}
