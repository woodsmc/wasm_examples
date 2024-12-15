#!/bin/bash
/opt/wasi-sdk/bin/clang -O3 -nostdlib -Wl,--no-entry -mreference-types -o extern_ref_example.wasm ./extern_ref_example.c
wasm2wat -o extern_ref_example.wat ./extern_ref_example.wasm


