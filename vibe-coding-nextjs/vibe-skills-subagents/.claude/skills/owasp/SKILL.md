---
name: owasp
description: Chuẩn bảo mật web theo OWASP Top 10 cho app Next.js bán hàng. Dùng khi viết hoặc sửa code đụng tới đăng nhập, phiên (session), quyền truy cập, đầu vào người dùng, thanh toán, ví/số dư, upload file, hoặc khi cần rà lỗ hổng bảo mật.
---

# Bảo mật web theo OWASP (Top 10)

Áp các nguyên tắc này mỗi khi đụng tới dữ liệu nhạy cảm (đăng nhập, tiền, quyền admin).
Mục tiêu: đóng các lỗ hổng phổ biến nhất trước khi ship.

## Checklist cốt lõi

1. **Kiểm soát truy cập (Broken Access Control).** Mọi API/route phải kiểm tra: người gọi
   ĐÃ đăng nhập chưa, và có QUYỀN với đúng tài nguyên đó không. Khách chỉ thấy dữ liệu của
   chính mình; chặn truy cập đơn/ví của người khác bằng cách lọc theo `userId` của phiên,
   không tin `userId` gửi từ client.
2. **Kiểm tra đầu vào (Injection).** Dùng truy vấn tham số hoá (parameterized query) hoặc
   ORM; không nối chuỗi vào SQL. Validate mọi input bằng schema (ví dụ Zod) ở phía server,
   kể cả khi client đã validate.
3. **Xác thực & phiên (Authentication failures).** Dùng thư viện auth có tiếng (Better-auth,
   Auth.js), không tự viết hash mật khẩu. Cookie phiên đặt `httpOnly`, `secure`, `sameSite`.
   Có rate-limit cho đăng nhập và quên mật khẩu.
4. **Bí mật & cấu hình (Security Misconfiguration).** Không hardcode secret trong code; để
   trong biến môi trường (`.env`, không commit). Không trả stack trace ra cho người dùng.
5. **Toàn vẹn dữ liệu tiền/ví.** Mọi thay đổi số dư chạy trong transaction; kiểm tra số dư
   đủ TRƯỚC khi trừ; số dư không bao giờ âm. (Xem thêm skill `data-integrity`.)
6. **SSRF / Open redirect.** Không fetch URL do người dùng nhập mà chưa kiểm; không redirect
   tới URL ngoài lấy thẳng từ query.

## Cách áp dụng

- Khi viết một API route mới: bắt đầu bằng kiểm tra phiên + quyền, rồi mới tới logic.
- Khi nhận input: parse bằng schema, từ chối sớm nếu sai.
- Khi đụng tiền: bọc trong transaction, kiểm điều kiện trước khi ghi.
- Sau khi sửa xong phần nhạy cảm: nhờ subagent `ra-soat-bao-mat` rà lại diff.

## Cờ đỏ cần dừng lại

- Một route trả dữ liệu mà không kiểm phiên.
- `userId`/`role` lấy từ body hoặc query thay vì từ phiên server.
- Số tiền lưu bằng float; trừ ví ngoài transaction.
- Secret hoặc API key nằm trong code đẩy lên git.
