# Đồ nghề: Semantic HTML + SEO + JSON-LD

Bộ mang về từ bài [JSON-LD: dữ liệu có cấu trúc](https://meohamhoc.vn/khoa-hoc/html/du-lieu-co-cau-truc-json-ld)
- khoá HTML của Mèo Ham Học. Gồm hai phần:

- **`CHEATSHEET.md`** - bản tra nhanh cho NGƯỜI: landmark semantic, head SEO, và thư viện công
  thức JSON-LD theo loại hình (Product, NewsArticle, Restaurant, JobPosting, Recipe, Event,
  FAQPage, BreadcrumbList, Course). Mở ra đọc hoặc in dán cạnh bàn - không cần công cụ gì.
- **`.claude/skills/semantic-html-seo/`** - skill cho AI (Claude Code): để Claude tự viết HTML
  chuẩn semantic + SEO + JSON-LD khi mèo con dựng trang.

## ⚠️ Thư mục `.claude/` đang BỊ ẨN

Tên bắt đầu bằng dấu chấm nên máy ẩn đi. Cách hiện: macOS bấm `Cmd`+`Shift`+`.`; Windows vào
**View → Hidden items**; hoặc mở cả thư mục bằng VS Code (file ẩn vẫn hiện trong cây thư mục).
`CHEATSHEET.md` thì luôn thấy - cứ mở nó đọc trước.

## Cài skill cho AI (tuỳ chọn)

Phần cheatsheet dùng được ngay, không cần AI. Nếu mèo con dựng trang cùng Claude Code và muốn
Claude tự theo chuẩn này:

1. Copy thư mục **`.claude/`** vào gốc repo dự án (cùng cấp `package.json` hoặc thư mục gốc).
2. Mở Claude Code ở đó. Khi mèo con nhờ dựng/sửa trang, Claude tự nạp skill `semantic-html-seo`.

> Đây là skill HTML thuần (framework-agnostic). Với dự án **Next.js**, dùng Metadata API thay
> cho thẻ head thủ công - xem bộ Skills của khoá
> [Vibe coding với Next.js](https://meohamhoc.vn/khoa-hoc/vibe-coding-nextjs).
