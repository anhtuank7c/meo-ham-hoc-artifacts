# Kiểm thử đơn vị (unit test) · module Stack

Bài lab cho *Unit test* (khoá **Lập trình C nâng cao**). Bạn kiểm thử **một module C cô lập** — `Stack` opaque — bằng một **framework tí hon tự viết** (`tests/test.h`, ~20 dòng) chạy qua **CTest**.

## Có gì sẵn

```
test-unit/
├── include/stack.h     # interface (HỢP ĐỒNG để viết test)
├── src/stack.c         # module đang kiểm thử (unit under test)
├── tests/test.h        # framework tí hon: CHECK / RUN / TEST_REPORT
├── tests/test_stack.c  # 4 unit test: happy · edge · error · table-driven
└── CMakeLists.txt      # build + CTest (bật ASan bằng -DSAN=ON)
```

## Build & chạy

```bash
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure   # hoặc chạy thẳng ./build/test_stack
```

## Bài tập (Definition of Done)

- [ ] `ctest` xanh: `29 kiem tra, 0 that bai`.
- [ ] **Test bắt bug:** sửa `stack_pop` lấy `s->data[0]` (biến LIFO thành FIFO). Chạy lại — test `test_push_roi_pop_la_lifo` báo `THAT BAI: x == 20`. Khôi phục lại cho xanh. *(Đây là điểm cốt lõi: test giữ cho bạn không phá vỡ hành vi đúng.)*
- [ ] **Thêm một unit test:** vd `test_push_qua_suc_chua` — push hơn 4 phần tử để ép mảng lớn lên, kiểm `count` đúng và pop ra đủ.
- [ ] **Đường lỗi:** đã có `test_pop_khi_rong_duoc_xu_ly`. Giải thích vì sao phải test cả đường lỗi, không chỉ happy path.
- [ ] **Chạy dưới sanitizer:** `cmake -S . -B build-san -DSAN=ON && cmake --build build-san && ctest --test-dir build-san`. Test xanh *và* sạch bộ nhớ.

## Ghi chú

- **Test double / stub:** muốn test nhánh `stack_create` trả `NULL` (hết bộ nhớ), bạn cần *thay* `malloc` bằng một bản giả luôn thất bại — đó là một **test double**. Kỹ thuật này (và framework thật như **Unity**, **CMocka**, cùng CI) học sâu ở khoá **C Thực Chiến · Toolchain**.
- Framework tí hon ở đây chỉ để hiểu **dưới nắp** một framework làm gì: một cách viết khẳng định, một cách gom & chạy, một mã thoát cho CTest.
