#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "candidate.h"

/* ==========================================================================
 * BO KHUNG DUNG CHUNG (sao tu du an Todo, doi Task -> Candidate).
 * ========================================================================== */
struct CandidateStore {
    Candidate *items;
    int        len, cap;
    int        next_id;
};

CandidateStore *store_create(void) {
    CandidateStore *s = malloc(sizeof *s);
    if (!s) return NULL;
    s->items = NULL; s->len = s->cap = 0; s->next_id = 1;
    return s;
}

void store_destroy(CandidateStore *s) {
    if (!s) return;
    free(s->items);
    free(s);
}

static bool grow(CandidateStore *s) {
    if (s->len < s->cap) return true;
    int cap = s->cap ? s->cap * 2 : 4;
    Candidate *p = realloc(s->items, (size_t)cap * sizeof *p);
    if (!p) return false;
    s->items = p; s->cap = cap;
    return true;
}

int store_add(CandidateStore *s, const char *name) {
    if (!grow(s)) return -1;
    Candidate *c = &s->items[s->len++];
    c->id = s->next_id++;
    snprintf(c->name, sizeof c->name, "%s", name);
    c->votes = 0;
    return c->id;
}

int        store_count(const CandidateStore *s) { return s->len; }
Candidate *store_at(CandidateStore *s, int i) { return (i >= 0 && i < s->len) ? &s->items[i] : NULL; }

bool store_remove(CandidateStore *s, int id) {
    for (int i = 0; i < s->len; i++)
        if (s->items[i].id == id) {
            s->items[i] = s->items[--s->len];
            return true;
        }
    return false;
}

/* --- Storage: moi dong "id|votes|name" --- */
bool store_save(const CandidateStore *s, const char *path) {
    FILE *f = fopen(path, "w");
    if (!f) return false;
    for (int i = 0; i < s->len; i++)
        fprintf(f, "%d|%d|%s\n", s->items[i].id, s->items[i].votes, s->items[i].name);
    fclose(f);
    return true;
}

bool store_load(CandidateStore *s, const char *path) {
    FILE *f = fopen(path, "r");
    if (!f) return true;
    char line[120];
    while (fgets(line, sizeof line, f)) {
        int id, votes; char name[60];
        if (sscanf(line, "%d|%d|%59[^\n]", &id, &votes, name) == 3) {
            store_add(s, name);
            Candidate *c = &s->items[s->len - 1];
            c->id = id; c->votes = votes;
            if (id >= s->next_id) s->next_id = id + 1;
        }
    }
    fclose(f);
    return true;
}

/* ==========================================================================
 * NGHIEP VU RIENG — phan BAN tu cai dat (Cot moc 2 & 4).
 * Hai ham NAM TRONG candidate.c nen duyet thang bang s->len / s->items[i].
 * ========================================================================== */

bool store_vote(CandidateStore *s, int id) {
    /* TODO (Cot moc 2): tim ung vien co s->items[i].id == id roi votes++,
       tra ve true. Khong tim thay -> tra ve false. */
    (void)s; (void)id;
    return false;
}

Candidate *store_leader(CandidateStore *s) {
    /* TODO (Cot moc 4): duyet s, tra ve con tro toi ung vien co votes lon nhat.
       Kho rong -> tra ve NULL. (Bai toan tim max kinh dien.) */
    (void)s;
    return NULL;
}
