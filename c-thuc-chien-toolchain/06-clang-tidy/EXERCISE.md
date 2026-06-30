# Lab 06 — Phân tích tĩnh (clang-tidy)

**Mục tiêu:** chạy `clang-tidy` trên một file có lỗi cài sẵn, hiểu file `.clang-tidy`, dùng `--fix`, và so sánh với cảnh báo trình biên dịch.

Bài học liên quan: [Phân tích tĩnh (clang-tidy)](https://emyeukhoahoc.anhtuank7c.dev/khoa-hoc/c-thuc-chien-toolchain/clang-tidy)

File: `buggy.c` (cố ý có lỗi), `.clang-tidy` (chọn nhóm check).

Cần: `clang-tidy` (đi kèm LLVM; `brew install llvm` hoặc `apt install clang-tidy`).

---

## Phần 1 — Lớp 1: cảnh báo trình biên dịch (miễn phí)

```bash
gcc -Wall -Wextra buggy.c -o app    # xem gcc canh bao gi (vd 'y = 1' trong if)
```

`-Wall -Wextra` đã bắt được vài lỗi mà không cần công cụ ngoài. Luôn bật chúng.

## Phần 2 — Lớp 2: clang-tidy

```bash
clang-tidy buggy.c -- -std=c17
```

Lưu ý dấu `--`: mọi thứ sau nó là cờ biên dịch (clang-tidy cần để dựng AST). Đọc các cảnh báo: mỗi cái có **dòng**, **thông điệp**, và **tên check** trong `[ ]`.

**Trả lời:** clang-tidy báo bao nhiêu vấn đề? Cái nào trùng với cảnh báo gcc, cái nào gcc không thấy?

## Phần 3 — Cấu hình nhóm check

Mở `.clang-tidy`: nó tắt hết (`-*`) rồi bật `clang-analyzer-*`, `bugprone-*`, và hai check readability. Thử bỏ `readability-magic-numbers` khỏi danh sách rồi chạy lại — cảnh báo số ma thuật biến mất.

```bash
clang-tidy buggy.c -- -std=c17 | grep -c warning   # dem so canh bao
```

## Phần 4 — Tự sửa (--fix)

```bash
cp buggy.c buggy.bak.c
clang-tidy --fix buggy.c -- -std=c17    # tu sua cac check co "fix-it"
diff buggy.bak.c buggy.c                 # xem nó da sua gi (vd them { })
```

Không phải check nào cũng tự sửa được (vd null-deref cần bạn thêm `if (!p) ...`). Sửa nốt phần còn lại bằng tay.

## Phần 5 — NOLINT

Thêm `// NOLINT` cuối một dòng bị báo và chạy lại — cảnh báo dòng đó biến mất. Chỉ dùng khi bạn CHẮC chắn đó là báo nhầm.

---

✅ **Xong khi bạn:** chạy được clang-tidy với cờ sau `--`, đọc được tên check, chỉnh `.clang-tidy` để đổi tập cảnh báo, dùng `--fix`, và biết khi nào dùng NOLINT.
