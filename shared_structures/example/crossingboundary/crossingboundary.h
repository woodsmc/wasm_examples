#pragma once
#include "crossplatformpointer.h"

typedef struct TLinkedListNode TLinkedListNode;
CREATE_CACHED_XPLATFORM(TLinkedListNode, XTLinkedListNodePtr);

typedef struct TLinkedListNode {
    XTLinkedListNodePtr next;
    uint32_t value;
} TLinkedListNode;

