#include <stdio.h>
#include <string.h>
#include "expense.h"

#define FILE_PATH "chi-tieu.dat"

static void in_danh_sach(ExpenseStore *s) {
    int n = store_count(s);
    if (n == 0) { printf("  (chua co khoan chi)\n"); return; }
    for (int i = 0; i < n; i++) {
        Expense *e = store_at(s, i);
        printf("  #%-3d %10ld  %-12s %s\n", e->id, e->amount, e->category, e->note);
    }
}

/* In tong theo tung danh muc. Phan thu thap danh muc da cho san;
   ban chi can cai dat store_total_of() trong expense.c la chay dung. */
static void in_theo_nhom(ExpenseStore *s) {
    char seen[64][24];
    int nseen = 0, n = store_count(s);
    for (int i = 0; i < n; i++) {
        Expense *e = store_at(s, i);
        int found = 0;
        for (int j = 0; j < nseen; j++)
            if (strcmp(seen[j], e->category) == 0) { found = 1; break; }
        if (!found && nseen < 64)
            snprintf(seen[nseen++], sizeof seen[0], "%s", e->category);
    }
    if (nseen == 0) { printf("  (chua co khoan chi)\n"); return; }
    for (int j = 0; j < nseen; j++)
        printf("  %-14s %ld\n", seen[j], store_total_of(s, seen[j]));
}

int main(void) {
    ExpenseStore *s = store_create();
    if (!s) return 1;
    store_load(s, FILE_PATH);

    char dong[200];
    printf("Lenh: chi <so tien> <danh muc> <ghi chu> | xoa <id> | in | tong | nhom | thoat\n");
    while (printf("> "), fgets(dong, sizeof dong, stdin)) {
        char cmd[16]; int id;
        if (sscanf(dong, "%15s", cmd) != 1) continue;

        if (strcmp(cmd, "chi") == 0) {
            long amount; char cat[24]; int pos = 0;
            if (sscanf(dong, "%*s %ld %23s %n", &amount, cat, &pos) >= 2) {
                char *note = dong + pos;
                note[strcspn(note, "\n")] = '\0';
                if (note[0] == '\0') { note[0] = '-'; note[1] = '\0'; }
                printf("  + #%d\n", store_add(s, amount, cat, note));
            } else {
                printf("  cu phap: chi <so tien> <danh muc> <ghi chu>\n");
            }
        } else if (strcmp(cmd, "xoa") == 0 && sscanf(dong, "%*s %d", &id) == 1) {
            if (store_remove(s, id)) printf("  da xoa #%d\n", id);
            else printf("  khong thay #%d\n", id);
        } else if (strcmp(cmd, "in") == 0) {
            in_danh_sach(s);
        } else if (strcmp(cmd, "tong") == 0) {
            printf("  Tong chi: %ld\n", store_total(s));
        } else if (strcmp(cmd, "nhom") == 0) {
            in_theo_nhom(s);
        } else if (strcmp(cmd, "thoat") == 0) {
            break;
        }
    }

    store_save(s, FILE_PATH);
    store_destroy(s);
    return 0;
}
