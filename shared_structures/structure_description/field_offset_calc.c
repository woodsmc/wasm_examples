#include "field_offset_calc.h"
#include <stdio.h>
#include <stdbool.h>

#define LINE_LENGTH 60
#define PADDING '-'
#define DATA '#'

void showStructure(const TStructDescriptor* description) {
    printf("structure %10s[%4llu]", description->name, description->size);
    const TFieldDescriptor* field = &description->fields[0];

    uint64_t x = 0;
    while(x < description->size) {        
        while (x != field->offset && x < description->size) {
            putchar(PADDING);
            x++;
        }

        if (field->name == NULL) break;

        if (x == field->offset && x < description->size) {
            printf("\n%10s @%4llu [%4llu]:", field->name, field->offset, field->size);
            for(uint64_t i = 0; i < field->size; i++) {
                putchar(DATA);
                x++;
            }
            field++;
        }

    }
    printf("\n");
}