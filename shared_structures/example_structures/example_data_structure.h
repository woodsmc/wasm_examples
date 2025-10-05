#pragma once
#include <stdint.h>

typedef union TPointerUnion
{
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