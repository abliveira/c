#include <stdio.h>

void pointer_to_const(const int *p) {
    /* Data cannot be changed here */
    /* p[0] = 50;      // not allowed */

    /* Pointer can be reassigned */
    static int other[] = {900, 901, 902};
    p = other;          /* allowed */

    printf("pointer_to_const: %d\n", p[0]);
}

void const_pointer(int * const p) {
    /* Pointer cannot be moved */
    /* p = NULL;       // not allowed */

    /* Data can be changed */
    p[1] = 777;         /* allowed */

    printf("const_pointer: %d\n", p[1]);
}

void const_pointer_to_const(const int * const p) {
    /* Neither pointer nor data may change */
    /* p = NULL;        // not allowed */
    /* p[2] = 40;       // not allowed */

    printf("const_pointer_to_const: %d\n", p[2]);
}

int main(void) {
    int data[] = {10, 20, 30};

    pointer_to_const(data);
    const_pointer(data);
    const_pointer_to_const(data);

    printf("data after modifications: %d %d %d\n",
           data[0], data[1], data[2]);

    return 0;
}
