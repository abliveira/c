#include <stdio.h> // Inclui funções de arquivos

/* fopen("file", ?)
- r open for reading (file must exist)
- w creates an empty file for writing. If a file with the same name already exists, its content is erased and the file is considered as a new empty file.
- a appends to a file. Writing operations, append data at the end of the file. The file is created if it does not exist.
- r+ open for reading and writing from beginning. The file must exist.
- w+ open for reading and writing, overwriting file
- a+ open for reading and writing, appending to file */


#include <stdio.h>

int main() {  
    FILE *fptr;
    int stock;
    char buffer[200], item[10], c;
    float price;
    
    // fopen retorna um ponteiro que será usado para o manejo de arquivos
    fptr = fopen("myfile.txt", "w");
    if (fptr == NULL) {   // Se retornar NULL, houve um erro
        printf("Error opening file.");
        return 1;
    }
    
    /* myfile.txt: Inventory\n100 Widget 0.29\nEnd of List */
    fprintf(fptr, "Inventory\n");
    fprintf(fptr, "%d %s %f\n", 100, "Widget", 0.29);
    fputs("End of List", fptr); // Writes string str to the file pointed
    //fputc(char, fp) Writes character char to the file pointed to by fp.
    fclose(fptr);
    
    fptr = fopen("myfile.txt", "r");
    fgets(buffer, 20, fptr);    //Le a primeira linha e armazena em buffer
    printf("%s\n", buffer);
    fscanf(fptr, "%d%s%f", &stock, item, &price);   // Continua da segunda linha, lê item por item separadamente
    printf("%d  %s  %4.2f\n", stock, item, price);
    
    // fgetc() retorna o próximo caracter do arquivo apontado pelo ponteiro
    // Se o final do arquivo tiver sido alcançado, o EOF será retornado.
    while ((c = fgetc(fptr)) != EOF) /* read the rest of the file */
        printf("%c", c);
    
    fclose(fptr);
    return 0;
}
