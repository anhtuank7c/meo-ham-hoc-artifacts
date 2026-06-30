---
name: semantic-html-seo
description: Viết và rà HTML chuẩn semantic, hỗ trợ accessibility, kèm SEO (title/meta/Open Graph) và structured data JSON-LD theo schema.org. Framework-agnostic (HTML thuần, không phụ thuộc Next.js). Dùng khi tạo/sửa trang web, trang sản phẩm/bài viết/cửa hàng, hoặc khi cần trang được Google hiểu rõ và hiện rich result.
---

# Semantic HTML + SEO + JSON-LD

Mục tiêu: trang dùng đúng thẻ semantic (máy và người đều hiểu), có meta SEO đầy đủ, và khai báo
structured data (JSON-LD) cho đúng loại nội dung để mở rich result. Đây là skill HTML THUẦN
(framework-agnostic). Với dự án Next.js, dùng Metadata API thay cho thẻ head thủ công - xem
skill `seo` (bộ vibe-coding-nextjs).

## Nguyên tắc semantic

1. **Landmark đúng:** `header > nav`, `main` (đúng một), `article` (đơn vị độc lập), `section`
   (mảng có tựa), `aside` (phụ), `footer`. Không thay bằng `div` chung chung.
2. **Heading có thứ bậc:** mỗi trang một `<h1>`; `h2`/`h3` đi xuống dần, không nhảy cóc.
3. **Đúng thẻ theo việc:** `<button>` cho hành động, `<a href>` cho điều hướng; không `<div onclick>`.
4. **Ảnh có `alt`:** ảnh nội dung mô tả rõ; ảnh trang trí để `alt=""`. Form có `<label for>`.

## Meta SEO (trong head)

- `<title>` (≤ ~60 ký tự) và `<meta name="description">` (~100-160 ký tự), riêng cho mỗi trang.
- `<meta charset="utf-8">` + `<meta name="viewport" content="width=device-width, initial-scale=1">`.
- `<link rel="canonical">` để tránh trùng nội dung.
- Open Graph (`og:title`/`og:description`/`og:image`) cho preview khi chia sẻ; ảnh OG dùng
  **PNG/JPG**, không WebP (nhiều mạng xã hội không dựng preview từ WebP).

## JSON-LD (structured data)

Đặt trong `<script type="application/ld+json">`. Luôn có `@context: "https://schema.org"` và
`@type`. Chọn `@type` theo loại trang:

| Loại trang             | @type            | Rich result mở khoá                  |
| ---------------------- | ---------------- | ------------------------------------ |
| Sản phẩm / web bán hàng | `Product`        | sao đánh giá, giá, tình trạng còn hàng |
| Tin tức / bài viết     | `NewsArticle`/`Article` | Top Stories, thẻ bài viết       |
| Cửa hàng / nhà hàng    | `LocalBusiness`/`Restaurant` | địa chỉ, giờ mở cửa        |
| Tuyển dụng             | `JobPosting`     | Google Jobs                          |
| Công thức nấu ăn       | `Recipe`         | thẻ món ăn (ảnh, thời gian)          |
| Sự kiện                | `Event`          | ngày giờ, địa điểm                   |
| Trang hỏi đáp          | `FAQPage`        | câu hỏi/đáp ngay trên kết quả        |
| Đường dẫn phân cấp     | `BreadcrumbList` | URL đẹp dạng Trang chủ › Danh mục    |
| Khoá học               | `Course`         | thẻ khoá học                         |

Mẫu Product (đủ giá + sao):

```html
<script type="application/ld+json">
{
  "@context": "https://schema.org",
  "@type": "Product",
  "name": "Tên sản phẩm",
  "offers": { "@type": "Offer", "price": "250000", "priceCurrency": "VND", "availability": "https://schema.org/InStock" },
  "aggregateRating": { "@type": "AggregateRating", "ratingValue": "4.8", "reviewCount": "256" }
}
</script>
```

Các mẫu đầy đủ khác (NewsArticle, Restaurant, JobPosting, Recipe, Event, FAQPage,
BreadcrumbList, Course): xem CHEATSHEET.md đi kèm.

## Cách áp dụng

- Khi dựng trang mới: chọn landmark đúng → thêm meta head → thêm JSON-LD đúng `@type`.
- Dữ liệu JSON-LD phải **khớp nội dung hiện trên trang** (giá, sao, ngày phải là thật).
- Sau khi xong: kiểm bằng [Rich Results Test](https://search.google.com/test/rich-results) và
  [Schema Markup Validator](https://validator.schema.org), sửa tới khi hết lỗi.

## Cờ đỏ cần dừng lại

- `div` thay cho landmark; `<div onclick>` đóng vai nút; ảnh nội dung thiếu `alt`.
- Nhiều trang dùng chung một `<title>`/description mặc định.
- JSON-LD sai cú pháp (một dấu phẩy hỏng cả khối) hoặc dữ liệu không khớp nội dung trang.
- Khai man sao/giá để câu rich result - có thể bị Google phạt.
