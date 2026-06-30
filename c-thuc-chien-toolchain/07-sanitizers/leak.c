#include <stdio.h>
#include <stdlib.h>

/* memory leak — gcc -fsanitize=address -g leak.c -o lk
 * LƯU Ý: LeakSanitizer chạy tốt trên LINUX. Trên macOS nó thường KHÔNG bật mặc
 * định (báo "not supported"); dùng Linux/WSL hoặc valgrind --leak-check=full. */
int main(void) {
    int *p = malloc(100); /* xin 100 byte */
    *p = 42;
    /* quên free(p) → rò rỉ khi thoát */
    return 0;
}
