// Demonstration of memory manipulation functions in C
#include <stdio.h>
#include <string.h> // memcpy, memset, memmove, memcmp

int main() {
    char src[20] = "Hello, world!";
    char dest[20];

    // memcpy(dest, src, n): dest <- src (n bytes)
    memcpy(dest, src, strlen(src) + 1); // +1 for null terminator
    printf("After memcpy, dest = '%s'\n", dest);

    // memset(dest, val, n): set n bytes at dest to val
    memset(dest, 0, sizeof(dest));
    printf("After memset, dest = '%s' (should be empty)\n", dest);

    // memmove(dest, src, n): safe copy n bytes (may overlap)
    char overlap[] = "1234567890";
    memmove(overlap + 4, overlap, 6);
    printf("After memmove (overlap), overlap = '%s'\n", overlap);

    // memcmp(a, b, n): compare n bytes (0=equal)
    char a[] = "ABCDEF", b[] = "ABCXYZ";
    int cmp = memcmp(a, b, 3);
    printf("memcmp first 3 bytes: %d\n", cmp);
    cmp = memcmp(a, b, 6);
    printf("memcmp all 6 bytes: %d\n", cmp);

    // memset(arr, 0, n): zero n bytes in arr
    int arr[5];
    memset(arr, 0, sizeof(arr));
    printf("After memset, arr = ");
    for (int i = 0; i < 5; i++) printf("%d ", arr[i]);
    printf("\n");

    // memcpy(&p2, &p1, n): copy struct p1 to p2
    struct Point { int x, y; } p1 = {1, 2}, p2;
    memcpy(&p2, &p1, sizeof(struct Point));
    printf("After memcpy, p2 = (%d, %d)\n", p2.x, p2.y);

    return 0;
}