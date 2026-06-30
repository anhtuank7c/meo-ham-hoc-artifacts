# Capstone · Bình chọn (starter)

**Khung khởi đầu** cho dự án thứ ba ở bài *“Dự án cuối khoá: 3 phần mềm thật”* (khoá **Lập trình C nâng cao**). Bộ khung và phần in kết quả (sắp xếp) đã có sẵn — **việc của bạn là viết nghiệp vụ bỏ phiếu**: tăng phiếu và tìm người dẫn đầu.

## Đã cho sẵn

- `candidate.h` — Model `Candidate {id, name, votes}` + API.
- `candidate.c` — bộ khung mảng động (create/add/remove/count/at) + save/load `binh-chon.dat`. Tái dùng từ Todo, đổi `Task → Candidate`.
- `main.c` — vòng lặp lệnh `them / bau / ketqua / dandau / thoat`; lệnh `ketqua` (sắp xếp giảm dần theo phiếu) đã viết xong.

## Việc của bạn (TODO trong `candidate.c`)

| Cột mốc | Hàm | Yêu cầu |
|---|---|---|
| **2** | `store_vote` | tìm ứng viên theo `id` rồi `votes++`; trả `true`/`false` |
| **4** | `store_leader` | duyệt store, trả con trỏ tới ứng viên có `votes` lớn nhất (tìm max) |

> Mẹo: hai hàm này **nằm trong `candidate.c`** nên duyệt thẳng bằng `s->len` và `s->items[i]`. `store_leader` chính là bài toán **tìm max** kinh điển: giữ một con trỏ `best`, cập nhật khi gặp `votes` lớn hơn.

## Build & chạy

```bash
make
./binh-chon
```

Trước khi cài đặt, `bau` báo “chưa bầu được” và `dandau` báo “chưa có kết quả”. Sau khi xong:

```
> them Lan
  + #1 Lan
> them Minh
  + #2 Minh
> bau 1
  da bau cho #1
> bau 1
  da bau cho #1
> bau 2
  da bau cho #2
> ketqua
  #1   Lan                      2 phieu
  #2   Minh                     1 phieu
> dandau
  Dan dau: Lan (2 phieu)
> thoat
```

## Definition of Done

- [ ] `make` sạch (`-Wall -Wextra`), không cảnh báo.
- [ ] `bau <id>` tăng đúng số phiếu của đúng ứng viên.
- [ ] `dandau` trả về đúng ứng viên nhiều phiếu nhất; `ketqua` in giảm dần.
- [ ] Thoát rồi mở lại: số phiếu còn nguyên (`binh-chon.dat`).
- [ ] Bonus: chạy với `-fsanitize=address`, ASan im lặng.
- [ ] Đưa cả ba dự án (Todo · Chi tiêu · Bình chọn) lên GitHub kèm `README.md` — đó là portfolio C của bạn.
