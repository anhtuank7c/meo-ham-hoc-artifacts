---
name: seo
description: Chuẩn SEO kỹ thuật cho web Next.js để Google tìm thấy sản phẩm. Dùng khi tạo trang mới, viết tiêu đề/mô tả (meta), thêm dữ liệu có cấu trúc (structured data), sitemap, hoặc khi cần tối ưu khả năng được tìm thấy.
---

# SEO kỹ thuật cho Next.js

> Skill này thiên về Next.js (Metadata API). Phần nền HTML thuần + thư viện công thức JSON-LD
> theo loại hình (Product, NewsArticle, Restaurant, JobPosting, Recipe, Event, FAQPage…) nằm ở
> skill `semantic-html-seo` (khoá HTML). Hai skill bổ trợ nhau, không lặp lại.

Giúp Google hiểu và hiển thị sản phẩm đúng. Tập trung vào phần kỹ thuật mà code kiểm soát
được; nội dung tốt vẫn là gốc.

## Checklist cốt lõi

1. **Title & meta description mỗi trang.** Dùng Metadata API của Next.js (`generateMetadata`).
   Title <= ~60 ký tự, mô tả ~120-160 ký tự, mỗi trang một bộ riêng, không trùng.
2. **Một `<h1>` mỗi trang**, mô tả đúng nội dung trang; heading theo thứ bậc.
3. **Dữ liệu có cấu trúc (JSON-LD).** Trang sản phẩm gắn schema `Product` (tên, giá, tình
   trạng còn hàng); trang chủ gắn `Organization`/`WebSite`.
4. **Ảnh tối ưu.** Dùng `next/image`; có `alt`; đặt `width`/`height` để tránh nhảy layout (CLS).
5. **URL sạch & canonical.** Đường dẫn ngắn, có nghĩa; đặt thẻ canonical để tránh trùng nội dung.
6. **Open Graph + Twitter card.** Có `og:title`, `og:description`, `og:image` (ảnh PNG/JPG,
   không dùng WebP cho ảnh chia sẻ vì nhiều nền tảng không dựng preview).
7. **Sitemap & robots.** Sinh `sitemap.xml` và `robots.txt`; không chặn nhầm trang cần index.

## Cách áp dụng

- Khi tạo route mới: thêm `generateMetadata` với title + description riêng.
- Khi làm trang sản phẩm: thêm JSON-LD `Product` và OG image.
- Sau khi xong một nhóm trang: nhờ subagent `toi-uu-seo` rà.

## Cờ đỏ cần dừng lại

- Nhiều trang dùng chung một title/description mặc định.
- Trang sản phẩm không có structured data.
- Ảnh chia sẻ (OG) để định dạng WebP.
- `robots.txt` chặn nhầm cả site.
