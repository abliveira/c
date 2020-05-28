#include <stdio.h>

// Há diferentes formas de trabalhar com entrada e saída de strings

int main() {
    
    // Para saída, pode-se usar printf, que permite a mistura de tipos de dados diferentes:
    printf("Programa v%d %s\n", 1, "beta");
    
    char intro[] = "Este programa perguntará seu nome ";
    
    // A função fputs(string, stdout) permite imprimir rapidamente um string
    fputs(intro, stdout);
    
    // A função puts(string) imprime uma string adicionando já comando new-line
    puts("e sobrenome"); // (Aqui poderia ser uma variável char)
    
    
    char primeiro_nome[10];
    char sobrenome[10];
    printf("\nDigite seu nome e sobrenome: ");
    
    // A função scanf para de ler quando há espaços, permitindo a separação da entrada em múltiplas strings
    scanf("%s %s", primeiro_nome, sobrenome);

    printf("Seu primeiro nome é %s. Seu sobrenome é %s\n", primeiro_nome, sobrenome);
    
    // A funções gets e fgets armazenam toda entrada em uma string
    // O uso de gets não é recomendável, pois não há limite de buffer de entrada
    
    char nome_completo[50];
    printf("\nDigite o seu nome completo: ");
    
    // Funções de entrada podem acabar capturando o comando de nova linha \n, usado na entrada de dados anterior ao invés do dado desejado
    // Há diferentes modos de se evitar isso, sendo um deles:
    
    // Capturar o comando nova-linha
    scanf("%*[^\n]"); 
    // Descartar o comando nova-linha
    scanf("%*c"); 
    
    // Aqui, a função fgets está limitando o que será lido, para impedir possíveis buffer overflow
    fgets(nome_completo, 50, stdin);
    printf("Seu nome completo é %s\n\n", nome_completo);
    
    
    // A função sprintf permite montar uma string com diferentes tipos de dados
    char info[50];
    int version = 1;
    char phase[] = "beta";
    sprintf(info, "Programa v%d %s\n\n", version, phase);
    printf("%s\n", info);
    
    // A função sscanf permite extrair diferentes tipos de dados de uma string 
    char data[ ] = "Av Paulista 1001 SP";
    puts(data);
    char tipo[50];
    char rua[50];
    int numero;
    char estado[50];
    sscanf(data, "%s %s %d %s", tipo, rua, &numero, estado);
    printf("Tipo de endereço: %s\nRua: %s\nNumero: %d\nEstado: %s", tipo, rua, numero, estado);
    
    // A função atoi() permite converter um uma string para um número
    int num = atoi("32");
    printf("\n\nO número é: %d", num);

    return 0;
}
