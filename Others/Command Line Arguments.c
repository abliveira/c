/*
Referências:
    https://www.studytonight.com/c/command-line-argument.php

C oferece um recurso chamado "argumento da linha de comando", os quais permitem
inserir valores da linha de comando no momento da execução. O argumento da linha
de comando é um parâmetro fornecido ao programa quando é chamado ou executado.

Uso de argumentos da linha de comando em c
Eles são usados quando precisamos controlar nosso programa de fora, em vez de codificá-lo.
O argumento da linha de comando é um conceito importante na programação C. 
Os argumentos da linha de comando são passados para o método main ().

Sintaxe:
int main(int argc, char *argv[])
Aqui, o argc conta o número de argumentos na linha de comando e o argv [] é uma
matriz de ponteiro que contém ponteiros do tipo char, que apontam para os argumentos
passados para o programa.

Comando de Linha:
Compilar o código usando: gcc "Command Line Arguments.c" -o "Command Line Arguments"
Em seguida, execute -o usando: ./"Command Line Arguments.c"

A partir do exemplo, podemos inferir que o primeiro argumento da linha de comando
é o nome do arquivo do programa, que é sempre adicionado por padrão pelo compilador.
Logo, argv[0] = nome do nosso arquivo e argc = 1.

Pode-se compilar o programa usando gcc filename.c -o filename. 
Fornecemos o sinalizador -o para que o arquivo de saída tenha o nome que fornecemos.

Os argumentos são automaticamente separados por espaços, mas pode-se usar aspas simples
ou duplas evitar que um dado argumento seja quebrado despropositadamente, como o nome de
um arquivo com espaços no nome.

Lembre-se de que o argv [0] mantém o nome do programa e o argv [1] aponta para o argumento
da primeira linha de comando e o argv [argc-1] dá o último argumento. Se nenhum argumento
for fornecido, o ARGC será 1.

Podemos dar argumentos do tipo int e float, mas eles serão armazenados como strings.

*/

#include<stdio.h>

int main (int argc, char *argv[]) {

    printf("argc = %d\r\n", argc);
    if(argc < 2)
        printf("No argument supplied. The only argument here is %s", argv[0]);
    else if (argc >= 2) {
        printf("The arguments supplied are:\n");
        for(int i = 1; i < argc; i++) {
            printf("%s\t", argv[i]);
        }
    }
    return 0;
}