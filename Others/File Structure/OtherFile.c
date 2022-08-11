#include <stdio.h>
#include "OtherFile.h"

void NotAccessibleFromOutsideFunction (void);

void OtherFileFunction (void) {
    printf("Hello from Other File!\r\n");
    NotAccessibleFromOutsideFunction();
}

void NotAccessibleFromOutsideFunction (void) {
    printf("Hello from a hidden function!\r\n");
}