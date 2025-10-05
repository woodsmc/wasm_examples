#!/bin/bash
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
COMPILER=/opt/wasi-sdk/wasi-sdk-21.0/bin/clang
mkdir -p $SCRIPT_DIR/bin
$COMPILER -I$SCRIPT_DIR/../example_structures -I$SCRIPT_DIR/../crossplatformpointer -I$SCRIPT_DIR/../structure_description  -o $SCRIPT_DIR/bin/structure.wasm $SCRIPT_DIR/structure.c $SCRIPT_DIR/../structure_description/field_offset_calc.c
$COMPILER -I$SCRIPT_DIR/../example_structures -I$SCRIPT_DIR/../crossplatformpointer -I$SCRIPT_DIR/../structure_description  -o $SCRIPT_DIR/bin/pointer.wasm $SCRIPT_DIR/pointer.c 
