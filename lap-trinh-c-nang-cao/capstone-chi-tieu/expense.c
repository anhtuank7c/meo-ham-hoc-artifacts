#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "expense.h"

/* ==========================================================================
 * BO KHUNG DUNG CHUNG (sao tu du an Todo, doi Task -> Expense).
 * Phan nay GIONG het moi du an — ban hau nhu khong phai dong vao.
 * ========================================================================== */
struct ExpenseStore {
    Expense *items;
    int      len, cap;
    int      next_id;
};

ExpenseStore *store_create(void) {
    ExpenseStore *s = malloc(sizeof *s);
    if (!s) return NULL;
    s->items = NULL; s->len = s->cap = 0; s->next_id = 1;
    return s;
}

void store_destroy(ExpenseStore *s) {
    if (!s) return;
    free(s->items);
    free(s);
}

static bool grow(ExpenseStore *s) {
    if (s->len < s->cap) return true;
    int cap = s->cap ? s->cap * 2 : 4;
    Expense *p = realloc(s->items, (size_t)cap * sizeof *p);
    if (!p) return false;
    s->items = p; s->cap = cap;
    return true;
}

int store_add(ExpenseStore *s, long amount, const char *category, const char *note) {
    if (!grow(s)) return -1;
    Expense *e = &s->items[s->len++];
    e->id = s->next_id++;
    e->amount = amount;
    snprintf(e->category, sizeof e->category, "%s", category);
    snprintf(e->note, sizeof e->note, "%s", note);
    return e->id;
}

int      store_count(const ExpenseStore *s) { return s->len; }
Expense *store_at(ExpenseStore *s, int i) { return (i >= 0 && i < s->len) ? &s->items[i] : NULL; }

bool store_remove(ExpenseStore *s, int id) {
    for (int i = 0; i < s->len; i++)
        if (s->items[i].id == id) {
            s->items[i] = s->items[--s->len];
            return true;
        }
    return false;
}

/* --- Storage: moi dong "id|amount|category|note" (cung khung, doi dinh dang) --- */
bool store_save(const ExpenseStore *s, const char *path) {
    FILE *f = fopen(path, "w");
    if (!f) return false;
    for (int i = 0; i < s->len; i++) {
        const Expense *e = &s->items[i];
        fprintf(f, "%d|%ld|%s|%s\n", e->id, e->amount, e->category, e->note);
    }
    fclose(f);
    return true;
}

bool store_load(ExpenseStore *s, const char *path) {
    FILE *f = fopen(path, "r");
    if (!f) return true;        /* chua co file = rong, khong loi */
    char line[200];
    while (fgets(line, sizeof line, f)) {
        int id; long amount; char cat[24], note[80];
        if (sscanf(line, "%d|%ld|%23[^|]|%79[^\n]", &id, &amount, cat, note) == 4) {
            store_add(s, amount, cat, note);
            Expense *e = &s->items[s->len - 1];
            e->id = id;
            if (id >= s->next_id) s->next_id = id + 1;
        }
    }
    fclose(f);
    return true;
}

/* ==========================================================================
 * NGHIEP VU RIENG — phan BAN tu cai dat (Cot moc 3 & 4).
 * Hai ham nay NAM TRONG expense.c nen thay duoc bo cuc struct: duyet bang
 * `s->len` va `s->items[i].amount`. So sanh chuoi bang strcmp(a, b) == 0.
 * ========================================================================== */

long store_total(const ExpenseStore *s) {
    /* TODO (Cot moc 3): for (i = 0..s->len) cong don s->items[i].amount. */
    (void)s;
    return 0;
}

long store_total_of(const ExpenseStore *s, const char *category) {
    /* TODO (Cot moc 4): nhu tren, nhung chi cong khi
       strcmp(s->items[i].category, category) == 0. */
    (void)s; (void)category;
    return 0;
}
