#include <stdio.h>

#include "util.h"

int main(void) {
    printf("binh_phuong(5) = %d\n", binh_phuong(5)); /* 25 */
    printf("tong_den(5)    = %d\n", tong_den(5));     /* nen la 15, nhung BUG in 10 */
    return 0;
}
