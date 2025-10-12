#include <stdio.h>
#include "crossplatformpointer.h"

xuint32Ptr u32pr;

uint32_t val = 42;

typedef union TXPointer {
    void* ptr;
    uint64_t padding;
} TXPointer;

typedef struct TCachedXPointer {
    TXPointer wasm;
    TXPointer host;
} TCachedXPointer;

typedef struct TLinkedListNode TLinkedListNode;
CREATE_CACHED_XPLATFORM(TLinkedListNode, XTLinkedListNode);

typedef struct TLinkedListNode {
    XTLinkedListNode next;
    uint32_t value;
} TLinkedListNode;

int main(int argc, const char* argv[]) {
    uint32_t value = 42;
    TCachedXPointer cp = {0};
    XPTR(cp) = &value;

    printf("value is %u\n", *(uint32_t*)XPTR(cp));


    SET_NULL(u32pr);
    XPTR(u32pr) = NULL;
    printf("A small example to show cross platform pointers\n");
    XPTR(u32pr) = &val;
    printf("val is %u\n", val);
    *XPTR(u32pr) = 52;
    printf("val is %u\n", val);

    return 0;
}

