#!/bin/bash
code="$1"
TIMEOUT="${TIMEOUT:-5}"

g++ "${code}.cpp" -o "$code" -std=c++20 -g -DLOCAL -DDeBuG -Wall -Wshadow -fsanitize=address,undefined || exit 1

: > output.txt
: > Error.txt

if [ -f input.txt ]; then
  timeout "${TIMEOUT}s" "./$code" < input.txt > output.txt 2> Error.txt
else
  timeout "${TIMEOUT}s" "./$code" > output.txt 2> Error.txt
fi
rc=$?

if [ $rc -eq 124 ]; then
  echo "Time Limit Exceeded (${TIMEOUT}s)" >> output.txt
fi
