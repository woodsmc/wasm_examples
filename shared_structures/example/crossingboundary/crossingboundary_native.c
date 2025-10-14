#include "crossingboundary.h"
#include <stdio.h>
#include <stdlib.h>
#include "wasm_export.h"


void printList(wasm_exec_env_t exec_env, XTLinkedListNodePtr* head) {
    printf("Printing list:\n");
    XTLinkedListNodePtr current = {0};
    SET_XPTR(current, *head);
    while (XPTR(current) != NULL) {
        printf("Node value: %u\n", XPTR(current)->value);
        SET_XPTR(current, XPTR(current)->next);
    }

    fflush(stdout);
}


static NativeSymbol native_symbols[] = {
    { "printList", printList, "(*)", NULL }
};

uint32_t
get_native_lib(char **p_module_name, NativeSymbol **p_native_symbols)
{
    *p_module_name = "example";
    *p_native_symbols = native_symbols;
    return sizeof(native_symbols) / sizeof(NativeSymbol);
}
