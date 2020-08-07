#include <stdio.h> // Possui todas as funções para arquivos binários

/*Binary file mode options for the fopen() function are:
- rb open for reading (file must exist)
- wb open for writing (file need not exist, or will be overwrited)
- ab open for append (file need not exist)
- rb+ open for reading and writing from beginning
- wb+ open for reading and writing, overwriting file
- ab+ open for reading and writing, appending to file*/

#include <string.h>

typedef struct {
  int id;
  char name[20];
} item;

int main() {
  FILE *fptr;
  int arr[10];
  int x[10];
  int k;

    /* generate array of numbers */
    for (k = 0; k < 10; k++)
        arr[k] = k;
    
    /* write array to file */
    fptr = fopen("datafile.bin", "wb");
    
    // fwrite(ptr, item_size, num_items, fp) Writes num_items items of item_size size from pointer ptr to the file pointed
    fwrite(arr, sizeof(arr[0]), sizeof(arr)/sizeof(arr[0]), fptr);
    
    // fclose() Closes file opened, returning 0 if close was successful. EOF is returned if there is an error in closing.
    fclose(fptr);
    
    /* read array from file */
    fptr = fopen("datafile.bin", "rb");
    
    // fread(ptr, item_size, num_items, fp) Reads num_items items of item_size size from the file pointed 
    fread(x, sizeof(arr[0]), sizeof(arr)/sizeof(arr[0]), fptr);
    //feof(fp) Returns 0 when the end of the file stream has been reached.
    if (!feof(fptr)){
        printf("Fim da Leitura\n");
    }
    fclose(fptr);
    
    /* print array */
    for (k = 0; k < 10; k++)
        printf("%d", x[k]);
    printf("\n\n");
    
    
    // Existem funções no stdio.h para controlar o local do ponteiro do arquivo em um arquivo binário:
    // ftell (fptr) retorna um valor long int correspondente à posição do ponteiro do arquivo fptr em número de bytes desde o início do arquivo
    /*fseek(fp, num_bytes, from_pos) Moves the fp file pointer position by num_bytes bytes relative to position from_pos, which can be one of the following constants:
    - SEEK_SET start of file
    - SEEK_CUR current position
    - SEEK_END end of file*/
  
    FILE *fptr2;
    item first, second, secondf;
    
    /* create records */
    first.id = 10276;
    strcpy(first.name, "Widget");
    second.id = 11786;
    strcpy(second.name, "Gadget");
    
    /* write records to a file */
    fptr2 = fopen("info.dat", "wb");
    fwrite(&first, 1, sizeof(first), fptr2);
    fwrite(&second, 1, sizeof(second), fptr2);
    fclose(fptr2); 
    
    /* file contains 2 records of type item */
    fptr2 = fopen("info.dat", "rb");
    
    /* seek second record */
    fseek(fptr2, 1*sizeof(item), SEEK_SET);
    fread(&secondf, 1, sizeof(item), fptr2);
    printf("%d  %s\n", secondf.id, secondf.name);
    fclose(fptr2);
  
    /*To read just the second record, fseek() moved the file pointer to 1*sizeof(item) bytes from the start of the file. For example, if you wanted to move the pointer to the fourth record, then you seek to 3*sizeof(item) from the beginning of the file (SEEK_SET).*/
    
    return 0;
}
