/*
   Copyright 2025 Chris Woods - https://withbighair.com

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#pragma once
#include <stdint.h>

typedef union TPointerUnion {
    void* pointer;
    uint64_t asUint64;
}TPointerUnion;

typedef struct TAllDataTypes{
    uint8_t eight;
    uint16_t sixteen;
    uint32_t thirtytwo;
    uint8_t eightAgain;
    void* pointer;
} TAllDataTypes;

typedef struct TAllDataTypesWithUnion{
    uint8_t eight;
    uint16_t sixteen;
    uint32_t thirtytwo;
    uint8_t eightAgain;
    TPointerUnion pointer;
} TAllDataTypesWithUnion;

typedef struct example_data_structure_padded_pointer
{
    uint8_t eight;
    uint16_t sixteen;
    uint32_t thirtytwo;
    uint8_t eightAgain;
    TPointerUnion pointer;
    uint8_t byteArray[3];
}example_data_structure_padded_pointer;


typedef struct TBasicDataTypes {
    uint8_t eight;
    uint16_t sixteen;
    uint32_t thirtytwo;
    uint64_t sixtyfour;
} TBasicDataTypes;

typedef struct T8and64BitataTypes {
    uint8_t eight;
    uint64_t sixtyfour;
} T8and64BitataTypes;

typedef struct TOnly8bitataType {
    uint8_t eight;
} TOnly8bitataType;

typedef struct T8and32BitataTypes {
    uint8_t eight;
    uint32_t thirtytwo;
} T8and32BitataTypes;