#!/usr/bin/env bash
# Dựng một file <khoá>/<lab>.zip cho mỗi bài lab - CHỈ gồm file đã commit (sạch, không kèm
# sản phẩm biên dịch). Mỗi zip giải nén ra một thư mục <lab>/ (wrapper) cho gọn.
#
# Chạy SAU khi đã commit nguồn:
#   ./build-zips.sh && git add . && git commit -m "Build lab zips"
set -euo pipefail
shopt -s nullglob
cd "$(git rev-parse --show-toplevel)"

count=0
for course in */; do
  course="${course%/}"
  [ "$course" = ".git" ] && continue
  for labdir in "$course"/*/; do
    lab="$(basename "$labdir")"
    git archive --format=zip --prefix="$lab/" -o "$course/$lab.zip" "HEAD:$course/$lab"
    echo "  $course/$lab.zip"
    count=$((count + 1))
  done
done
echo "Xong - dựng $count file .zip."
