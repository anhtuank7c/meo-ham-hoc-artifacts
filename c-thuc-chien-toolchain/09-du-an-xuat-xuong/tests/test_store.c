/* Unit test cho module store — chay duoi CTest (xem CMakeLists.txt).
 * Dung assert(): sai mot dieu kien la chuong trinh abort, CTest bao FAIL. */
#include "task.h"
#include <assert.h>
#include <stdio.h>

int main(void) {
    TaskStore *s = store_create();
    assert(s != NULL);
    assert(store_count(s) == 0);

    int id1 = store_add(s, "viec A");
    int id2 = store_add(s, "viec B");
    assert(store_count(s) == 2);
    assert(id1 != id2); /* id tu tang, khong trung */

    assert(store_at(s, 0) != NULL);
    assert(store_at(s, 9) == NULL); /* ngoai pham vi -> NULL  */

    assert(store_done(s, id1) == true);
    assert(store_done(s, 999) == false); /* id khong ton tai       */
    assert(store_at(s, 0)->done == true);

    assert(store_remove(s, id2) == true);
    assert(store_remove(s, id2) == false);
    assert(store_count(s) == 1);

    store_destroy(s);
    printf("OK: tat ca assert deu dung\n");
    return 0;
}
