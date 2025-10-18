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

// corssingboundary_wasm.c
#include "crossingboundary.h"
#include <stdio.h>
#include <stdlib.h>

#define WASM_IMPORT(A, B) __attribute__((__import_module__((A)), __import_name__((B))))

WASM_IMPORT("example", "printList") void printList(XTLinkedListNodePtr* head); 

XTLinkedListNodePtr addToList(XTLinkedListNodePtr head, uint32_t value) {
    XTLinkedListNodePtr newNode = {0};
    XPTR(newNode) = malloc(sizeof(TLinkedListNode));
    if (XPTR(newNode) == NULL) {
        printf("Failed to allocate memory for new node\n");
        return newNode;
    }
   
    XPTR(newNode)->value = value;
    XPTR_SET_NULL(XPTR(newNode)->next);

    if (XPTR(head) == NULL) {
        printf("The list was empty, this node is the first node %u\n", value);
        return newNode;
    }

    printf("Adding node with value %u to the front of the list\n", value);
    XPTR_SET(XPTR(newNode)->next, head);
    printf("newNode->next is %p\n", (void*)XPTR(XPTR(newNode)->next));

    return newNode;
}

int main(void) {
    XTLinkedListNodePtr head = {0};
    for(int i = 0; i < 10; i++) {
        head = addToList(head, i);
        printf("head is %p\n", (void*)XPTR(head));
    }

    printf("Calling printList in the native code\n");
    fflush(stdout);
    printList(&head);
    fflush(stdout);
    printf("Returned from printList in the native code\n");

    // Free the list
    XTLinkedListNodePtr current = head;
    while (XPTR(current) != NULL) {
        XTLinkedListNodePtr next = XPTR(current)->next;
        free(XPTR(current));
        current = next;
    }
    printf("Freed the list and all finished\n");
    return 0;
}
