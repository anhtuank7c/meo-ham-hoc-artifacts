# Lab 03 — Make & đồ thị build

**Mục tiêu:** viết một `Makefile` thật, thấy tận mắt **build tăng dần** (chỉ dịch lại phần phụ thuộc), và để trình biên dịch tự sinh phụ thuộc header.

Bài học liên quan: [Make & đồ thị build](https://emyeukhoahoc.anhtuank7c.dev/khoa-hoc/c-thuc-chien-toolchain/make-build-graph)

File: `main.c`, `util.c`, `util.h`, và `Makefile` (đã viết sẵn, dùng `-MMD -MP` để tự sinh phụ thuộc).

---

## Phần 1 — Build & build lại

```bash
make            # build lan dau: dich main.o, util.o, roi app
./app
make            # lan hai: "app is up to date" — KHONG dich lai gi
```

> Mở `Makefile` bằng editor và kiểm tra: dòng recipe phải bắt đầu bằng một ký tự **TAB**. Thử đổi một TAB thành dấu cách rồi `make` → bạn sẽ thấy lỗi `missing separator` kinh điển.

## Phần 2 — Build tăng dần (incremental)

```bash
touch util.h    # gia lap "sua header"
make            # -> main.o VA util.o deu build lai (ca hai #include util.h), roi app

touch util.c    # gia lap "sua util.c"
make            # -> chi util.o roi app build lai; main.o duoc bo qua
```

**Quan sát:** sửa header lan rộng tới mọi file include nó; sửa một `.c` chỉ ảnh hưởng `.o` của nó. Đó là sức mạnh của đồ thị phụ thuộc.

> **Lưu ý macOS:** `make` bản cũ (GNU Make 3.81 đi kèm macOS) so sánh thời gian theo **giây**. Nếu bạn `touch` rồi `make` trong *cùng một giây*, nó có thể tưởng file chưa đổi. Chờ một nhịp giữa các lệnh, hoặc cài make mới: `brew install make` rồi dùng `gmake`. Trên Linux thì không gặp.

## Phần 3 — Tự sinh phụ thuộc header

`Makefile` ở đây dùng `CFLAGS += -MMD -MP`. Sau khi `make`:

```bash
ls *.d              # main.d, util.d do trinh bien dich sinh ra
cat util.d          # liet ke header ma util.c phu thuoc
```

Dòng `-include $(OBJ:.o=.d)` nạp các phụ thuộc này, nên bạn **không phải tự khai báo** `util.h` trong mỗi luật — sửa header sẽ luôn build lại đúng. Thử xoá `-MMD -MP` và bỏ `-include`, rồi `touch util.h; make` — lần này header KHÔNG kích hoạt build lại (vì luật `%.o: %.c` không nhắc tới header). Đó là cái bẫy "thiếu phụ thuộc header".

## Phần 4 — Dọn dẹp

```bash
make clean      # xoa *.o, app, *.d
make all        # target phony 'all' -> build lai tu dau
```

---

✅ **Xong khi bạn:** viết/đọc được một luật Make, giải thích vì sao `make` chỉ build lại phần cần, thấy `-MMD -MP` tự bắt phụ thuộc header, và biết bẫy TAB-vs-space.
