#include <stdio.h>
#include <stdlib.h>

/* heap-buffer-overflow — gcc -fsanitize=address -g overflow.c -o ov */
int main(void) {
    int *a = malloc(4 * sizeof(int)); /* chỉ số hợp lệ: 0..3 */
    for (int i = 0; i <= 4; i++) {     /* <-- i = 4 là tràn! */
        a[i] = i;
    }
    printf("%d\n", a[0]);
    free(a);
    return 0;
}
