/* Unit test cho module Stack — kiem MOT don vi (module) co lap.
 * Moi test: ARRANGE (dung canh) -> ACT (goi ham) -> ASSERT (khang dinh ket qua).
 * Phu 3 nhom: duong di thuong (happy), bien (edge), va duong loi (error). */
#include "stack.h"
#include "test.h"

/* --- happy path --- */
static void test_stack_moi_thi_rong(void) {
    Stack *s = stack_create();
    CHECK(s != NULL);
    CHECK(stack_count(s) == 0);
    CHECK(stack_empty(s) == 1);
    stack_destroy(s);
}

static void test_push_roi_pop_la_lifo(void) {
    Stack *s = stack_create();
    CHECK(stack_push(s, 10) == 1);
    CHECK(stack_push(s, 20) == 1);
    CHECK(stack_count(s) == 2);

    int x = 0;
    CHECK(stack_pop(s, &x) == 1);
    CHECK(x == 20); /* LIFO: phan tu vao sau ra truoc */
    CHECK(stack_pop(s, &x) == 1);
    CHECK(x == 10);
    CHECK(stack_empty(s) == 1);
    stack_destroy(s);
}

/* --- error path: pop khi rong PHAI duoc xu ly, khong duoc sap --- */
static void test_pop_khi_rong_duoc_xu_ly(void) {
    Stack *s = stack_create();
    int x = 123;
    CHECK(stack_pop(s, &x) == 0); /* bao that bai */
    CHECK(x == 123);              /* va KHONG ghi vao *out */
    stack_destroy(s);
}

/* --- table-driven: mot du lieu, lap qua nhieu truong hop --- */
static void test_table_driven_nhieu_phan_tu(void) {
    int input[] = {1, 2, 3, 4, 5};
    int n = (int)(sizeof input / sizeof input[0]);
    Stack *s = stack_create();
    for (int i = 0; i < n; i++) {
        CHECK(stack_push(s, input[i]) == 1);
    }
    CHECK(stack_count(s) == n);
    for (int i = n - 1; i >= 0; i--) { /* pop ra thu tu nguoc */
        int x = 0;
        CHECK(stack_pop(s, &x) == 1);
        CHECK(x == input[i]);
    }
    stack_destroy(s);
}

int main(void) {
    RUN(test_stack_moi_thi_rong);
    RUN(test_push_roi_pop_la_lifo);
    RUN(test_pop_khi_rong_duoc_xu_ly);
    RUN(test_table_driven_nhieu_phan_tu);
    return TEST_REPORT();
}
