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

#include "crossingboundary.h"
#include <stdio.h>
#include <stdlib.h>
#include "wasm_export.h"

void update_native_addresses(wasm_module_inst_t module_inst, XTLinkedListNodePtr* head) {
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
