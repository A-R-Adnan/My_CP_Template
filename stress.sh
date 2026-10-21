#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")"
# Files: template.cpp (main), brute.cpp, gen.cpp
MAIN=template.cpp
BRUTE=brute.cpp
GEN=gen.cpp
# Compile
printf '[*] Compiling...\n'
g++ -std=c++17 -O2 -Wall "$MAIN" -o main || exit 1
g++ -std=c++17 -O2 -Wall "$BRUTE" -o brute || exit 1
g++ -std=c++17 -O2 -Wall "$GEN" -o gen || exit 1
printf '[*] Running stress loop (Ctrl+C to stop)\n'
ITER=0
while true; do
  ITER=$((ITER+1))
  ./gen > input.txt
  ./main < input.txt > out_main.txt 2> /dev/null || { echo "Runtime error main"; exit 1; }
  ./brute < input.txt > out_brute.txt 2> /dev/null || { echo "Runtime error brute"; exit 1; }
  if diff -q out_main.txt out_brute.txt > /dev/null; then
     echo "OK #$ITER";
  else
     echo 'Mismatch found!';
     diff -u out_brute.txt out_main.txt | sed -n '1,100p'
     echo 'Failing input:'
     cat input.txt
     exit 0
  fi
  if (( ITER >= 200 )); then
     echo "Completed $ITER iterations without mismatch."; exit 0; fi
done
