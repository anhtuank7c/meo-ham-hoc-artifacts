---
name: shadcn-tailwind
description: Dựng giao diện React/Next.js theo bộ quy ước shadcn/ui + Tailwind CSS, nhất quán và mobile-first. Dùng khi tạo hoặc sửa component UI, layout, form, trang sản phẩm/giỏ hàng/admin - để các màn hình trông như một sản phẩm.
---

# Dựng UI với shadcn/ui + Tailwind CSS

Mục tiêu: UI nhất quán giữa các trang (shop và admin trông cùng một sản phẩm), bám design
tokens, ưu tiên màn hình điện thoại.

## Nguyên tắc

1. **Component từ shadcn/ui làm nền.** Cài qua CLI (`npx shadcn@latest add <component>`), rồi
   tuỳ biến. Không tự dựng lại button/dialog/input từ đầu khi đã có sẵn.
2. **Bám design tokens, không hardcode mã màu.** Dùng class theo token (`bg-primary`,
   `text-foreground`) thay vì `bg-[#7c3aed]` rải rác. (Xem skill `design-system`.)
3. **Mobile-first.** Viết style cho điện thoại trước, rồi thêm breakpoint `sm:`/`md:`/`lg:`
   để mở rộng lên màn lớn. Kiểm tra không vỡ ở khung hẹp.
4. **Tái dùng layout.** Dùng chung shell (header, container, spacing) cho cả shop lẫn admin
   để cảm giác đồng nhất.
5. **Khoảng cách & kích thước theo thang.** Dùng thang spacing của Tailwind (`p-4`, `gap-2`),
   không đặt số lẻ tuỳ tiện.
6. **Trạng thái đầy đủ.** Mỗi khối dữ liệu có trạng thái loading, rỗng (empty), và lỗi -
   không chỉ làm happy path.

## Cách áp dụng

- Tạo UI mới: tìm component shadcn phù hợp trước, rồi ghép lại; style bằng token.
- Form: dùng input/label/button của shadcn, gắn validation và thông báo lỗi rõ.
- Sau khi dựng: nhờ subagent `ra-soat-giao-dien` kiểm responsive + nhất quán.

## Cờ đỏ cần dừng lại

- Hardcode mã màu (`#...`) thay vì dùng token.
- Mỗi trang một kiểu spacing/typography khác nhau.
- UI vỡ ở màn hình điện thoại; chỉ test trên desktop.
- Thiếu trạng thái loading/empty/error.
