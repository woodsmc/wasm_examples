#include "wasm_linking.h"

static __externref_t reference[0];
static int table_size = 0;

WASM_EXPORT("set_ref") void set_ref(__externref_t r) {
  if ( table_size == 0 )
    __builtin_wasm_table_grow(reference, r, 1);

  __builtin_wasm_table_set(reference, 0, r);
  table_size++;
}

WASM_EXPORT("get_ref") __externref_t get_ref() {
  __externref_t retval = __builtin_wasm_table_get(reference, 0);

  return retval;
}


