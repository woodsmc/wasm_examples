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
    SET_NULL(XPTR(newNode)->next);

    if (XPTR(head) == NULL) {
        printf("The list was empty, this node is the first node %u\n", value);
        return newNode;
    }

    printf("Adding node with value %u to the front of the list\n", value);
    SET_XPTR(XPTR(newNode)->next, head);
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
    printList(&head);
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