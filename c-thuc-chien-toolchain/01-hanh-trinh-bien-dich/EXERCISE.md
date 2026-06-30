# Lab 01 — Hành trình biên dịch

**Mục tiêu:** tự tay đưa một file C qua từng giai đoạn (tiền xử lý → dịch → hợp dịch → liên kết), nhìn tận mắt từng sản phẩm trung gian, và tái tạo + sửa lỗi liên kết kinh điển.

Bài học liên quan: [Hành trình biên dịch](https://emyeukhoahoc.anhtuank7c.dev/khoa-hoc/c-thuc-chien-toolchain/hanh-trinh-bien-dich)

---

## Phần 1 — Dừng gcc ở từng giai đoạn

```bash
gcc -E hello.c -o hello.i    # 1. Tiền xử lý: bung #include, #define, macro
gcc -S hello.c -o hello.s    # 2. Dịch: ra hợp ngữ (.s)
gcc -c hello.c -o hello.o    # 3. Hợp dịch: ra file đối tượng (.o)
gcc hello.o -o hello         # 4. Liên kết: ra chương trình chạy được
./hello
```

**Quan sát & trả lời:**
1. Mở `hello.i` — `#define MAX 100` và `GAP(5)` biến thành gì? Còn dòng nào bắt đầu bằng `#` không?
2. Mở `hello.s` — bạn thấy tên lệnh CPU / thanh ghi nào không? (đây là assembly)
3. `file hello.o` và `file hello` in ra gì khác nhau? (một cái "relocatable", một cái "executable")
4. `nm hello.o` — ký hiệu nào là `U` (undefined, còn thiếu)? `printf` ở đâu ra?

## Phần 2 — Macro & ngoặc

Trong `hello.c`, đổi `#define GAP(x) ((x) + (x))` thành `#define GAP(x) x + x` (bỏ ngoặc), rồi:

```bash
gcc -E hello.c | tail -5      # xem GAP(5) bung ra sao
```

Thử thêm `int z = 10 / GAP(5);` và dự đoán kết quả TRƯỚC khi chạy. Vì sao ngoặc lại quan trọng?

## Phần 3 — Tái tạo & sửa "undefined reference"

```bash
gcc needs_math.c -o needs_math      # CỐ Ý lỗi: undefined reference to 'sqrt'
```

> **Lưu ý nền tảng:** lỗi này xuất hiện trên **Linux** (glibc tách thư viện math). Trên **macOS**, `sqrt` đã nằm sẵn trong libSystem nên lệnh trên *vẫn chạy* — đây cũng là một bài học thực chiến: hành vi liên kết khác nhau giữa các hệ. Dùng Linux/WSL để thấy đúng lỗi, hoặc tin lời và tập thói quen thêm `-lm`.

- Lỗi này thuộc giai đoạn nào? (gợi ý: trình `ld`)
- Sửa bằng cách nối thư viện math:

```bash
gcc needs_math.c -lm -o needs_math && ./needs_math
```

## Phần 4 — Đọc một lệnh chuyên nghiệp

```bash
gcc -Wall -Wextra -Werror -g -O2 -std=c17 hello.c -o hello
```

Giải thích vai trò từng cờ. Thử thêm một cảnh báo (vd biến không dùng) và xem `-Werror` biến nó thành lỗi thế nào.

---

✅ **Xong khi bạn:** giải thích được mỗi file `.i/.s/.o` chứa gì, biết `undefined reference` là lỗi liên kết và cách sửa, và đọc được một dòng `gcc` đầy cờ.
