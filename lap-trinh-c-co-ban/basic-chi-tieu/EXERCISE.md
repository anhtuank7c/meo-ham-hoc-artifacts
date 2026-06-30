# Capstone (Basic C) · Chi tiêu (starter)

**Khung khởi đầu** cho dự án thứ hai ở bài *“Dự án cuối khoá: 3 app nhỏ”* (khoá **Lập trình C cơ bản**). Phần nhập/in đã có sẵn — **việc của bạn là viết vòng lặp tính tổng**.

## Đã cho sẵn
- Hai mảng song song: `so_tien[]` (số tiền, kiểu `long`) và `danh_muc[]` (nhóm chi).
- Menu: `1` ghi một khoản · `2` in các khoản · `3` tổng chi · `0` thoát.

## Việc của bạn (TODO trong `main.c`, nhánh `chon == 3`)
Viết một vòng `for` chạy `i` từ `0` đến `n-1`, cộng dồn `so_tien[i]` vào biến `tong`:

```c
for (int i = 0; i < n; i++) tong += so_tien[i];
```

> Dùng `long` (không dùng `float`) cho tiền để khỏi sai số làm tròn. Đây đúng là mẫu “duyệt mảng cộng dồn” ở bài *Mảng & chuỗi*.

## Build & chạy
```bash
make
./chi-tieu
```
Trước khi điền TODO, `3` (Tổng) luôn in `0` — đó là dấu hiệu cần viết vòng lặp. Sau khi xong, ghi 50000 + 20000 rồi `3` phải ra `Tong chi: 70000`.

## Definition of Done
- [ ] `make` sạch (`-Wall -Wextra`), không cảnh báo.
- [ ] `3` cộng đúng tổng tất cả khoản đã ghi.
- [ ] **Bonus:** thêm lệnh “tổng theo nhóm” — chỉ cộng khi `strcmp(danh_muc[i], muc) == 0`.
