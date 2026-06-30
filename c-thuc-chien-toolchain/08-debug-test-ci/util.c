#include "util.h"

int binh_phuong(int x) {
    return x * x;
}

/* 1 + 2 + ... + n. THỬ THÁCH: có một lỗi off-by-one ẩn ở đây —
 * dùng gdb/lldb để tìm (đặt breakpoint, in 'tong' qua từng vòng),
 * hoặc bật test_tong trong test_util.c để nó báo trượt. */
int tong_den(int n) {
    int tong = 0;
    for (int i = 1; i < n; i++) { /* <-- BUG: nên là i <= n */
        tong += i;
    }
    return tong;
}
