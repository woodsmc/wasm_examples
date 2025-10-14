#!/bin/bash
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

mkdir -p $SCRIPT_DIR/bin
gcc -I$SCRIPT_DIR/../example_structures -I$SCRIPT_DIR/../crossplatformpointer -I$SCRIPT_DIR/../structure_description  -o $SCRIPT_DIR/bin/structure $SCRIPT_DIR/structure.c $SCRIPT_DIR/../structure_description/field_offset_calc.c
gcc -I$SCRIPT_DIR/../example_structures -I$SCRIPT_DIR/../crossplatformpointer -I$SCRIPT_DIR/../structure_description  -o $SCRIPT_DIR/bin/pointer $SCRIPT_DIR/pointer.c 
