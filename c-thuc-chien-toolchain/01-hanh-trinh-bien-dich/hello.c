#include <stdio.h>

#define MAX 100
#define GAP(x) ((x) + (x)) /* thử bỏ ngoặc rồi xem -E để hiểu vì sao cần ngoặc */

int bang[MAX];

int main(void) {
    int y = GAP(5);
    printf("Xin chao! GAP(5) = %d, MAX = %d\n", y, MAX);
    return 0;
}
