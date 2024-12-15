#!/bin/bash
#Build it... 
/opt/wasi-sdk/bin/clang -O3  -o pointers_to_functions.wasm ./pointers_to_functions.c
clang -O3  -o pointers_to_functions.native ./pointers_to_functions.c
wasm2wat -o pointers_to_functions.wat ./pointers_to_functions.wasm

# Run it.. 
./pointers_to_functions.native
iwasm ./pointers_to_functions.wasm