# Capstone · Quản lý chi tiêu (starter)

**Khung khởi đầu** cho dự án thứ hai ở bài *“Dự án cuối khoá: 3 phần mềm thật”* (khoá **Lập trình C nâng cao**). Bộ khung (Store · Storage · CLI) đã có sẵn — **việc của bạn là viết phần nghiệp vụ**: cộng tổng và cộng theo nhóm.

## Đã cho sẵn

- `expense.h` — Model `Expense {id, amount, category, note}` + API.
- `expense.c` — bộ khung mảng động (create/add/remove/count/at) + save/load `chi-tieu.dat`. Đây là phần **tái dùng từ Todo**, đổi `Task → Expense`.
- `main.c` — vòng lặp lệnh `chi / xoa / in / tong / nhom / thoat` (đã xong, gọi vào hai hàm bạn sẽ viết).

## Việc của bạn (TODO trong `expense.c`)

| Cột mốc | Hàm | Yêu cầu |
|---|---|---|
| **3** | `store_total` | duyệt `s->items[i].amount`, trả về tổng tất cả khoản chi |
| **4** | `store_total_of` | như trên nhưng chỉ cộng khi `strcmp(category, ...) == 0` |

> Mẹo: hai hàm này **nằm trong `expense.c`** nên thấy được `struct ExpenseStore` — duyệt thẳng bằng `s->len` và `s->items[i]`. Dùng `long` để khỏi tràn khi cộng nhiều khoản.

## Build & chạy

```bash
make
./chi-tieu
```

Trước khi cài đặt, `tong` in `0` và `nhom` in mỗi danh mục `0` — đó là dấu hiệu bạn cần điền hai hàm. Sau khi xong:

```
> chi 50000 an-uong com trua
  + #1
> chi 20000 di-lai gui xe
  + #2
> chi 30000 an-uong ca phe
  + #3
> tong
  Tong chi: 100000
> nhom
  an-uong        80000
  di-lai         20000
> thoat
```

## Definition of Done

- [ ] `make` sạch (`-Wall -Wextra`), không cảnh báo.
- [ ] `tong` cộng đúng tổng; `nhom` cộng đúng theo từng danh mục.
- [ ] `amount` luôn là số nguyên (`long`) — không dùng `float` cho tiền.
- [ ] Thoát rồi mở lại: các khoản chi còn nguyên (`chi-tieu.dat`).
- [ ] Bonus: chạy với `-fsanitize=address`, ASan im lặng.
