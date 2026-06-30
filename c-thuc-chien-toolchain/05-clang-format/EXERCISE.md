# Lab 05 — Định dạng mã (clang-format)

**Mục tiêu:** định dạng một file C lộn xộn bằng `clang-format`, hiểu file `.clang-format`, và chạy kiểm tra kiểu CI.

Bài học liên quan: [Định dạng mã (clang-format)](https://emyeukhoahoc.anhtuank7c.dev/khoa-hoc/c-thuc-chien-toolchain/clang-format)

File: `messy.c` (cố ý lộn xộn), `.clang-format` (style của dự án).

Cần: `clang-format` (đi kèm LLVM/Clang; `brew install clang-format` hoặc `apt install clang-format`).

---

## Phần 1 — Xem trước (chưa ghi đè)

```bash
clang-format messy.c        # in ban da dinh dang ra man hinh; KHONG sua file
```

So sánh với bản gốc. clang-format đã dùng `.clang-format` ở cùng thư mục (4 space, `int *p`, không gộp if/hàm một dòng).

## Phần 2 — Kiểm tra kiểu CI

```bash
clang-format --dry-run --Werror messy.c     # bao loi vi file CHUA dung dinh dang
echo "Exit code: $?"                         # khac 0 -> CI se fail
```

Đây chính là cách pipeline chặn code chưa format. Thử với một file đã đẹp sẵn → exit code 0.

## Phần 3 — Định dạng tại chỗ

```bash
git diff messy.c            # (neu o trong repo) — chua co thay doi
clang-format -i messy.c     # ghi de file bang ban da dinh dang
# xem ket qua:
cat messy.c
```

## Phần 4 — Đổi style & quan sát

Sửa `.clang-format`: đổi `PointerAlignment: Right` thành `Left`, `IndentWidth: 4` thành `2`. Rồi:

```bash
clang-format messy.c | head
```

Thấy `int* p` (Left) và thụt lề 2 cột. Đổi `BasedOnStyle: LLVM` sang `Google` và so sánh.

## Phần 5 — Chừa một vùng

Thêm vào `messy.c` một bảng căn tay, bọc bằng `// clang-format off` … `// clang-format on`, rồi format lại — vùng đó được giữ nguyên.

---

✅ **Xong khi bạn:** chạy được cả ba chế độ (xem / kiểm tra / ghi đè), chỉnh `.clang-format` và thấy kết quả đổi theo, và biết cách chừa một vùng khỏi định dạng.
