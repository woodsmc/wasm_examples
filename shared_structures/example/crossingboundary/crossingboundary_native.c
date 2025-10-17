#include "crossingboundary.h"
#include <stdio.h>
#include <stdlib.h>
#include "wasm_export.h"

void update_native_addresses(wasm_module_inst_t module_inst, XTLinkedListNodePtr* head) {
    // In a real application, you would have a way to map the wasm pointers to native pointers.
    // For this example, we will assume that the wasm pointers are valid native pointers.
    XTLinkedListNodePtr* current = head;
    
    while (!XPTR_IS_COMPLETELY_NULL(*current)) {
        XPTR_RESOLVE_HOST(module_inst, *current);
       current = &XPTR(*current)->next;
    }
}


void printList(wasm_exec_env_t exec_env, XTLinkedListNodePtr* head) {
    printf("Native -- Printing list:\n");
    wasm_module_inst_t module = wasm_runtime_get_module_inst(exec_env);
    update_native_addresses(module, head);

    fflush(stdout);
    XTLinkedListNodePtr* current = head;
    XPTR_PRINT(*current);
    
    while (XPTR(*current) != NULL) {
        printf("Node value: %u\n", XPTR(*current)->value);
        current = &XPTR(*current)->next;
    }

    fflush(stdout);
}


static NativeSymbol native_symbols[] = {
    { "printList", printList, "(*)", NULL }
};

uint32_t
get_native_lib(char **p_module_name, NativeSymbol **p_native_symbols)
{
  printf("%s\n", __func__);
    *p_module_name = "example";
    *p_native_symbols = native_symbols;
    return sizeof(native_symbols) / sizeof(NativeSymbol);
}
