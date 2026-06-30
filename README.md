# meo-ham-hoc-artifacts

Kho **tài nguyên tải về** cho học viên của [Mèo Ham Học](https://meohamhoc.vn) - mã nguồn
bài lab, tài liệu mẫu, bộ skills/subagents. Các bài học trên web liên kết trực tiếp tới
file/thư mục trong kho này; học viên tải về từ GitHub, không cần tài khoản hay công cụ gì thêm.

> Trước đây các file này phục vụ qua Cloudflare R2. Nay chuyển sang kho git công khai để dễ
> xem, dễ tải, và minh bạch nguồn.

## Cấu trúc

Mỗi khoá một thư mục; mỗi bài lab một thư mục con; kèm một file `.zip` dựng sẵn để tải một chạm:

```
<khoá>/
  <lab>/            # mã nguồn bài lab (xem từng file trên GitHub)
  <lab>.zip         # bản nén dựng sẵn, giải nén ra thư mục <lab>/
```

Các khoá hiện có:

- `c-thuc-chien-toolchain/` - 9 lab toolchain C (01-09).
- `lap-trinh-c-co-ban/` - 3 app cuối khoá C cơ bản (basic-*).
- `lap-trinh-c-nang-cao/` - kiểm thử (test-*) + 3 capstone (capstone-*).
- `vibe-coding-nextjs/` - tài liệu BA mẫu + bộ Skills/Subagents (.claude/).

## Dựng lại các file .zip

Các `.zip` được commit sẵn để tải một chạm. Khi sửa nội dung lab, commit nguồn rồi dựng lại zip:

```bash
git add .            # commit nguồn trước
git commit -m "..."
./build-zips.sh      # dựng <khoá>/<lab>.zip từ nội dung đã commit
git add .            # commit lại các zip
git commit -m "Build lab zips"
```

`build-zips.sh` dùng `git archive` nên zip chỉ gồm file đã commit (sạch, không kèm sản phẩm
biên dịch).
