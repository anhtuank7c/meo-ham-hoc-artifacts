#include <stdio.h>

#include "util.h"

int main(void) {
    for (int i = 1; i <= 5; i++) {
        printf("%d^2 = %d\n", i, binh_phuong(i));
    }
    return 0;
}
