---
name: wcag-a11y
description: Chuẩn khả năng tiếp cận (accessibility, a11y) theo WCAG cho giao diện web. Dùng khi viết hoặc sửa UI - nút, form, ảnh, màu sắc, điều hướng bàn phím, modal - để ai cũng dùng được, kể cả người dùng trình đọc màn hình.
---

# Khả năng tiếp cận (a11y) theo WCAG

Làm giao diện ai cũng dùng được: người khiếm thị (trình đọc màn hình), người chỉ dùng bàn
phím, người phân biệt màu kém. Theo bốn nguyên tắc WCAG: nhận biết được, thao tác được,
hiểu được, ổn định.

## Checklist cốt lõi

1. **Ảnh có `alt`.** Ảnh truyền tải thông tin phải có `alt` mô tả; ảnh trang trí để `alt=""`.
2. **Tương phản màu đủ.** Chữ thường cần tỉ lệ tương phản >= 4.5:1 so với nền; chữ lớn >= 3:1.
3. **Dùng đúng thẻ ngữ nghĩa.** `<button>` cho hành động, `<a>` cho điều hướng; không dùng
   `<div>` có `onClick` thay nút. Heading theo thứ bậc (`h1` -> `h2` -> `h3`), không nhảy cóc.
4. **Form có nhãn.** Mỗi input gắn `<label>` (hoặc `aria-label`). Báo lỗi rõ ràng, gắn lỗi
   với input qua `aria-describedby`.
5. **Bàn phím dùng được.** Mọi thứ bấm được bằng chuột phải tới được bằng `Tab`; có focus
   ring nhìn thấy; modal bẫy focus và đóng được bằng `Esc`.
6. **Trạng thái động báo cho trình đọc.** Thông báo (toast, lỗi) dùng `aria-live` để trình
   đọc màn hình đọc lên.

## Cách áp dụng

- Khi dựng nút/link: chọn đúng thẻ theo việc (hành động vs điều hướng).
- Khi đặt màu: kiểm tương phản trước khi chốt bảng màu (xem skill `design-system`).
- Khi làm form: gắn label, cho thông báo lỗi cụ thể.
- Sau khi dựng một trang: nhờ subagent `kiem-a11y` rà theo WCAG.

## Cờ đỏ cần dừng lại

- `<div onClick>` hoặc `<span onClick>` đóng vai nút.
- Ảnh nội dung thiếu `alt`; icon-only button thiếu `aria-label`.
- Chữ xám nhạt trên nền sáng (tương phản thấp).
- Modal không đóng được bằng bàn phím; focus đi lạc ra sau nền.
