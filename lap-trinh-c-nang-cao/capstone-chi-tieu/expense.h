#ifndef EXPENSE_H
#define EXPENSE_H
#include <stdbool.h>

/* Model: mot khoan chi. amount la SO NGUYEN (dong) — dung float cho tien. */
typedef struct {
    int  id;
    long amount;
    char category[24];     /* vd "an-uong", "di-lai" */
    char note[80];
} Expense;

/* Store: kho chua cac Expense — OPAQUE (giau cau truc o expense.c) */
typedef struct ExpenseStore ExpenseStore;

ExpenseStore *store_create(void);
void          store_destroy(ExpenseStore *s);

int      store_add(ExpenseStore *s, long amount, const char *category, const char *note);
int      store_count(const ExpenseStore *s);
Expense *store_at(ExpenseStore *s, int index);
bool     store_remove(ExpenseStore *s, int id);

/* --- Nghiep vu rieng cua du an nay (BAN se cai dat trong expense.c) --- */
long store_total(const ExpenseStore *s);                          /* tong tat ca */
long store_total_of(const ExpenseStore *s, const char *category); /* tong 1 nhom */

bool store_save(const ExpenseStore *s, const char *path);
bool store_load(ExpenseStore *s, const char *path);

#endif
