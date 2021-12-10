#include <stdio.h>

#include <string.h>     // Necessário para uso de strings

/* Em C, strings são vetores char terminados pelo caractere nulo ( '\0' ), que deve ser considerado
    no tamanho da string */

int main() {

    // Há diferentes formas de declarar uma string, eis algumas delas:

    // Pode-se ocultar o tamanho da string, deixando que ele seja calculado automaticamente. Neste caso, 11+1 = 12
    char str[] = "Hello World";

    // Pode-se colocar o tamanho, útil quando ao longo da execução o conteúdo da string aumenta
    char str1[15] = "hello";

    // Pode-se colocar individualmente os caracteres. Aqui, não esquecer no caracter nulo
    char str2[6] = {'w', 'o', 'r', 'l', 'd', '\0'};

    // Pode-se declarar como vetores, respeitanto o tamanho da maior string
    char trip[3][15] = {
        "suitcase",
        "passport",
        "ticket"
    };

    // Declarando o vetor como ponteiro, o acesso as trings ficam facilitadas (por string)
    char * trip2[] = {
        "suitcase",
        "passport",
        "ticket"
    };
    printf("Please bring the following:\n");
    for (int i = 0; i < 3; i++) {
        printf("%s\n", trip2[i]);
    }

    // Usase-se %s para imprimir uma string
    printf("%s\n", str);

    // Obs: Após declarar uma string com =, não é possível faze-lo novamente. Deve se usar funções da biblioteca

    // A biblioteca string.h possui diferentes funções para manipulação de strings:

    // Obter o tamanho de uma string (Somente o conteúdo usado e desconsidera null)
    printf("'%s' = %ld\n", str, strlen(str));
    printf("'%s' = %ld\n", str1, strlen(str1));

    // Adiciona (Concatena) a segunda string ao final da primeira (Concatena). Cuidado com o tamanho
    strcat(str1, str2);
    printf("'%s' = %ld\n", str1, strlen(str1));

    // Adciona (Concatena) apenas os n primeiros caracteres da segunda string ao final da primeira. Cuidado com o tamanho
    char str4[7] = "1234"; // 1 2 3 4 _ _ 0
    strncat(str4, "5678", 2);
    printf("%s\n", str4);

    // Copia o conteúdo da segunda string na primeira
    char str3[6] = "";
    printf("str2 = '%s'\n", str2);
    printf("str3 = '%s'\n", str3);
    strcpy(str3, str2);
    printf("str3 = '%s'\n", str3);

    // Copia apenas os n primeiros caracteres do conteúdo da segunda string na primeira
    strncpy(str3, "WORLD", 1);
    printf("str3 = '%s'\n", str3);

    // Compara o conteúdo de duas strings, e se for diferente, indica qual string vem antes pela tabela ASCII
    if (strcmp("Hello", "Stranger") != 0) {
        printf("Hello != Stranger\n");
    }
    if (strcmp("Hello", "Stranger") < 0) {
        printf("'Hello' vem antes de 'Stranger'\n");
    }
    if (strcmp("Stranger", "Hello") > 0) {
        printf("'Stranger' vem depois de 'Hello'\n");
    }

    // Compara o conteúdo dos n primeiros caracteres de duas strings, e se for diferente, retorna a difença da posição pela tabela ASCII do primeiro caracter distinto
    if (strncmp("Stranger", "Strangers", 8) == 0) {
        printf("Stranger == Stranger\n");
    }
    if (strncmp("Stranger", "Strangers", 9) != 0) {
        printf("Stranger != Strangers\n");
    }

    char str5[] = "CC";
    char str6[] = "AA";
    printf("A diferença de posição de %s e %s é %d\n", str5, str6, strncmp(str5, str6, 1));

    strcpy(str5, "5");
    strcpy(str6, "9");
    printf("A diferença de posição de %s e %s é %d\n", str5, str6, strncmp(str5, str6, 1));

    // A função strchr retorna um ponteiro da posição do primeiro caracter semelhante ao escolhido. Retorna NULL se não encontrar
    char str7[] = "Aqui tem 3 letras 'e'";
    char * p1;
    p1 = strchr(str7, 'e');
    printf("Letras 'e' nas posições da frase '%s':\n", str7);
    // Algoritmo para retornar a posição do seguinte:
    while (p1 != NULL) {
        printf("Na posição %ld\n", p1 - str7 + 1);
        p1 = strchr(p1 + 1, 'e');
    }

    // A função strrchr retorna um ponteiro da posição do primeiro caracter na ordem reversa:
    p1 = strrchr(str7, 'e');
    printf("A posição do último 'e' é %ld:\n", p1 - str7 + 1);

    // A função srtstr retorna  um ponteiro da primeira ocorrencia da segunda string na primeira

    char str8[] = "Esta é uma simples string";
    char * p2;
    p2 = strstr(str8, "simple");
    printf("Na posição %ld\n", p2 - str8);
    strncpy(p2, "singela", 7);
    puts(str8);

    // Passa todos caracteres da string para maiúsculos (Função não inclusa na bibiliotaca C padrão)
    //strupr(str);
    //printf("'%s'\n", str);

    // Passa todos caracteres da strung para minúsculos (Função não inclusa na bibiliotaca C padrão)
    //strlwr(str);
    //printf("'%s'\n", str);

    // Reverte a ordem da string (Função não inclusa na bibiliotaca C padrão)
    //strrev(srt);
    //printf("'%s'\n", str);

    return 0;
}
