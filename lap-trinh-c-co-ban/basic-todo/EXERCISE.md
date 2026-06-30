# Capstone (Basic C) · Todo

Bản **mẫu hoàn chỉnh** cho dự án Todo ở bài *“Dự án cuối khoá: 3 app nhỏ”* (khoá **Lập trình C cơ bản**). Chỉ dùng những gì khoá cơ bản đã dạy: **mảng, vòng lặp, rẽ nhánh, hàm `main`, nhập/xuất** — không struct, không con trỏ, không file.

## Ý tưởng: hai mảng song song

```
tieu_de[0]="hoc bai C"   xong[0]=1   ← cùng chỉ số 0
tieu_de[1]="di cho"      xong[1]=0   ← cùng chỉ số 1
```

Hai mảng `tieu_de[]` và `xong[]` luôn **thẳng hàng theo chỉ số `i`**: phần tử thứ `i` của mảng này ứng với phần tử thứ `i` của mảng kia. Đó là cách lưu “một bản ghi nhiều thuộc tính” khi **chưa học struct**.

## Build & chạy

```bash
make
./todo
```

Menu số: `1` thêm việc · `2` đánh dấu xong · `3` in danh sách · `0` thoát.

## Tự kiểm (Definition of Done)

- [ ] `make` biên dịch sạch với `-Wall -Wextra`, không cảnh báo.
- [ ] Thêm vài việc → `3` in đúng, `[x]` cho việc đã đánh dấu xong.
- [ ] `2` rồi nhập số thứ tự (đếm từ 1) đổi đúng việc tương ứng.
- [ ] Hiểu vì sao `xong[so - 1]`: người dùng đếm từ 1, mảng đếm từ 0.

## Bước tiếp

App này **mất dữ liệu khi thoát** (chỉ ở trong bộ nhớ) và dùng *hai mảng rời*. Ở khoá **Lập trình C nâng cao**, bạn sẽ gom `tieu_de` + `xong` vào một **struct** gọn gàng, và **lưu ra file** để nhớ qua mỗi lần chạy. Cùng một sản phẩm, code sạch hơn nhiều.
