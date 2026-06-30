# Bộ Skills & Subagents của Mèo

Đây là "đồ nghề" cho Claude Code: 7 **skills** (OWASP, WCAG/a11y, SEO, shadcn-react + Tailwind,
design-system, Prettier, data-integrity) và 4 **subagents** (rà bảo mật, kiểm a11y, rà giao diện,
tối ưu SEO). Khoá [Vibe coding với Next.js](https://meohamhoc.vn/khoa-hoc/vibe-coding-nextjs) -
Mèo Ham Học.

## ⚠️ Đồ nghề nằm trong thư mục `.claude/` (đang BỊ ẨN)

Tên thư mục bắt đầu bằng dấu chấm nên máy tính **ẩn nó đi** - vì vậy sau khi giải nén, thư mục
này trông như rỗng. Đừng lo, `.claude/` vẫn ở ngay cạnh file README này. Cách thấy nó:

- **macOS (Finder):** bấm `Cmd` + `Shift` + `.` để bật/tắt hiện file ẩn.
- **Windows (File Explorer):** thẻ **View** → tích **Hidden items**.
- **VS Code / trình soạn thảo:** mở cả thư mục, file ẩn vẫn hiện trong cây thư mục.

## Cài vào dự án của mèo con

1. Copy nguyên thư mục **`.claude/`** vào **gốc repo dự án** (cùng cấp với `package.json`).
2. Commit để nó đi cùng dự án: `git add .claude/ && git commit -m "Them bo Skills va Subagents"`.
3. Mở phiên Claude Code mới - nó tự nhận các skill/subagent. Hỏi thử "dự án có những subagent nào?"

**Cách dễ nhất (để Claude làm giúp):** đặt cả thư mục vừa giải nén vào gốc repo, mở Claude Code ở đó
rồi gõ: *"Trong thư mục này có `.claude/` (có thể đang ẩn). Hãy chuyển `.claude/` ra gốc repo cùng cấp
`package.json`, rồi liệt kê các skill và subagent có trong đó."*

## Có gì bên trong `.claude/`

```
.claude/
  skills/
    owasp/SKILL.md            # bảo mật web theo OWASP Top 10
    wcag-a11y/SKILL.md        # khả năng tiếp cận theo WCAG
    seo/SKILL.md              # SEO kỹ thuật cho Next.js
    shadcn-tailwind/SKILL.md  # dựng UI nhất quán, mobile-first
    design-system/SKILL.md    # design tokens, bảng màu
    prettier/SKILL.md         # format/lint code
    data-integrity/SKILL.md   # toàn vẹn dữ liệu (tiền, số dư ví)
  agents/
    ra-soat-bao-mat.md        # subagent rà bảo mật (OWASP)
    kiem-a11y.md              # subagent kiểm a11y (WCAG)
    ra-soat-giao-dien.md      # subagent rà giao diện (responsive, nhất quán)
    toi-uu-seo.md             # subagent rà SEO
```
