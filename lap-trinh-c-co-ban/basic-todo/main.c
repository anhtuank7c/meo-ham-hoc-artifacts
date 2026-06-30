/* Todo — Basic C: luu bang HAI MANG SONG SONG (tieu_de[] va xong[]),
 * chay trong bo nho, menu so. Chi dung mang + vong lap + re nhanh + ham main. */
#include <stdio.h>

#define MAX 100

int main(void) {
    char tieu_de[MAX][80];   /* ten tung viec        */
    int  xong[MAX];          /* 0=chua, 1=xong (song song voi tieu_de) */
    int  n = 0, chon;

    do {
        printf("\n1=Them 2=Xong 3=In 0=Thoat | Chon: ");
        if (scanf("%d", &chon) != 1) break;

        if (chon == 1 && n < MAX) {
            printf("Ten viec: ");
            scanf(" %79[^\n]", tieu_de[n]);   /* doc ca dong, gom dau cach */
            xong[n] = 0;                       /* moi them -> chua xong     */
            n++;
        } else if (chon == 2) {
            int so = 0;
            printf("So thu tu: ");
            scanf("%d", &so);
            if (so >= 1 && so <= n) xong[so - 1] = 1;   /* nguoi dung dem tu 1 */
        } else if (chon == 3) {
            if (n == 0) printf("  (chua co viec)\n");
            for (int i = 0; i < n; i++)
                printf("  %d. [%c] %s\n", i + 1, xong[i] ? 'x' : ' ', tieu_de[i]);
        }
    } while (chon != 0);

    return 0;
}
