# Capstone (Basic C) · Bình chọn (starter)

**Khung khởi đầu** cho dự án thứ ba ở bài *“Dự án cuối khoá: 3 app nhỏ”* (khoá **Lập trình C cơ bản**). Thêm/bỏ phiếu/in đã có sẵn — **việc của bạn là tìm người dẫn đầu** (bài toán tìm max).

## Đã cho sẵn
- Hai mảng song song: `ten[]` (tên ứng viên) và `phieu[]` (số phiếu).
- Menu: `1` thêm ứng viên · `2` bỏ phiếu · `3` xem kết quả · `0` thoát.
- Bỏ phiếu đã hoạt động: `phieu[so - 1]++`.

## Việc của bạn (TODO trong `main.c`, nhánh `chon == 3`)
Sau khi in danh sách, tìm chỉ số có `phieu[]` **lớn nhất** và gán vào `dan_dau`:

```c
int dan_dau = (n > 0) ? 0 : -1;
for (int i = 1; i < n; i++)
    if (phieu[i] > phieu[dan_dau]) dan_dau = i;
```

> Đây là mẫu **tìm max** kinh điển: giả sử phần tử đầu là lớn nhất, rồi duyệt phần còn lại, gặp ai nhiều phiếu hơn thì cập nhật.

## Build & chạy
```bash
make
./binh-chon
```
Thêm Lan & Minh, bỏ cho Lan 2 phiếu + Minh 1 phiếu, rồi `3`:
```
  1. Lan: 2 phieu
  2. Minh: 1 phieu
  >> Dan dau: Lan (2 phieu)
```

## Definition of Done
- [ ] `make` sạch (`-Wall -Wextra`), không cảnh báo.
- [ ] `>> Dan dau:` chỉ đúng ứng viên nhiều phiếu nhất.
- [ ] Đưa cả ba app (Todo · Chi tiêu · Bình chọn) lên GitHub — sản phẩm C đầu tay của bạn.
