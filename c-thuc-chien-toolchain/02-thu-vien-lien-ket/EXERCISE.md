# Lab 02 — Thư viện & liên kết

**Mục tiêu:** chia một dự án thành nhiều file, hiểu trình liên kết ghép ký hiệu, rồi tự tay tạo **thư viện tĩnh (.a)** và **thư viện động (.so)** — và tái tạo lỗi `undefined reference`.

Bài học liên quan: [Thư viện & liên kết](https://emyeukhoahoc.anhtuank7c.dev/khoa-hoc/c-thuc-chien-toolchain/thu-vien-lien-ket)

File: `main.c` (dùng `binh_phuong`), `util.c` (định nghĩa nó), `util.h` (khai báo + include guard).

---

## Phần 1 — Biên dịch nhiều file & liên kết

```bash
gcc -c main.c -o main.o      # main.o: CAN binh_phuong (chua co)
gcc -c util.c -o util.o      # util.o: DINH NGHIA binh_phuong
gcc main.o util.o -o app     # lien ket: ghep 2 .o
./app
```

**Quan sát:**
- `nm main.o | grep binh_phuong` → ký hiệu là `U` (undefined, còn thiếu).
- `nm util.o | grep binh_phuong` → ký hiệu là `T` (defined, có trong .text).
- Trình liên kết nối `U` của main với `T` của util — đó là "giải quyết ký hiệu".

## Phần 2 — Tái tạo `undefined reference`

```bash
gcc main.o -o broken         # CO Y thieu util.o
# -> undefined reference to 'binh_phuong'
```

Lỗi này thuộc giai đoạn nào (gợi ý: `ld`)? Sửa bằng cách thêm `util.o` (hoặc một thư viện cung cấp `binh_phuong`).

## Phần 3 — Thư viện tĩnh (.a)

```bash
ar rcs libutil.a util.o              # dong goi thanh thu vien tinh
gcc main.c -L. -lutil -o app_tinh    # -L. tim o day; -lutil = libutil.a
./app_tinh
```

Thử đổi thứ tự: `gcc -L. -lutil main.c -o x` — trên một số hệ sẽ lỗi. Vì sao thứ tự lib quan trọng khi link tĩnh?

## Phần 4 — Thư viện động (.so / .dylib)

```bash
# Linux:
gcc -fPIC -shared util.c -o libutil.so
gcc main.c -L. -lutil -o app_dong
LD_LIBRARY_PATH=. ./app_dong         # can libutil.so luc CHAY
ldd app_dong                         # xem thu vien dong can

# macOS (đuôi .dylib, công cụ otool):
# gcc -dynamiclib util.c -o libutil.dylib
# gcc main.c -L. -lutil -o app_dong && ./app_dong
# otool -L app_dong
```

So sánh kích thước `app_tinh` (đã copy mã util vào) với `app_dong` (chưa). Xoá `libutil.so` rồi chạy `app_dong` — lỗi gì? (đó là lý do link động cần thư viện lúc chạy).

---

✅ **Xong khi bạn:** giải thích được `U`/`T` trong `nm`, tạo được cả `.a` và `.so`, biết vì sao thứ tự lib quan trọng, và tái tạo + sửa được `undefined reference`.
