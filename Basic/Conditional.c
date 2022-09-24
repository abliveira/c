#include <stdio.h>

int f1 (int a, int b)
{
    if (a > b)
    {
        printf("A is greater than B\n");
        return 1;
    }
    else
    {
        printf("B is greater than A");
        return 0;
    }
}

int main() {

    // Exemplo de identação de if-else
    int i = 0;
    int a = 1, b = 0;

    if (a)
        if (b)
            b = 1;
        else
            b = 2;

    printf ("%d\n", b);

    // Exemplo de condição. Neste caso, a segunda condição não é executada
    if (f1(20,10) || f1(10,20))
        printf("C is fun!\n");
    // O mesmo vale para AND. Se a primeira falha, a segunda não é executada
    if (f1(10,20) && f1(20,10))
        printf("C is fun!\n");

    // Uso de Ternary operator vs if-else
	int m = 5, n = 4;

    // if else
    if (m > n)
        printf("%d\n", (m>n?m:n));
    else
        printf("%d\n", (m>n?m:n));

    // Ternary operator
    printf("%d\n", (m>n?m:n));

	(m > n) ? printf("m is greater than n that is %d > %d",
					m, n)
			: printf("n is greater than m that is %d > %d",
					n, m);

	return 0;
}
