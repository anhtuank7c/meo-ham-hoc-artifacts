# Lab 04 — CMake & Meson

**Mục tiêu:** chuyển một dự án nhiều file sang **CMake**, build **out-of-source**, thử generator **Ninja**, và thấy tận mắt `PUBLIC` vs `PRIVATE` include propagation.

Bài học liên quan: [CMake & Meson](https://emyeukhoahoc.anhtuank7c.dev/khoa-hoc/c-thuc-chien-toolchain/cmake-meson)

Cấu trúc: `include/util.h` (header PUBLIC), `src/util.c`, `src/main.c`, `CMakeLists.txt`, `meson.build`.

Cần: `cmake` (≥ 3.16). Tuỳ chọn: `ninja`, `meson` (`pip install meson ninja` hoặc `brew install meson ninja`).

---

## Phần 1 — Cấu hình & build (hai pha)

```bash
cmake -S . -B build      # PHA 1: doc CMakeLists, sinh build files vao build/
cmake --build build      # PHA 2: bien dich (goi Make ben duoi)
./build/app              # -> binh_phuong(9) = 81
```

**Quan sát:** cây nguồn vẫn sạch; mọi thứ nằm trong `build/`. Xoá `build/` rồi cấu hình lại — tái tạo hoàn toàn.

## Phần 2 — Đổi generator (Ninja)

```bash
cmake -S . -B build-ninja -G Ninja
cmake --build build-ninja
./build-ninja/app
```

Cùng một `CMakeLists.txt`, generator khác. Đó là điểm mạnh của CMake.

## Phần 3 — PUBLIC vs PRIVATE include

`CMakeLists.txt` đặt `target_include_directories(util PUBLIC include)`. Vì PUBLIC nên **app (link util) tự thấy `include/`** — đó là lý do `src/main.c` include được `util.h`.

Thử đổi `PUBLIC` thành `PRIVATE`:

```bash
# sua CMakeLists.txt: PUBLIC include -> PRIVATE include
cmake -S . -B build
cmake --build build      # -> LOI: main.c khong tim thay 'util.h'
```

Vì sao? PRIVATE nghĩa là chỉ `util` thấy `include/`, app không thừa hưởng → không include được header. Đổi lại PUBLIC để sửa. (Đây chính là điều công cụ ở Bước 4 minh hoạ.)

## Phần 4 (tuỳ chọn) — Meson

```bash
meson setup build-meson
meson compile -C build-meson    # hoac: ninja -C build-meson
./build-meson/app
```

So sánh cú pháp `meson.build` với `CMakeLists.txt` — gọn hơn, nhưng ý tưởng (target, thư viện, include) tương tự.

---

✅ **Xong khi bạn:** viết được CMakeLists.txt, build out-of-source, đổi generator, và giải thích vì sao đổi PUBLIC→PRIVATE làm app không build được.
