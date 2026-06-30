#include <limits.h>
#include <stdio.h>

/* signed integer overflow (UB) — gcc -fsanitize=undefined -g ub.c -o ub */
int main(void) {
    int x = INT_MAX;
    int y = x + 1; /* <-- tràn số có dấu → UBSan báo runtime error */
    printf("%d\n", y);
    return 0;
}
