
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