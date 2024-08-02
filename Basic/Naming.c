/*

Variables with same name
    While using the same name for variables is not recommended due to potential confusion and errors, it is possible when in different scopes, such globally, in functions and in loops. The variable value is always the one from the current scope.

*/

#include <stdio.h>

// Global variable
int x = 5;

void func() {
    // Local variable in func
    int x = 10;
    printf("Value of x in func: %d\n", x);

    // Loop inside func
    for (int x = 0; x < 3; x++) {
        printf("Value of x in func loop: %d\n", x);
    }

    printf("Value of x in func after loop: %d\n", x);
}


int main() {
    // Local variable in main
    int x = 30;
    
    printf("Value of x in main: %d\n", x);

    // Loop inside main
    for (int x = 0; x < 3; x++) {
        printf("Value of x in main loop: %d\n", x);
    }

    printf("Value of x in main after loop: %d\n", x);

    // Call func
    func();

    // Access global variable (note: the scope resolution operator :: is not valid in C, it is used in C++)
    printf("Value of global x: %d\n", x);

    return 0;
}
