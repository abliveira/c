/*

Inclusão de bibliotecas e arquivos extras:

    Acessando arquivos da biblioteca padrão. Novos arquivos podem precisar ser incluídos nas configurações do compilador:
        #include <file.h>
    Acessando arquivos na mesma pasta
        #include "file.h"
    Acessando arquivos nas subpastas
        #include "subfolder/file.h"
    Acessando arquivos na pasta superior:
        Use "../", que direciona para a pasta raiz.
        Em seguida, navegue até a pasta desejada
        #include "../file.h" (arquivos na pasta raiz)
        #include "../otherfolder/file.h" (arquivos em outras pastas)

Estruturando arquivos header (.h) e source (.c)

    Em programas maiores, cuja organização é extremamente importante, arquivos header e source
    são divisões para estruturar código extra, além da sua folha principal. Não chega a ser um
    crime usar apenas um arquivo source extra no caso de um programa pequeno.

    Arquivos header (.h)
        - São utilizados para declaração de variáveis, de protótipo de funções uso de diretivas de pré-processador (macros)
        - As variáveis e funções declaradas no header estarão disponíveis em quaisquer arquivos que incluir este header
        - Não contém código executável
        - Devem ser incluídos nos respectivos arquivos source
        - Devem ser incluídos nos outros arquivos source que utilizam código deste par header e source
        - Devem utilizar diretivas de pré-processador para evitar duplicação da declaração (ver abaixo)
    Arquivos source (.c)
        - São utilizados para carregar o código executável
        - As variáveis e funções declaradas apenas no source não ficaram disponíveis para uso externo
        - Devem ser incluir os respectivos arquivos header
    Utilização
        - Incluir arquivos header nos respectivos arquivos source
        - Incluir arquivos header nos demais arquivos source que utilizam código deste par header e source
        - Não se inclui os arquivos source em outros arquivos. O compilador que deve, manualmente ou
        automaticamente refenciar estes arquivos para compilar tudo junto no momento do build

Incluindo um arquivo de cabeçalho (Header/.h) múltiplas vezes:

    Quando um arquivo de cabeçalho é incluído duas vezes em um programa, o compilador processa
    o conteúdo desse arquivo de cabeçalho duas vezes. Isso leva a um erro no programa.
    Para eliminar esse erro, são usadas diretivas de pré-processador condicional. Assim,
    apenas na primeira vez o conteúdo do arquivo é compilado.

    Sintaxe: 
 
    #ifndef HEADER_FILE_NAME
    #define HEADER_FILE_NAME

    // the code

    #endif

*/

#include <stdio.h>
#include "OtherFile.h"
#include "SubFolder\SubFolderFile.c"

int main() {

    printf("Hello from Main File!\r\n");
    OtherFileFunction();
    SubFolderFileFunction();
    return 0;
}