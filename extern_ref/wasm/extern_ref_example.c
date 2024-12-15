#include "wasm_linking.h"

static __externref_t table[0];

WASM_EXPORT("set_ref") void set_ref(__externref_t r) {
  if ( __builtin_wasm_table_size(table) == 0 ) {
    __builtin_wasm_table_grow(table, r, 1);
  }
    
  __builtin_wasm_table_set(table, 0, r);
}

WASM_EXPORT("get_ref") __externref_t get_ref() {
  __externref_t retval = __builtin_wasm_table_get(table, 0);

  return retval;
}


