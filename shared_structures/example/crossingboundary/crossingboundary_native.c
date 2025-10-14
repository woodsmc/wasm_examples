#include "crossingboundary.h"
#include <stdio.h>
#include <stdlib.h>
#include "wasm_export.h"

void update_native_addresses(wasm_module_inst_t module_inst, XTLinkedListNodePtr* head) {
    // In a real application, you would have a way to map the wasm pointers to native pointers.
    // For this example, we will assume that the wasm pointers are valid native pointers.
    XTLinkedListNodePtr current = {0};
    SET_XPTR(current, *head);
    
    while (!IS_COMPLETELY_NULL(current)) {
        if (IS_HOST_NULL(current)) {
            current.host.ptr = wasm_runtime_addr_app_to_native(module_inst, XPTR_GET_WASM_ADDR(current) );
        }
        SET_XPTR(current, XPTR(current)->next);
    }
}


void printList(wasm_exec_env_t exec_env, XTLinkedListNodePtr* head) {
    printf("Native -- Printing list:\n");
    wasm_module_inst_t module = wasm_runtime_get_module_inst(exec_env);
    update_native_addresses(module, head);

    fflush(stdout);
    XTLinkedListNodePtr current = {0};
    SET_XPTR(current, *head);
    PRINT_XPTR(current);
    
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
  printf("%s\n", __func__);
    *p_module_name = "example";
    *p_native_symbols = native_symbols;
    return sizeof(native_symbols) / sizeof(NativeSymbol);
}
