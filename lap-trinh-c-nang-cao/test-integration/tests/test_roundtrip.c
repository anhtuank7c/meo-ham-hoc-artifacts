/* INTEGRATION test: kiem hai module GHEP nhau o cho tiep giap —
 * Store (trong bo nho) + Storage (luu/doc tep). Khac unit test: o day ta
 * dung MOT TEP THAT, luu bang store_save roi doc lai bang store_load tu mot
 * store MOI (mo phong "tat roi mo lai app"), va khang dinh du lieu song sot.
 *
 * Cung minh hoa FIXTURE: dung tep tam (setup) roi don sach (teardown). */
#include "task.h"
#include "test.h"
#include <stdio.h>

static void test_save_load_roundtrip(void) {
    const char *path = "test_roundtrip.tmp"; /* FIXTURE: tep tam */

    /* --- ACT 1: dung store, them, danh dau, LUU ra tep --- */
    TaskStore *a = store_create();
    int id1 = store_add(a, "viec mot");
    int id2 = store_add(a, "viec hai");
    store_done(a, id1);
    CHECK(store_save(a, path) == true);
    store_destroy(a);

    /* --- ACT 2: store MOI DOC LAI tu tep (nhu mo lai app) --- */
    TaskStore *b = store_create();
    CHECK(store_load(b, path) == true);

    /* --- ASSERT: du lieu song sot qua bien gioi store <-> tep --- */
    CHECK(store_count(b) == 2);
    Task *t0 = store_at(b, 0);
    Task *t1 = store_at(b, 1);
    CHECK(t0 != NULL);
    CHECK(t1 != NULL);
    if (t0 && t1) { /* phong thu: neu load hong, khong deref NULL -> bao FAIL sach */
        CHECK(t0->id == id1);
        CHECK(t0->done == true); /* trang thai cung phai song sot */
        CHECK(t1->id == id2);
        CHECK(t1->done == false);
    }
    store_destroy(b);

    remove(path); /* TEARDOWN: don tep tam */
}

static void test_load_thieu_tep_la_rong(void) {
    /* Hop dong: load mot tep khong ton tai -> danh sach rong, KHONG loi */
    TaskStore *s = store_create();
    CHECK(store_load(s, "khong_ton_tai_12345.tmp") == true);
    CHECK(store_count(s) == 0);
    store_destroy(s);
}

int main(void) {
    RUN(test_save_load_roundtrip);
    RUN(test_load_thieu_tep_la_rong);
    return TEST_REPORT();
}
