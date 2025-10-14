#!/bin/bash
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
WASM_CC=/opt/wasi-sdk/bin/clang
WAMR_INC=~/wasm-micro-runtime/core/iwasm/include

mkdir -p $SCRIPT_DIR/build


gcc -fPIC --shared -I$WAMR_INC -I$SCRIPT_DIR/../../example_structures -I$SCRIPT_DIR/../../crossplatformpointer -I$SCRIPT_DIR/../../structure_description  -o $SCRIPT_DIR/build/libcrossingboundary.so $SCRIPT_DIR/crossingboundary_native.c

$WASM_CC -I$SCRIPT_DIR/../../example_structures -I$SCRIPT_DIR/../../crossplatformpointer -I$SCRIPT_DIR/../../structure_description  -o $SCRIPT_DIR/build/crossboundary.wasm $SCRIPT_DIR/crossingboundary_wasm.c