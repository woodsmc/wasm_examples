#!/bin/bash

#   Copyright 2025 Chris Woods - https://withbighair.com
#
#   Licensed under the Apache License, Version 2.0 (the "License");
#   you may not use this file except in compliance with the License.
#   You may obtain a copy of the License at
#
#       http://www.apache.org/licenses/LICENSE-2.0
#
#   Unless required by applicable law or agreed to in writing, software
#   distributed under the License is distributed on an "AS IS" BASIS,
#   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#   See the License for the specific language governing permissions and
#   limitations under the License.


SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
WASM_CC=/opt/wasi-sdk/bin/clang
WAMR_INC=~/wasm-micro-runtime/core/iwasm/include


# Check WASM_CC
if [ -x "$WASM_CC" ]; then
    echo -e "${GREEN}WASM_CC found: $WASM_CC${NC}"
else
    echo -e "${RED}Warning: WASM_CC not found at $WASM_CC${NC}"
fi

# Expand tilde for WAMR_INC
WAMR_INC_EXPANDED=$(eval echo $WAMR_INC)
if [ -d "$WAMR_INC_EXPANDED" ]; then
    echo -e "${GREEN}WAMR_INC found: $WAMR_INC_EXPANDED${NC}"
else
    echo -e "${RED}Warning: WAMR_INC not found at $WAMR_INC_EXPANDED${NC}"
fi

echo "building now"

mkdir -p $SCRIPT_DIR/build


gcc -fPIC --shared -I$WAMR_INC -I$SCRIPT_DIR/../../example_structures -I$SCRIPT_DIR/../../crossplatformpointer -I$SCRIPT_DIR/../../structure_description  -o $SCRIPT_DIR/build/libcrossingboundary.so $SCRIPT_DIR/crossingboundary_native.c

$WASM_CC -I$SCRIPT_DIR/../../example_structures -I$SCRIPT_DIR/../../crossplatformpointer -I$SCRIPT_DIR/../../structure_description  -o $SCRIPT_DIR/build/crossboundary.wasm $SCRIPT_DIR/crossingboundary_wasm.c