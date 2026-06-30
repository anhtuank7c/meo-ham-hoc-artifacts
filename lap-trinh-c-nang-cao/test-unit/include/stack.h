#ifndef STACK_H
#define STACK_H

/* Stack so nguyen — OPAQUE (giau cau truc o stack.c). Day la "don vi" (unit)
 * ta se kiem thu: hop dong ro rang, co duong loi de test.
 *
 * Hop dong cac ham (interface = lời hứa để viết test):
 *   stack_create : tra con tro moi, hoac NULL neu het bo nho.
 *   stack_push   : tra 1 neu them duoc, 0 neu that bai.
 *   stack_pop    : tra 1 va ghi gia tri vao *out neu co; tra 0 neu RONG
 *                  (KHONG dung *out khi rong).
 *   stack_count  : so phan tu hien co.
 *   stack_empty  : 1 neu rong, 0 neu khong.
 */
typedef struct Stack Stack;

Stack *stack_create(void);
void   stack_destroy(Stack *s);
int    stack_push(Stack *s, int x);
int    stack_pop(Stack *s, int *out);
int    stack_count(const Stack *s);
int    stack_empty(const Stack *s);

#endif
