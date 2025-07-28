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

