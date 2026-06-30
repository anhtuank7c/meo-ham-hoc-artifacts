#include <stdio.h>
#include <stdlib.h>

/* heap-use-after-free — biên dịch: gcc -fsanitize=address -g uaf.c -o uaf */
int main(void) {
    int *p = malloc(sizeof(int));
    *p = 10;
    free(p);
    *p = 20; /* <-- dùng vùng đã free → ASan dừng tại đây */
    printf("%d\n", *p);
    return 0;
}
