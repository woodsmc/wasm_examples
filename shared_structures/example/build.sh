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

mkdir -p $SCRIPT_DIR/bin
gcc -I$SCRIPT_DIR/../example_structures -I$SCRIPT_DIR/../crossplatformpointer -I$SCRIPT_DIR/../structure_description  -o $SCRIPT_DIR/bin/structure $SCRIPT_DIR/structure.c $SCRIPT_DIR/../structure_description/field_offset_calc.c
gcc -I$SCRIPT_DIR/../example_structures -I$SCRIPT_DIR/../crossplatformpointer -I$SCRIPT_DIR/../structure_description  -o $SCRIPT_DIR/bin/pointer $SCRIPT_DIR/pointer.c 
