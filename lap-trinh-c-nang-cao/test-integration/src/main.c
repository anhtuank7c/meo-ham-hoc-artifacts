#include <stdio.h>
#include <string.h>
#include "task.h"

#define FILE_PATH "todo.dat"

static void in_danh_sach(TaskStore *s) {
    int n = store_count(s), chua = 0;
    for (int i = 0; i < n; i++) {
        Task *t = store_at(s, i);
        printf("  #%-3d [%c] %s\n", t->id, t->done ? 'x' : ' ', t->title);
        if (!t->done) chua++;
    }
    if (n == 0) printf("  (trong)\n");
    printf("  -- con %d viec chua xong --\n", chua);
}

int main(void) {
    TaskStore *s = store_create();
    if (!s) return 1;
    store_load(s, FILE_PATH);

    char dong[120];
    printf("Lenh: them <viec> | xong <id> | xoa <id> | in | thoat\n");
    while (printf("> "), fgets(dong, sizeof dong, stdin)) {
        char cmd[16]; int id;
        if (sscanf(dong, "%15s", cmd) != 1) continue;

        if (strcmp(cmd, "them") == 0) {
            char *viec = dong + 4;                  /* bo qua "them " */
            while (*viec == ' ') viec++;
            viec[strcspn(viec, "\n")] = '\0';       /* bo ky tu xuong dong */
            if (*viec) printf("  + #%d\n", store_add(s, viec));
        } else if (strcmp(cmd, "xong") == 0 && sscanf(dong, "%*s %d", &id) == 1) {
            if (store_done(s, id)) printf("  da xong #%d\n", id);
            else printf("  khong thay #%d\n", id);
        } else if (strcmp(cmd, "xoa") == 0 && sscanf(dong, "%*s %d", &id) == 1) {
            if (store_remove(s, id)) printf("  da xoa #%d\n", id);
            else printf("  khong thay #%d\n", id);
        } else if (strcmp(cmd, "in") == 0) {
            in_danh_sach(s);
        } else if (strcmp(cmd, "thoat") == 0) {
            break;
        }
    }

    store_save(s, FILE_PATH);    /* luu truoc khi thoat */
    store_destroy(s);            /* tra het bo nho */
    return 0;
}
