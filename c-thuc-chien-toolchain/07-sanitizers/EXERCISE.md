# Lab 07 — Sanitizers (ASan / UBSan)

**Mục tiêu:** biên dịch các chương trình có lỗi với sanitizer, chạy, và đọc **báo cáo runtime THẬT** — use-after-free, tràn bộ đệm, tràn số nguyên, rò rỉ.

Bài học liên quan: [Sanitizers](https://emyeukhoahoc.anhtuank7c.dev/khoa-hoc/c-thuc-chien-toolchain/sanitizers)

File: `uaf.c`, `overflow.c`, `ub.c`, `leak.c` (mỗi file một loại lỗi).

Cần: `gcc`/`clang` có hỗ trợ sanitizer (mặc định có trên Linux & macOS).

---

## Phần 1 — AddressSanitizer (ASan)

```bash
gcc -fsanitize=address -g uaf.c -o uaf && ./uaf
# -> heap-use-after-free: WRITE ... freed by ... previously allocated by ...

gcc -fsanitize=address -g overflow.c -o ov && ./ov
# -> heap-buffer-overflow tai i = 4
```

**Đọc báo cáo:** loại lỗi ở dòng đầu; rồi nơi TRUY CẬP sai; với UAF còn có nơi **freed** và nơi **allocated**. Đối chiếu với số dòng trong file.

So sánh: chạy `./uaf` mà KHÔNG có `-fsanitize=address` → có thể "chạy được" một cách may rủi (đó là sự nguy hiểm của UB — không phải lúc nào cũng sập).

## Phần 2 — UndefinedBehaviorSanitizer (UBSan)

```bash
gcc -fsanitize=undefined -g ub.c -o ub && ./ub
# -> runtime error: signed integer overflow: 2147483647 + 1 cannot be represented in type 'int'
```

UBSan in cảnh báo rồi vẫn chạy tiếp (mặc định). Thêm `-fno-sanitize-recover=all` để DỪNG ngay lỗi đầu.

## Phần 3 — Kết hợp ASan + UBSan

```bash
gcc -fsanitize=address,undefined -g overflow.c -o ov2 && ./ov2
```

Một bản build bắt cả hai họ lỗi. (Nhưng `address` + `thread` thì KHÔNG kết hợp.)

## Phần 4 — Rò rỉ (LeakSanitizer)

```bash
# Linux:
gcc -fsanitize=address -g leak.c -o lk && ./lk
# -> LeakSanitizer: detected memory leaks ... 100 byte(s)

# macOS (LeakSan thuong khong bat): dung valgrind hoac chay tren Linux/WSL
valgrind --leak-check=full ./lk   # neu co valgrind
```

## Phần 5 — Chạy test dưới sanitizer

Đây là cách dùng thật trong CI: build bản có sanitizer rồi chạy toàn bộ test — lỗi bộ nhớ nào chạm phải khi test chạy sẽ bị tóm ngay. Thử sửa từng file cho hết lỗi rồi chạy lại đến khi "sạch".

---

✅ **Xong khi bạn:** biên dịch & chạy được cả ba sanitizer, đọc được báo cáo (loại lỗi + vị trí + allocated/freed), biết ASan+UBSan kết hợp được còn ASan+TSan thì không, và hiểu macOS không bật LeakSan mặc định.
