#include <stdio.h>
#include "field_offset_calc.h"
#include "example_data_structure.h"

START_DESCRIBE_STRUCT(TFieldDescriptor)
    DESCRIBE_FIELD(TFieldDescriptor, name),
    DESCRIBE_FIELD(TFieldDescriptor, offset),
    DESCRIBE_FIELD(TFieldDescriptor, size)
END_DESCRIBE_STRUCT;

START_DESCRIBE_STRUCT(example_data_structure)
    DESCRIBE_FIELD(example_data_structure, eight),
    DESCRIBE_FIELD(example_data_structure, sixteen),
    DESCRIBE_FIELD(example_data_structure, thirtytwo),
    DESCRIBE_FIELD(example_data_structure, eightAgain),
    DESCRIBE_FIELD(example_data_structure, pointer),
    DESCRIBE_FIELD(example_data_structure, byteArray)
END_DESCRIBE_STRUCT;



int main(int argc, const char* argv[]) {
    printf("A small example to show structure packing across platforms\n");
    showStructure(&TFieldDescriptor_meta);
    showStructure(&example_data_structure_meta);
    return 0;
}

