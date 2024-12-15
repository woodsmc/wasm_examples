#!/bin/bash
/opt/wasi-sdk/bin/clang -nostdlib -Wl,--no-entry -o add.wasm ./add.c
wasm2wat -o add.wat ./add.wasm


