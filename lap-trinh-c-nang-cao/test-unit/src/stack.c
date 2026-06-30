#include "stack.h"
#include <stdlib.h>

struct Stack {
    int *data;
    int  len, cap;
};

Stack *stack_create(void) {
    Stack *s = malloc(sizeof *s);
    if (!s) {
        return NULL;
    }
    s->data = NULL;
    s->len = s->cap = 0;
    return s;
}

void stack_destroy(Stack *s) {
    if (!s) {
        return;
    }
    free(s->data);
    free(s);
}

int stack_push(Stack *s, int x) {
    if (s->len >= s->cap) {
        int cap = s->cap ? s->cap * 2 : 4;
        int *p = realloc(s->data, (size_t)cap * sizeof *p);
        if (!p) {
            return 0; /* het bo nho — bao that bai */
        }
        s->data = p;
        s->cap = cap;
    }
    s->data[s->len++] = x;
    return 1;
}

int stack_pop(Stack *s, int *out) {
    if (s->len == 0) {
        return 0; /* RONG: khong dung *out, bao that bai */
    }
    *out = s->data[--s->len];
    return 1;
}

int stack_count(const Stack *s) {
    return s->len;
}

int stack_empty(const Stack *s) {
    return s->len == 0;
}
