#include <stdio.h>
#include "..\OtherFolder\OtherFolderFile.c"

void SubFolderFileFunction (void) {
    printf("Hello from SubFolder File!\r\n");
    OtherFolderFileFunction();
}