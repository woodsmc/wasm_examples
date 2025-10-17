
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

#include <stddef.h>
#include <stdint.h>


typedef struct TFieldDescriptor
{
    const char* name;
    uint64_t offset;
    uint64_t size;
} TFieldDescriptor;

typedef struct TStructDescriptor
{
    const char* name;
    uint64_t size;
    TFieldDescriptor fields[];
} TStructDescriptor;

#define START_DESCRIBE_STRUCT(s) const TStructDescriptor s##_meta = { \
    .name = #s, \
    .size = sizeof(s), \
    .fields = { 

#define DESCRIBE_FIELD(s, f) { .name = #f, \
    .offset = offsetof(s, f), \
    .size = sizeof(((s *)0)->f) }

#define END_OF_FIELD {.name = NULL, .offset = 0, .size = 0}

#define END_DESCRIBE_STRUCT , END_OF_FIELD } }

void showStructure(const TStructDescriptor* description);

