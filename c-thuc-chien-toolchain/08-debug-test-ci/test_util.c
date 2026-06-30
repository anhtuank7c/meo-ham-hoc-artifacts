#include <assert.h>

#include "util.h"

/* Unit test theo mẫu Arrange–Act–Assert. ctest coi exit 0 = pass;
 * assert trượt -> abort -> exit khác 0 -> test FAIL. */
int main(void) {
    assert(binh_phuong(3) == 9);
    assert(binh_phuong(0) == 0);
    assert(binh_phuong(-2) == 4);

    /* THỬ THÁCH: bỏ comment dòng dưới và chạy lại `ctest`. Nó sẽ TRƯỢT vì
     * lỗi off-by-one trong tong_den(). Dùng gdb/lldb tìm & sửa util.c
     * (đổi  i < n  thành  i <= n), rồi test xanh trở lại. */
    /* assert(tong_den(5) == 15); */

    return 0;
}
