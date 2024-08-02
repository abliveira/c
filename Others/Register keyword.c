/*

The register keyword in C is a storage class specifier that suggests to the 
compiler that a variable should be stored in a CPU register instead of regular 
memory. Registers are extremely fast memory locations within the CPU.

Why use register?
    Performance: Accessing variables from registers is significantly faster 
than accessing them from memory. This can lead to performance improvements,
especially in loops and computationally intensive code.
    Compiler Optimization: The compiler can potentially perform more optimizations
when it knows a variable is in a register.

*/

#include <stdio.h>

int main() {

    // Suggest to the compiler to store 'i' in a register
    register int i;
    int sum = 0;

    for (i = 1; i <= 100; ++i) {
        sum += i;
    }

    printf("The sum is: %d\n", sum);

    return 0;
}