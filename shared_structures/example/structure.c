#include <stdio.h>
#include "field_offset_calc.h"
#include "example_data_structure.h"

START_DESCRIBE_STRUCT(TFieldDescriptor)
    DESCRIBE_FIELD(TFieldDescriptor, name),
    DESCRIBE_FIELD(TFieldDescriptor, offset),
    DESCRIBE_FIELD(TFieldDescriptor, size)
END_DESCRIBE_STRUCT;

START_DESCRIBE_STRUCT(TAllDataTypes)
    DESCRIBE_FIELD(TAllDataTypes, eight),
    DESCRIBE_FIELD(TAllDataTypes, sixteen),
    DESCRIBE_FIELD(TAllDataTypes, thirtytwo),
    DESCRIBE_FIELD(TAllDataTypes, eightAgain),
    DESCRIBE_FIELD(TAllDataTypes, pointer)
END_DESCRIBE_STRUCT;

START_DESCRIBE_STRUCT(TAllDataTypesWithUnion)
    DESCRIBE_FIELD(TAllDataTypesWithUnion, eight),
    DESCRIBE_FIELD(TAllDataTypesWithUnion, sixteen),
    DESCRIBE_FIELD(TAllDataTypesWithUnion, thirtytwo),
    DESCRIBE_FIELD(TAllDataTypesWithUnion, eightAgain),
    DESCRIBE_FIELD(TAllDataTypesWithUnion, pointer)
END_DESCRIBE_STRUCT;

START_DESCRIBE_STRUCT(example_data_structure_padded_pointer)
    DESCRIBE_FIELD(example_data_structure_padded_pointer, eight),
    DESCRIBE_FIELD(example_data_structure_padded_pointer, sixteen),
    DESCRIBE_FIELD(example_data_structure_padded_pointer, thirtytwo),
    DESCRIBE_FIELD(example_data_structure_padded_pointer, eightAgain),
    DESCRIBE_FIELD(example_data_structure_padded_pointer, pointer),
    DESCRIBE_FIELD(example_data_structure_padded_pointer, byteArray)
END_DESCRIBE_STRUCT;

START_DESCRIBE_STRUCT(TBasicDataTypes)
    DESCRIBE_FIELD(TBasicDataTypes, eight),
    DESCRIBE_FIELD(TBasicDataTypes, sixteen),
    DESCRIBE_FIELD(TBasicDataTypes, thirtytwo),
    DESCRIBE_FIELD(TBasicDataTypes, sixtyfour)
END_DESCRIBE_STRUCT;

START_DESCRIBE_STRUCT(T8and64BitataTypes)
    DESCRIBE_FIELD(T8and64BitataTypes, eight),
    DESCRIBE_FIELD(T8and64BitataTypes, sixtyfour)
END_DESCRIBE_STRUCT;

START_DESCRIBE_STRUCT(T8and32BitataTypes)
    DESCRIBE_FIELD(T8and32BitataTypes, eight),
    DESCRIBE_FIELD(T8and32BitataTypes, thirtytwo)
END_DESCRIBE_STRUCT;

START_DESCRIBE_STRUCT(TOnly8bitataType)
    DESCRIBE_FIELD(TOnly8bitataType, eight)
END_DESCRIBE_STRUCT;

#if defined(__x86_64__) || defined(_M_X64)
    #define ARCH_STRING "x86_64"
#elif defined(__i386__) || defined(_M_IX86)
    #define ARCH_STRING "x86"
#elif defined(__aarch64__) || defined(_M_ARM64)
    #define ARCH_STRING "arm64"
#elif defined(__arm__) || defined(_M_ARM)
    #define ARCH_STRING "arm"
#elif defined(__wasm64__)
    #define ARCH_STRING "wasm64"
#elif defined(__wasm32__)
    #define ARCH_STRING "wasm32"
#elif defined(__riscv)
    #define ARCH_STRING "riscv"
#else
    #define ARCH_STRING "unknown"
#endif

// ---------- Compiler detection ----------
#if defined(__clang__)
    #define COMPILER_STRING "Clang"
#elif defined(__GNUC__)
    #define COMPILER_STRING "GCC"
#elif defined(_MSC_VER)
    #define COMPILER_STRING "MSVC"
#elif defined(__EMSCRIPTEN__)
    #define COMPILER_STRING "Emscripten"
#else
    #define COMPILER_STRING "Unknown Compiler"
#endif

int main(int argc, const char* argv[]) {
    printf("A small example to show structure packing across platforms\n");
    printf("Platform: %s\n", ARCH_STRING);
    printf("Compiler: %s\n", COMPILER_STRING);
    /*showStructure(&TFieldDescriptor_meta);
    showStructure(&example_data_structure_meta);
    showStructure(&example_data_structure_padded_pointer_meta);*/
    //showStructure(&TBasicDataTypes_meta);
    //showStructure(&T8and64BitataTypes_meta);
    //showStructure(&T8and32BitataTypes_meta);
    //showStructure(&TOnly8bitataType_meta);
    //showStructure(&TAllDataTypes_meta);
    showStructure(&TAllDataTypesWithUnion_meta);
    return 0;
}

