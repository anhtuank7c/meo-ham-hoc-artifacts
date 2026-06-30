#ifndef TEST_H
#define TEST_H
/* ===========================================================================
 * Mot framework kiem thu TI HON (~20 dong) — de hieu "duoi nap" mot framework
 * lam gi. Du framework that (Unity, CMocka) phong phu hon, loi van la 3 thu nay:
 *   1) mot cach VIET kiem tra        -> macro CHECK(cond)
 *   2) mot cach GOM & CHAY cac test  -> macro RUN(test)
 *   3) mot BAO CAO + ma thoat        -> TEST_REPORT()  (0 = pass, 1 = fail)
 * CTest doc ma thoat de bao xanh/do.
 * =========================================================================== */
#include <stdio.h>

static int tests_checks = 0;
static int tests_failed = 0;

/* Mot khang dinh (assert) — KHONG dung abort de cac test sau van chay. */
#define CHECK(cond)                                                            \
    do {                                                                       \
        tests_checks++;                                                        \
        if (!(cond)) {                                                         \
            tests_failed++;                                                    \
            printf("  THAT BAI: %s  (dong %d)\n", #cond, __LINE__);            \
        }                                                                      \
    } while (0)

/* Chay mot ham test va in ten no. */
#define RUN(test)                                                              \
    do {                                                                       \
        printf("== %s ==\n", #test);                                           \
        test();                                                                \
    } while (0)

/* In tong ket; tra ma thoat cho CTest (0 = tat ca xanh). */
#define TEST_REPORT()                                                          \
    (printf("\n%d kiem tra, %d that bai\n", tests_checks, tests_failed),       \
     tests_failed == 0 ? 0 : 1)

#endif
