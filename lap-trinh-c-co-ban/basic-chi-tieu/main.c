/* Chi tieu — Basic C (starter). Hai mang song song: so_tien[] + danh_muc[].
 * Phan nhap/in da co san; BAN viet vong lap tinh TONG (xem phan TODO). */
#include <stdio.h>

#define MAX 100

int main(void) {
    long so_tien[MAX];        /* so tien moi khoan (dong, so nguyen) */
    char danh_muc[MAX][24];   /* nhom chi cua khoan do (song song)   */
    int  n = 0, chon;

    do {
        printf("\n1=Ghi 2=In 3=Tong 0=Thoat | Chon: ");
        if (scanf("%d", &chon) != 1) break;

        if (chon == 1 && n < MAX) {
            printf("So tien: ");
            scanf("%ld", &so_tien[n]);
            printf("Danh muc: ");
            scanf(" %23[^\n]", danh_muc[n]);   /* doc ca cum tu */
            n++;
        } else if (chon == 2) {
            if (n == 0) printf("  (chua co khoan chi)\n");
            for (int i = 0; i < n; i++)
                printf("  %d. %ld - %s\n", i + 1, so_tien[i], danh_muc[i]);
        } else if (chon == 3) {
            long tong = 0;
            /* TODO: vong for chay i tu 0 den n-1, cong don so_tien[i] vao `tong`. */
            printf("Tong chi: %ld\n", tong);
        }
    } while (chon != 0);

    return 0;
}
