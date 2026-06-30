/* Binh chon — Basic C (starter). Hai mang song song: ten[] + phieu[].
 * Them/bau/in da co san; BAN viet phan TIM NGUOI DAN DAU (xem phan TODO). */
#include <stdio.h>

#define MAX 100

int main(void) {
    char ten[MAX][60];   /* ten ung vien            */
    int  phieu[MAX];      /* so phieu (song song)    */
    int  n = 0, chon;

    do {
        printf("\n1=Them 2=Bau 3=Ketqua 0=Thoat | Chon: ");
        if (scanf("%d", &chon) != 1) break;

        if (chon == 1 && n < MAX) {
            printf("Ten ung vien: ");
            scanf(" %59[^\n]", ten[n]);
            phieu[n] = 0;             /* bat dau voi 0 phieu */
            n++;
        } else if (chon == 2) {
            int so = 0;
            printf("Bau cho ung vien so: ");
            scanf("%d", &so);
            if (so >= 1 && so <= n) phieu[so - 1]++;   /* mot la phieu */
        } else if (chon == 3) {
            for (int i = 0; i < n; i++)
                printf("  %d. %s: %d phieu\n", i + 1, ten[i], phieu[i]);

            int dan_dau = -1;
            /* TODO: duyet mang phieu[] tim chi so co so phieu LON NHAT -> gan vao dan_dau.
               Goi y (tim max): gia su dan_dau = 0, roi neu phieu[i] > phieu[dan_dau]
               thi dan_dau = i. */
            if (dan_dau >= 0)
                printf("  >> Dan dau: %s (%d phieu)\n", ten[dan_dau], phieu[dan_dau]);
        }
    } while (chon != 0);

    return 0;
}
