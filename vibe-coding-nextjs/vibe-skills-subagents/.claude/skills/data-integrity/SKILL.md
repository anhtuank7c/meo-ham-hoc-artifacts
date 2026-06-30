---
name: data-integrity
description: Giữ dữ liệu đúng và nhất quán, nhất là tiền và số dư ví. Dùng khi viết code đụng tới tiền, ví, đơn hàng, tồn kho, hoặc bất kỳ thao tác ghi dữ liệu cần nguyên tử (atomic) và không được sai lệch.
---

# Toàn vẹn dữ liệu (data integrity)

Tiền sai một xu là mất niềm tin. Dữ liệu nửa vời (đơn tạo mà ví chưa trừ) còn tệ hơn lỗi báo
ra. Các nguyên tắc dưới đây giữ dữ liệu luôn đúng.

## Nguyên tắc

1. **Lưu tiền bằng số nguyên.** Dùng đơn vị nhỏ nhất (ví dụ: đồng) kiểu integer/bigint, KHÔNG
   dùng float - vì `0.1 + 0.2 !== 0.3`. Chỉ định dạng ra chuỗi khi hiển thị.
2. **Thao tác nhiều bước phải nguyên tử (transaction).** "Trừ ví" + "tạo đơn" + "ghi giao
   dịch" chạy trong MỘT transaction: hoặc cùng thành công, hoặc rollback hết.
3. **Kiểm điều kiện trong transaction.** Đọc số dư, kiểm đủ tiền, rồi trừ - tất cả trong cùng
   transaction (hoặc dùng update có điều kiện `WHERE balance >= amount`) để tránh race khi hai
   request chạy song song. Số dư không bao giờ âm.
4. **Idempotency.** Đặt đơn / nạp ví nhận một khoá idempotency; bấm hai lần không tạo hai đơn
   hay trừ tiền hai lần.
5. **Ràng buộc ở tầng database.** Đặt constraint (NOT NULL, CHECK `balance >= 0`, unique key)
   để DB là tuyến phòng thủ cuối, không chỉ dựa vào code ứng dụng.
6. **Sổ cái ghi-thêm (append-only).** Lịch sử giao dịch chỉ thêm dòng, không sửa/xoá; số dư
   luôn khớp tổng các giao dịch.

## Cách áp dụng

- Khi thiết kế bảng tiền: integer cho số tiền, transaction cho thao tác, constraint cho ràng buộc.
- Khi viết luồng đặt đơn: bọc trừ ví + tạo đơn + ghi sổ trong một transaction, có idempotency.
- Sau khi xong: nhờ subagent `ra-soat-bao-mat` rà phần tiền/ví (bảo mật và toàn vẹn đi cùng nhau).

## Cờ đỏ cần dừng lại

- Số tiền lưu bằng float/double.
- Trừ ví và tạo đơn ở hai bước tách rời, không transaction.
- Không có constraint `balance >= 0` ở database.
- Không chống được double-submit khi đặt đơn.
