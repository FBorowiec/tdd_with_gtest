#!/usr/bin/env bash

set -eu
toplevel=${1:-$(git rev-parse --show-toplevel)}

echo "Applying clang-format in $toplevel"
find "${toplevel}" -type f -iname BUILD -exec buildifier {} + \
  && find "${toplevel}" -type f -iname WORKSPACE -exec buildifier {} + \
  && echo "Formatting is completed successfully"
