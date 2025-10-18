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

#include <stdio.h>
#include "crossplatformpointer.h"

CREATE_CACHED_XPLATFORM(uint32_t, xuint32Ptr);




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


    uint32_t val = 42;
    xuint32Ptr u32pr;
    XPTR_SET_NULL(u32pr);
    XPTR(u32pr) = NULL;
    printf("A small example to show cross platform pointers\n");
    XPTR(u32pr) = &val;
    printf("val is %u\n", *XPTR(u32pr));
    *XPTR(u32pr) = 52;
    printf("val is %u\n", val);

    return 0;
}

