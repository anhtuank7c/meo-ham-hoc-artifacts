# Lab 08 — Gỡ lỗi, kiểm thử & CI

**Mục tiêu:** build một dự án CMake có **unit test**, chạy `ctest`, **gỡ một lỗi** bằng gdb/lldb, và đọc một **workflow CI** mẫu — khép lại khoá Toolchain.

Bài học liên quan: [Gỡ lỗi, kiểm thử & CI](https://emyeukhoahoc.anhtuank7c.dev/khoa-hoc/c-thuc-chien-toolchain/debug-test-ci)

File: `util.c/.h` (có một bug off-by-one cài sẵn trong `tong_den`), `main.c`, `test_util.c`, `CMakeLists.txt`, `.github/workflows/ci.yml` (CI mẫu).

Cần: `cmake`, `gcc`/`clang`, và `gdb` (Linux) hoặc `lldb` (macOS).

---

## Phần 1 — Build & test

```bash
cmake -S . -B build && cmake --build build
ctest --test-dir build --output-on-failure   # PASS (chi test binh_phuong)
./build/app                                   # tong_den(5) in 10 — SAI! (dung phai 15)
```

`app` in ra `tong_den(5) = 10` nhưng 1+2+3+4+5 = **15**. Có lỗi.

## Phần 2 — Bắt lỗi bằng test

Mở `test_util.c`, bỏ comment dòng:

```c
assert(tong_den(5) == 15);
```

Build lại & `ctest` → test **TRƯỢT**. Giờ ta có một test đỏ tái hiện bug.

## Phần 3 — Gỡ lỗi bằng gdb / lldb

```bash
# Linux:
gdb ./build/app
(gdb) break tong_den
(gdb) run
(gdb) print n            # n = 5
(gdb) next               # buoc qua tung dong
(gdb) print tong i       # theo doi 'tong' va 'i' qua tung vong
(gdb) continue

# macOS:
lldb ./build/app
(lldb) b tong_den
(lldb) run
(lldb) p n
(lldb) n
(lldb) p tong
```

**Quan sát:** vòng lặp dừng khi `i < n`, nên `i` chỉ chạy 1..4, bỏ sót `i = 5`. Đó là off-by-one.

## Phần 4 — Sửa & xác nhận

Trong `util.c`, đổi `i < n` thành `i <= n`. Rồi:

```bash
cmake --build build && ctest --test-dir build   # test XANH tro lai
./build/app                                      # tong_den(5) = 15
```

## Phần 5 — Đọc CI

```bash
cat .github/workflows/ci.yml
```

Đây là CI chạy: kiểm tra định dạng → build (có ASan/UBSan) → test. Để dùng cho dự án THẬT của bạn, đặt file này ở `.github/workflows/` của repo gốc (GitHub chỉ chạy workflow ở gốc repo).

---

✅ **Xong khi bạn:** chạy được `ctest`, tái hiện bug bằng một test đỏ, dùng gdb/lldb tìm đúng dòng lỗi, sửa cho test xanh, và đọc hiểu workflow CI.
