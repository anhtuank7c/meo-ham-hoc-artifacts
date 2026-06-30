# Semantic HTML + SEO + JSON-LD - Cheatsheet

Bản tra nhanh đi kèm khoá [HTML: cấu trúc & semantic](https://meohamhoc.vn/khoa-hoc/html) -
Mèo Ham Học. In ra dán cạnh bàn, hoặc mở khi dựng trang. Mọi đoạn JSON-LD dưới đây đều kiểm
được bằng [Rich Results Test](https://search.google.com/test/rich-results).

## 1. Landmark semantic (bộ xương trang)

```html
<header>   <!-- logo + nav đầu trang -->
  <nav> … </nav>
</header>
<main>            <!-- nội dung CHÍNH, mỗi trang đúng MỘT main -->
  <article> … </article>   <!-- một đơn vị nội dung đứng độc lập (bài viết, sản phẩm) -->
  <section> … </section>   <!-- một mảng nội dung có tựa -->
  <aside> … </aside>       <!-- nội dung phụ (liên quan, quảng cáo) -->
</main>
<footer> … </footer>   <!-- chân trang -->
```

- Mỗi trang một `<h1>`; heading đi theo thứ bậc `h1 → h2 → h3`, không nhảy cóc.
- Dùng `<button>` cho hành động, `<a href>` cho điều hướng. Không `<div onclick>`.
- Ảnh nội dung có `alt` mô tả; ảnh trang trí `alt=""`.

## 2. Head cho SEO

```html
<meta charset="utf-8" />
<meta name="viewport" content="width=device-width, initial-scale=1" />
<title>Tối đa ~60 ký tự, đúng nội dung</title>
<meta name="description" content="~100-160 ký tự, hấp dẫn, không nhồi từ khoá" />
<link rel="canonical" href="https://vidu.com/trang" />
<!-- Open Graph: preview khi chia sẻ (ảnh PNG/JPG, KHÔNG WebP) -->
<meta property="og:title" content="…" />
<meta property="og:description" content="…" />
<meta property="og:image" content="https://vidu.com/og.png" />
```

## 3. JSON-LD theo loại hình

Đặt trong `<script type="application/ld+json">…</script>`. Mỗi loại mở một kiểu rich result.

### Product (web bán hàng → sao + giá)

```json
{
  "@context": "https://schema.org",
  "@type": "Product",
  "name": "Bàn cào cho mèo",
  "image": "https://vidu.com/ban-cao.png",
  "offers": {
    "@type": "Offer",
    "price": "250000",
    "priceCurrency": "VND",
    "availability": "https://schema.org/InStock"
  },
  "aggregateRating": { "@type": "AggregateRating", "ratingValue": "4.8", "reviewCount": "256" }
}
```

### NewsArticle / Article (tin tức → Top Stories)

```json
{
  "@context": "https://schema.org",
  "@type": "NewsArticle",
  "headline": "Tựa bài",
  "image": "https://vidu.com/anh.png",
  "datePublished": "2026-06-30T08:00:00+07:00",
  "author": { "@type": "Person", "name": "Tên tác giả" },
  "publisher": {
    "@type": "Organization",
    "name": "Tên toà soạn",
    "logo": { "@type": "ImageObject", "url": "https://vidu.com/logo.png" }
  }
}
```

### LocalBusiness / Restaurant (cửa hàng địa phương → địa chỉ, giờ mở cửa)

```json
{
  "@context": "https://schema.org",
  "@type": "Restaurant",
  "name": "Quán Cá Mèo",
  "servesCuisine": "Hải sản",
  "priceRange": "$$",
  "telephone": "+84-28-1234-5678",
  "address": {
    "@type": "PostalAddress",
    "streetAddress": "12 Đường Cá",
    "addressLocality": "TP.HCM",
    "addressCountry": "VN"
  },
  "openingHours": "Mo-Su 10:00-22:00"
}
```

### JobPosting (tuyển dụng → Google Jobs)

```json
{
  "@context": "https://schema.org",
  "@type": "JobPosting",
  "title": "Lập trình viên Frontend",
  "description": "Mô tả công việc…",
  "datePosted": "2026-06-30",
  "hiringOrganization": { "@type": "Organization", "name": "Mèo Tech" },
  "jobLocation": {
    "@type": "Place",
    "address": { "@type": "PostalAddress", "addressLocality": "TP.HCM", "addressCountry": "VN" }
  }
}
```

### Recipe (công thức → thẻ món ăn có ảnh, thời gian)

```json
{
  "@context": "https://schema.org",
  "@type": "Recipe",
  "name": "Pa-tê cho mèo",
  "image": "https://vidu.com/pate.png",
  "recipeIngredient": ["200g cá", "1 lòng đỏ trứng"],
  "recipeInstructions": "Hấp cá, nghiền nhuyễn, trộn trứng, hấp lại 10 phút.",
  "prepTime": "PT10M",
  "cookTime": "PT20M"
}
```

### Event (sự kiện → ngày giờ, địa điểm)

```json
{
  "@context": "https://schema.org",
  "@type": "Event",
  "name": "Buổi gặp mặt mèo lập trình",
  "startDate": "2026-07-15T19:00:00+07:00",
  "location": {
    "@type": "Place",
    "name": "Nhà văn hoá Mèo",
    "address": "1 Đường Mèo, TP.HCM"
  }
}
```

### FAQPage (trang hỏi đáp → câu hỏi/đáp ngay trên kết quả)

```json
{
  "@context": "https://schema.org",
  "@type": "FAQPage",
  "mainEntity": [
    {
      "@type": "Question",
      "name": "Giao hàng mất bao lâu?",
      "acceptedAnswer": { "@type": "Answer", "text": "Thường 2-3 ngày trong nội thành." }
    }
  ]
}
```

### BreadcrumbList (đường dẫn phân cấp → URL đẹp trên kết quả)

```json
{
  "@context": "https://schema.org",
  "@type": "BreadcrumbList",
  "itemListElement": [
    { "@type": "ListItem", "position": 1, "name": "Trang chủ", "item": "https://vidu.com" },
    { "@type": "ListItem", "position": 2, "name": "Danh mục", "item": "https://vidu.com/danh-muc" },
    { "@type": "ListItem", "position": 3, "name": "Trang hiện tại" }
  ]
}
```

### Course (khoá học - chính meohamhoc.vn dùng)

```json
{
  "@context": "https://schema.org",
  "@type": "Course",
  "name": "Tên khoá",
  "description": "Mô tả khoá.",
  "provider": { "@type": "Organization", "name": "Tên tổ chức", "url": "https://vidu.com" }
}
```

## 4. Kiểm chứng (đừng tin, hãy thử)

- [Rich Results Test](https://search.google.com/test/rich-results) - kiểm trang đủ điều kiện rich result.
- [Schema Markup Validator](https://validator.schema.org) - kiểm cú pháp schema.org tổng quát.

> Quy tắc vàng: dữ liệu JSON-LD phải **khớp nội dung hiện trên trang**. Khai man (sao ảo, giá
> sai) có thể bị Google phạt. JSON-LD đúng là điều kiện cần, không phải lời hứa chắc chắn có
> rich result - Google vẫn tự quyết.
