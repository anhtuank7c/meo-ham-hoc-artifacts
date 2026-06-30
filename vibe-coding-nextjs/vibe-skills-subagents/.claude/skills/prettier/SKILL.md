---
name: prettier
description: Tự động format code nhất quán bằng Prettier (kèm ESLint cho lint). Dùng khi thiết lập dự án, trước khi commit, hoặc khi code trình bày lộn xộn, lệch kiểu giữa các file.
---

# Format & lint với Prettier

Để code sạch và nhất quán, đỡ tranh cãi kiểu trình bày. Prettier lo định dạng; ESLint lo bắt
lỗi/anti-pattern. Hai thứ bổ trợ nhau.

## Thiết lập

1. Cài Prettier: `npm i -D prettier`. Thêm file `.prettierrc` tối giản:

   ```json
   {
     "semi": true,
     "singleQuote": true,
     "trailingComma": "all",
     "printWidth": 100
   }
   ```

2. Thêm `.prettierignore` (bỏ qua `node_modules`, `.next`, `dist`).
3. Script trong `package.json`:

   ```json
   {
     "scripts": {
       "format": "prettier --write .",
       "format:check": "prettier --check ."
     }
   }
   ```

4. ESLint (Next.js đã kèm `eslint-config-next`); để Prettier lo format, ESLint lo logic.

## Cách áp dụng

- Sau khi viết/sửa code: chạy `npm run format`.
- Trước khi commit: chạy `format:check` để chắc không còn file lệch định dạng.
- Có thể gắn vào pre-commit hook hoặc bước CI để tự kiểm.

## Cờ đỏ cần dừng lại

- Mỗi file một kiểu thụt lề/dấu nháy khác nhau.
- Commit kèm thay đổi định dạng lẫn lộn với thay đổi logic (khó review).
- Chỉnh tay từng dòng cho thẳng hàng thay vì để Prettier lo.
