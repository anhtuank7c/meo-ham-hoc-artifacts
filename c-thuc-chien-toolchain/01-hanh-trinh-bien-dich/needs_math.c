#include <math.h>
#include <stdio.h>

/* Bài này CỐ Ý gây lỗi "undefined reference to sqrt" để bạn tự sửa.
 * Biên dịch thường sẽ lỗi ở giai đoạn LIÊN KẾT:
 *     gcc needs_math.c -o needs_math        # -> undefined reference to 'sqrt'
 * Sửa bằng cách nối thư viện math khi liên kết:
 *     gcc needs_math.c -lm -o needs_math    # OK
 */
int main(void) {
    double x = 2.0;
    printf("can bac hai cua %.0f = %f\n", x, sqrt(x));
    return 0;
}
