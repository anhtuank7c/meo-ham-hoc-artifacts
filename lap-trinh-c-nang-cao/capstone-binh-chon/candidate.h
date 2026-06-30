#ifndef CANDIDATE_H
#define CANDIDATE_H
#include <stdbool.h>

/* Model: mot ung vien. votes tang dan moi khi co nguoi bo phieu. */
typedef struct {
    int  id;
    char name[60];
    int  votes;
} Candidate;

/* Store: kho chua cac Candidate — OPAQUE (giau cau truc o candidate.c) */
typedef struct CandidateStore CandidateStore;

CandidateStore *store_create(void);
void            store_destroy(CandidateStore *s);

int        store_add(CandidateStore *s, const char *name);  /* dang ky; tra id */
int        store_count(const CandidateStore *s);
Candidate *store_at(CandidateStore *s, int index);
bool       store_remove(CandidateStore *s, int id);

/* --- Nghiep vu rieng cua du an nay (BAN se cai dat trong candidate.c) --- */
bool       store_vote(CandidateStore *s, int id);    /* tim theo id roi votes++ */
Candidate *store_leader(CandidateStore *s);          /* ung vien nhieu phieu nhat */

bool store_save(const CandidateStore *s, const char *path);
bool store_load(CandidateStore *s, const char *path);

#endif
