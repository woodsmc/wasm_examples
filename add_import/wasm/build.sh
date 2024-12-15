#!/bin/bash
/opt/wasi-sdk/bin/clang -O3 -nostdlib -Wl,--no-entry -o add.wasm ./add.c
wasm2wat -o add.wat ./add.wasm


