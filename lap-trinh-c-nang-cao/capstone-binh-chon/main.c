#include <stdio.h>
#include <string.h>
#include "candidate.h"

#define FILE_PATH "binh-chon.dat"

/* In ket qua: sap xep giam dan theo so phieu (selection sort tren con tro).
   Da cho san — chi dung store_count/store_at, khong dung den cau truc trong. */
static void in_ket_qua(CandidateStore *s) {
    int n = store_count(s);
    if (n == 0) { printf("  (chua co ung vien)\n"); return; }
    Candidate *arr[256];
    int m = n < 256 ? n : 256;
    for (int i = 0; i < m; i++) arr[i] = store_at(s, i);
    for (int i = 0; i < m - 1; i++) {
        int mx = i;
        for (int j = i + 1; j < m; j++)
            if (arr[j]->votes > arr[mx]->votes) mx = j;
        Candidate *t = arr[i]; arr[i] = arr[mx]; arr[mx] = t;
    }
    for (int i = 0; i < m; i++)
        printf("  #%-3d %-24s %d phieu\n", arr[i]->id, arr[i]->name, arr[i]->votes);
}

int main(void) {
    CandidateStore *s = store_create();
    if (!s) return 1;
    store_load(s, FILE_PATH);

    char dong[120];
    printf("Lenh: them <ten> | bau <id> | ketqua | dandau | thoat\n");
    while (printf("> "), fgets(dong, sizeof dong, stdin)) {
        char cmd[16]; int id;
        if (sscanf(dong, "%15s", cmd) != 1) continue;

        if (strcmp(cmd, "them") == 0) {
            char *ten = dong + 4;
            while (*ten == ' ') ten++;
            ten[strcspn(ten, "\n")] = '\0';
            if (*ten) printf("  + #%d %s\n", store_add(s, ten), ten);
        } else if (strcmp(cmd, "bau") == 0 && sscanf(dong, "%*s %d", &id) == 1) {
            if (store_vote(s, id)) printf("  da bau cho #%d\n", id);
            else printf("  khong bau duoc #%d (chua tim thay / chua cai dat store_vote)\n", id);
        } else if (strcmp(cmd, "ketqua") == 0) {
            in_ket_qua(s);
        } else if (strcmp(cmd, "dandau") == 0) {
            Candidate *c = store_leader(s);
            if (c) printf("  Dan dau: %s (%d phieu)\n", c->name, c->votes);
            else printf("  (chua co ket qua / chua cai dat store_leader)\n");
        } else if (strcmp(cmd, "thoat") == 0) {
            break;
        }
    }

    store_save(s, FILE_PATH);
    store_destroy(s);
    return 0;
}
