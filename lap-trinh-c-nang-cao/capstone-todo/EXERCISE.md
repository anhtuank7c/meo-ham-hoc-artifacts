# Capstone · Todo — quản lý việc cần làm

Bản **mẫu hoàn chỉnh** (reference) cho dự án Todo ở bài *“Dự án cuối khoá: 3 phần mềm thật”* (khoá **Lập trình C nâng cao**). Đây là app dòng lệnh chạy được, minh hoạ kiến trúc **4 lớp** dùng chung cho cả ba dự án.

## Kiến trúc 4 lớp

| Lớp | File | Vai trò |
|---|---|---|
| **Model** | `task.h` (`struct Task`) | một bản ghi: id, title, done |
| **Store** | `store.c` (`TaskStore` opaque) | mảng động: create/add/done/remove/count/at |
| **Storage** | `store.c` (`store_save/load`) | ghi/đọc `todo.dat` — mỗi dòng `id|done|title` |
| **CLI** | `main.c` | vòng lặp lệnh them/xong/xoa/in/thoat |

> 3/4 lớp (Store · Storage · CLI) là **bộ khung dùng chung** — hai dự án kia (Chi tiêu, Bình chọn) chỉ đổi **Model** và **nghiệp vụ**.

## Build & chạy

```bash
make            # hoặc: cc -Wall -Wextra main.c store.c -o todo
./todo
```

Thử:

```
> them hoc bai C
  + #1
> them di cho
  + #2
> xong 1
  da xong #1
> in
  #1   [x] hoc bai C
  #2   [ ] di cho
  -- con 1 viec chua xong --
> thoat
```

Thoát rồi chạy lại `./todo` → danh sách vẫn còn (đã lưu trong `todo.dat`).

## Tự kiểm (Definition of Done)

- [ ] `make` biên dịch sạch với `-Wall -Wextra`, không cảnh báo.
- [ ] Thêm việc → `in` hiển thị đúng, `xong`/`xoa` nhắm đúng id.
- [ ] Thoát rồi mở lại: dữ liệu (kể cả trạng thái đã xong) còn nguyên.
- [ ] Không rò rỉ bộ nhớ: build lại với `-fsanitize=address` rồi chạy, ASan im lặng. (Xem khoá **C Thực Chiến · Toolchain**, bài *Sanitizers*.)

## Bước tiếp

Sao thư mục này thành điểm xuất phát cho **Chi tiêu** và **Bình chọn**: giữ nguyên `store.c`/`main.c` làm khung, đổi `Task` thành Model mới và viết nghiệp vụ riêng. Xem `capstone-chi-tieu/` và `capstone-binh-chon/`.
