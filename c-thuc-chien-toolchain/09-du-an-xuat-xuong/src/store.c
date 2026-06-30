#include "task.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TaskStore { /* chi file nay biet bo cuc */
    Task *items;
    int len, cap;
    int next_id; /* id tu tang, khong trung */
};

TaskStore *store_create(void) {
    TaskStore *s = malloc(sizeof *s);
    if (!s) {
        return NULL;
    }
    s->items = NULL;
    s->len = s->cap = 0;
    s->next_id = 1;
    return s;
}

void store_destroy(TaskStore *s) {
    if (!s) {
        return;
    }
    free(s->items); /* tra lai bo nho da xin */
    free(s);
}

static bool grow(TaskStore *s) { /* RIENG (static): tang gap doi khi day */
    if (s->len < s->cap) {
        return true;
    }
    int cap = s->cap ? s->cap * 2 : 4;
    Task *p = realloc(s->items, (size_t)cap * sizeof *p);
    if (!p) {
        return false;
    }
    s->items = p;
    s->cap = cap;
    return true;
}

int store_add(TaskStore *s, const char *title) {
    if (!grow(s)) {
        return -1;
    }
    Task *t = &s->items[s->len++];
    t->id = s->next_id++;
    snprintf(t->title, sizeof t->title, "%s", title);
    t->done = false;
    return t->id;
}

static Task *find(TaskStore *s, int id) { /* RIENG: tim theo id */
    for (int i = 0; i < s->len; i++) {
        if (s->items[i].id == id) {
            return &s->items[i];
        }
    }
    return NULL;
}

bool store_done(TaskStore *s, int id) {
    Task *t = find(s, id);
    if (!t) {
        return false;
    }
    t->done = true;
    return true;
}

bool store_remove(TaskStore *s, int id) {
    for (int i = 0; i < s->len; i++) {
        if (s->items[i].id == id) {
            s->items[i] = s->items[--s->len]; /* lap muc cuoi vao cho trong */
            return true;
        }
    }
    return false;
}

int store_count(const TaskStore *s) {
    return s->len;
}
Task *store_at(TaskStore *s, int i) {
    return (i >= 0 && i < s->len) ? &s->items[i] : NULL;
}

/* --- Storage: moi dong la "id|done|title" --- */
bool store_save(const TaskStore *s, const char *path) {
    FILE *f = fopen(path, "w");
    if (!f) {
        return false;
    }
    for (int i = 0; i < s->len; i++) {
        fprintf(f, "%d|%d|%s\n", s->items[i].id, s->items[i].done, s->items[i].title);
    }
    fclose(f);
    return true;
}

bool store_load(TaskStore *s, const char *path) {
    FILE *f = fopen(path, "r");
    if (!f) {
        return true; /* chua co file = danh sach rong, khong loi */
    }
    char line[160];
    while (fgets(line, sizeof line, f)) {
        int id, done;
        char title[80];
        if (sscanf(line, "%d|%d|%79[^\n]", &id, &done, title) == 3) {
            store_add(s, title);
            Task *t = &s->items[s->len - 1];
            t->id = id;
            t->done = (done != 0);
            if (id >= s->next_id) {
                s->next_id = id + 1;
            }
        }
    }
    fclose(f);
    return true;
}
