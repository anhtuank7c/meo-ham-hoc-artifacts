#!/bin/sh
# END-TO-END test (black-box): chay CHUONG TRINH that, cap input qua stdin,
# kiem output. Khong biet ruot ben trong — chi kiem "ngoai vao, ngoai ra".
# CTest goi: sh run_cli.sh <duong-dan-todo>
set -eu
TODO="$1"

# FIXTURE: chay trong thu muc tam de todo.dat khong dinh vao nhau giua cac lan
work="$(mktemp -d)"
cd "$work"

out="$(printf 'them hoc bai\nthem di cho\nxong 1\nin\nthoat\n' | "$TODO")"
printf '%s\n' "$out"

echo "$out" | grep -q '\[x\] hoc bai' || { echo 'FAIL: thieu "[x] hoc bai"'; exit 1; }
echo "$out" | grep -q '\[ \] di cho'  || { echo 'FAIL: thieu "[ ] di cho"'; exit 1; }
echo "$out" | grep -q 'con 1 viec chua xong' || { echo 'FAIL: dem sai so viec'; exit 1; }

echo 'e2e OK'
