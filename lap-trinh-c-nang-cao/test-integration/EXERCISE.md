# Kiểm thử tích hợp (integration test) · Store + Storage + CLI

Bài lab cho *Integration test* (khoá **Lập trình C nâng cao**). Khác unit test (kiểm một module cô lập), ở đây ta kiểm **nhiều đơn vị GHÉP nhau ở chỗ tiếp giáp**:

- **Integration** (`tests/test_roundtrip.c`): Store **+** Storage qua một **tệp thật** — lưu rồi đọc lại bằng một store mới (mô phỏng *tắt rồi mở lại app*), khẳng định dữ liệu sống sót.
- **End-to-end** (`tests/run_cli.sh`): chạy **chương trình `todo` thật**, cấp input qua stdin, kiểm output (black-box).

```
test-integration/
├── include/task.h        # Model + Store opaque
├── src/store.c           # Store + Storage (save/load tệp)
├── src/main.c            # CLI
├── tests/test.h          # framework tí hon
├── tests/test_roundtrip.c# INTEGRATION: round-trip qua tệp + fixture
├── tests/run_cli.sh      # E2E: chạy CLI, kiểm output
└── CMakeLists.txt        # 2 test: roundtrip + cli_e2e
```

## Build & chạy

```bash
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
```

→ `100% tests passed ... 2 ... ` (roundtrip + cli_e2e).

## Bài tập (Definition of Done)

- [ ] `ctest` xanh cả hai test.
- [ ] **Bắt lỗi ở chỗ tiếp giáp:** trong `store.c`, đổi `store_save` ghi dấu `,` thay vì `|` (lệch định dạng giữa *lưu* và *đọc*). Chạy lại — `roundtrip` **đỏ sạch**: `THAT BAI: store_count(b) == 2`, `t0 != NULL`… *Đây là loại bug unit test KHÓ bắt: mỗi module riêng vẫn “đúng”, chỉ chỗ ghép mới lệch.* Khôi phục cho xanh.
- [ ] **Fixture:** chỉ ra dòng *setup* (tạo tệp tạm) và *teardown* (`remove`) trong `test_roundtrip.c`. Vì sao test phải tự dọn?
- [ ] **Phòng thủ:** vì sao asserts per-record được bọc trong `if (t0 && t1)`? (Để load hỏng thì báo FAIL sạch, không deref NULL → segfault.)
- [ ] **Thêm e2e:** trong `run_cli.sh`, thêm một kiểm: sau lệnh `xoa`, danh sách không còn việc đó.

## Ghi chú — tháp kiểm thử

Nhiều **unit** (nhanh, một module) · vừa **integration** (vài module + tệp) · ít **e2e** (cả chương trình, chậm). Mỗi tầng bắt một loại lỗi khác nhau; integration & e2e bắt đúng loại lỗi “mỗi mảnh đúng nhưng ráp lại sai”. Gắn cả ba vào CI để chạy tự động — xem khoá **C Thực Chiến · Toolchain**.
