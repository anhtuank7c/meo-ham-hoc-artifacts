---
name: design-system
description: Khai báo và bám design tokens (primary color, bảng màu, spacing, bo góc) một lần bằng Tailwind v4 @theme, đảm bảo mobile-first. Dùng khi chọn màu thương hiệu, dựng bảng màu, hoặc cần UI nhất quán giữa shop và admin.
---

# Design system: tokens, bảng màu, mobile-first

Một sản phẩm trông chuyên nghiệp khi màu sắc, khoảng cách, bo góc nhất quán khắp nơi. Bí
quyết: khai báo MỘT LẦN thành design tokens, rồi mọi nơi dùng lại.

## Nguyên tắc

1. **Khai báo tokens một chỗ.** Với Tailwind v4, dùng `@theme` trong file CSS gốc:

   ```css
   @theme {
     --color-primary: #7c3aed; /* màu thương hiệu */
     --color-accent: #14b8a6; /* nhấn phụ */
     --color-bg: #0d1117;
     --color-foreground: #e6edf3;
     --radius: 0.75rem;
   }
   ```

   Đổi token là cả sản phẩm đổi theo; AI không lệch màu giữa các trang.

2. **Bảng màu có hệ thống.** Một primary + 2-3 màu phụ + màu nền/chữ + màu trạng thái
   (success/warning/error). Đừng thêm màu lẻ ngoài bảng.
3. **Dùng class theo token** (`bg-primary`, `text-foreground`, `rounded-[--radius]`), không
   `bg-[#...]`.
4. **Mobile-first.** Tokens và layout thiết kế cho điện thoại trước; tương phản đủ ở cả nền
   sáng lẫn tối nếu có dark mode.
5. **Ghi luật vào CLAUDE.md.** Ghi rõ primary color, font, "luôn mobile-first" để mọi phiên
   bám theo, không phải nhắc lại.

## Cách áp dụng

- Bắt đầu dự án: chốt bảng màu, khai báo `@theme`, ghi luật vào CLAUDE.md.
- Khi dựng trang mới: chỉ dùng token có sẵn; cần màu mới thì thêm vào bảng, không hardcode.
- Kiểm tương phản màu để đạt a11y (xem skill `wcag-a11y`).

## Cờ đỏ cần dừng lại

- Mã màu hardcode rải rác trong component.
- Mỗi trang một tông màu/spacing khác nhau.
- Bảng màu không đủ tương phản cho chữ.
