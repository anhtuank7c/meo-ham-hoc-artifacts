# Web bán hàng có ví - Tài liệu BA

> Tài liệu BA (business analysis) mẫu cho khoá **Vibe coding với Next.js** - Mèo Ham Học.
> Đây là điểm tựa để mèo con mô tả sản phẩm cho Claude trước khi viết code. Hãy đổi mọi
> nội dung trong này theo dự án của mèo con; giữ nguyên cấu trúc sáu mục để dễ làm việc với AI.

---

## 1. Bối cảnh & mục tiêu

**Bối cảnh.** Một shop nhỏ bán hàng online (ví dụ: đồ handmade, khoá học, vật phẩm số).
Hiện chủ shop chốt đơn thủ công qua tin nhắn, dễ sót đơn và khó theo dõi doanh thu.

**Mục tiêu sản phẩm.** Dựng một website bán hàng có **ví nội bộ** (wallet): khách nạp tiền
vào ví trước, rồi dùng số dư trong ví để mua hàng. Cách này giảm phụ thuộc cổng thanh toán
ở mỗi đơn và cho trải nghiệm mua nhanh "một chạm".

**Tiêu chí thành công (đo được).**

- Khách tự đặt được đơn và thanh toán bằng ví, không cần chủ shop can thiệp.
- Mỗi giao dịch ví ghi lại đầy đủ, số dư luôn khớp với lịch sử (không bao giờ âm).
- Admin xem được đơn hàng và biến động ví theo thời gian.

---

## 2. Người dùng & vai trò

| Vai trò    | Là ai                          | Cần làm gì                                                        |
| ---------- | ------------------------------ | ---------------------------------------------------------------- |
| **Khách**  | Người mua hàng, có tài khoản   | Xem sản phẩm, nạp ví, đặt đơn, xem lịch sử đơn và số dư ví        |
| **Admin**  | Chủ shop / người quản lý       | Quản lý sản phẩm, duyệt nạp ví, xem đơn hàng và báo cáo doanh thu |
| **Khách vãng lai** | Người chưa đăng nhập   | Xem sản phẩm; muốn mua thì phải đăng ký/đăng nhập                 |

**Phân quyền cốt lõi:** khách chỉ thấy dữ liệu của chính mình; admin thấy toàn hệ thống.
Một khách KHÔNG được xem đơn hay ví của khách khác.

---

## 3. User stories

Viết theo mẫu: *Là <vai trò>, tôi muốn <việc> để <lợi ích>.*

**Tài khoản & ví**

- Là khách, tôi muốn đăng ký và đăng nhập an toàn để có tài khoản riêng.
- Là khách, tôi muốn nạp tiền vào ví để mua hàng nhanh mà không nhập thẻ mỗi lần.
- Là khách, tôi muốn xem số dư ví và lịch sử giao dịch để biết tiền đi đâu.

**Mua hàng**

- Là khách, tôi muốn xem danh sách sản phẩm và chi tiết từng sản phẩm để chọn món cần mua.
- Là khách, tôi muốn thêm sản phẩm vào giỏ và đặt đơn, thanh toán bằng số dư ví.
- Là khách, tôi muốn xem lại các đơn đã đặt và trạng thái của chúng.

**Quản trị**

- Là admin, tôi muốn thêm/sửa/ẩn sản phẩm để cập nhật gian hàng.
- Là admin, tôi muốn duyệt yêu cầu nạp ví để cộng tiền cho khách sau khi nhận được tiền.
- Là admin, tôi muốn xem danh sách đơn và tổng doanh thu theo ngày để theo dõi kinh doanh.

---

## 4. Phạm vi MVP (làm trước)

Bản đầu tiên chỉ cần đủ để một khách mua được hàng bằng ví:

1. Đăng ký / đăng nhập / quên mật khẩu.
2. Danh sách sản phẩm + trang chi tiết sản phẩm.
3. Ví: xem số dư, gửi yêu cầu nạp tiền, xem lịch sử giao dịch.
4. Giỏ hàng + đặt đơn, trừ tiền từ ví khi đặt thành công.
5. Trang "Đơn của tôi" cho khách.
6. Trang admin tối giản: duyệt nạp ví, xem đơn.

**Ràng buộc tiền & ví (quan trọng - đừng bỏ qua):**

- Lưu tiền bằng **số nguyên đơn vị nhỏ nhất** (ví dụ: đồng), KHÔNG dùng số thực (float).
- Trừ ví và tạo đơn phải **nguyên tử** (atomic): hoặc cùng thành công, hoặc cùng thất bại.
- Không cho đặt đơn nếu số dư không đủ; số dư ví **không bao giờ âm**.
- Chống bấm hai lần (double-submit) khi đặt đơn bằng khoá idempotency.

---

## 5. Definition of done (tiêu chí "xong")

Một tính năng được coi là xong khi:

- Chạy được ở localhost theo đúng user story tương ứng (happy path).
- Có xử lý lỗi rõ ràng: số dư không đủ, sản phẩm hết hàng, phiên đăng nhập hết hạn.
- Khách A không truy cập được dữ liệu của khách B (kiểm thử phân quyền).
- Số dư ví sau giao dịch = số dư trước +/- đúng số tiền, và khớp lịch sử giao dịch.
- Giao diện dùng được trên màn hình điện thoại (mobile-first), không vỡ layout.
- Đã cho subagent bảo mật rà qua phần thanh toán/ví trước khi coi là hoàn tất.

---

## 6. Ngoài phạm vi (để sau)

Những thứ KHÔNG làm ở MVP để tránh phình to:

- Tích hợp cổng thanh toán tự động cho việc nạp ví (MVP duyệt tay).
- Mã giảm giá, khuyến mãi, tích điểm.
- Vận chuyển, theo dõi đơn hàng qua đơn vị giao hàng.
- Đánh giá sản phẩm, bình luận.
- Đa ngôn ngữ, đa tiền tệ.
- Ứng dụng di động riêng (web responsive là đủ cho MVP).

---

*Ghi chú cho mèo con: chỗ nào trong dự án của bạn còn chưa rõ thì ghi `<cần bổ sung>`*
*thay vì tự bịa. Một spec trung thực, có chỗ trống rõ ràng, vẫn tốt hơn một spec đầy nhưng sai.*
