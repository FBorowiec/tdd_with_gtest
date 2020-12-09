#!/usr/bin/env bash

set -eu
toplevel=${1:-$(git rev-parse --show-toplevel)}

echo "Applying clang-format in $toplevel"
find "${toplevel}" -regex '.*\(\.c\|\.C\|\.cc\|\.cpp\|\.cxx\|\.h\|\.H\|\.hh\|\.hpp\|\.hxx\|\.cl\)$' \
    | xargs -n1 -P$(nproc --all) clang-format -i -style=file -fallback-style=google && echo "Formatting is completed successfully"