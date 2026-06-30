#ifndef TASK_H
#define TASK_H
#include <stdbool.h>

/* Model: mot viec can lam (struct nho, trong suot) */
typedef struct {
    int  id;
    char title[80];
    bool done;
} Task;

/* Store: kho chua cac Task — OPAQUE (giau cau truc o store.c) */
typedef struct TaskStore TaskStore;

TaskStore *store_create(void);
void       store_destroy(TaskStore *s);

int   store_add(TaskStore *s, const char *title); /* tra id moi; -1 neu loi */
bool  store_done(TaskStore *s, int id);           /* danh dau xong */
bool  store_remove(TaskStore *s, int id);
int   store_count(const TaskStore *s);
Task *store_at(TaskStore *s, int index);          /* lay theo chi so de in */

bool  store_save(const TaskStore *s, const char *path);
bool  store_load(TaskStore *s, const char *path);

#endif
