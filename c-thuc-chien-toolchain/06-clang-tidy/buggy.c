#include <stdio.h>
#include <stdlib.h>

/* File này CỐ Ý có vài vấn đề để clang-tidy bắt:
 *  - đọc biến chưa khởi tạo
 *  - dereference malloc chưa kiểm tra NULL
 *  - dùng '=' thay vì '==' trong if
 *  - số "ma thuật"
 *  - thiếu { } quanh thân if
 */
int main(void) {
    int x;
    printf("%d\n", x);

    int *p = malloc(sizeof(int));
    *p = 42;

    int y = 0;
    if (y = 1) {
        y = y + 86400;
    }

    if (y > 10)
        printf("lon\n");

    free(p);
    return 0;
}
