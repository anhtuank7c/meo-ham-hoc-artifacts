# Capstone (Toolchain) · Dự án xuất xưởng

Bài cuối khoá **C Thực Chiến · Toolchain & Kiểm soát chất lượng**. Bạn lấy **một dự án thật** — app Todo module-hoá từ khoá *C nâng cao* (`include/task.h` + `src/store.c` + `src/main.c`) — rồi **áp trọn quy trình chất lượng** đã học: định dạng → cảnh báo → phân tích tĩnh → test → sanitizer → CI. Mục tiêu: mọi **cổng chất lượng đều xanh** ⇒ dự án "xuất xưởng được".

## Bố cục dự án

```
09-du-an-xuat-xuong/
├── include/task.h            # interface công khai (Model + Store opaque)
├── src/store.c               # implementation (mảng động) + storage
├── src/main.c                # CLI
├── tests/test_store.c        # unit test (assert) — chạy bằng CTest
├── CMakeLists.txt            # build + bật test
├── .clang-format             # phong cách thống nhất
├── .clang-tidy               # phân tích tĩnh
└── .github/workflows/ci.yml  # chạy hết các cổng mỗi push
```

## 6 cổng chất lượng

| # | Cổng | Lệnh |
|---|---|---|
| 1 | Định dạng | `clang-format --dry-run --Werror $(git ls-files '*.c' '*.h')` |
| 2 | Cảnh báo = lỗi | cấu hình với `-Werror` rồi `cmake --build build` |
| 3 | Phân tích tĩnh | `clang-tidy -p build $(git ls-files 'src/*.c')` |
| 4 | Unit test | `ctest --test-dir build --output-on-failure` |
| 5 | Sanitizer | cấu hình với `-fsanitize=address,undefined` rồi chạy lại test |
| 6 | CI | `.github/workflows/ci.yml` chạy cổng 1→5 tự động |

## Build & chạy tất cả cổng (trên máy)

```bash
# Cổng 1 — định dạng
clang-format --dry-run --Werror $(git ls-files '*.c' '*.h')

# Cổng 2 — build với cảnh báo = lỗi
cmake -S . -B build -DCMAKE_C_FLAGS="-Werror"
cmake --build build

# Cổng 3 — phân tích tĩnh (đọc compile_commands.json trong build/)
clang-tidy -p build $(git ls-files 'src/*.c')

# Cổng 4 — test
ctest --test-dir build --output-on-failure

# Cổng 5 — test dưới ASan + UBSan
cmake -S . -B build-san -DCMAKE_C_FLAGS="-fsanitize=address,undefined -g"
cmake --build build-san
ctest --test-dir build-san --output-on-failure

./build/todo   # chạy thử app
```

## Vì sao tắt vài kiểm tra của clang-tidy?

`.clang-tidy` ở đây **bật** `readability-braces-around-statements` (luôn có `{ }` — chính lỗi này gây ra bug **“goto fail”** nổi tiếng của Apple năm 2014) nhưng **tắt** hai cái thường gây nhiễu ở dự án thật: `insecureAPI.DeprecatedOrUnsafeBufferHandling` (đòi hàm `_s` của Annex K, không khả chuyển) và `readability-magic-numbers`. Một `.clang-tidy` tốt là cấu hình **vừa đủ nghiêm** cho đội của bạn — không phải bật tất cả.

## Definition of Done

- [ ] Cả 6 cổng đều **xanh** trên máy bạn.
- [ ] Thêm một `clang-format` sai (vd thụt lề lệch) → cổng 1 bắt được; sửa lại cho xanh.
- [ ] Thêm một test mới trong `tests/test_store.c` (vd kiểm `store_remove` phần tử giữa) → vẫn xanh.
- [ ] Đẩy lên GitHub: tab **Actions** chạy `ci.yml` và báo xanh. Đây là dự án để khoe nhà tuyển dụng.
