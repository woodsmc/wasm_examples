#ifndef WASM_LINKING_CONTROLS_H_
#define WASM_LINKING_CONTROLS_H_

#ifdef __wasm__
#define WASM_IMPORT(A, B) __attribute__((__import_module__((A)), __import_name__((B))))
#define WASM_EXPORT(A) __attribute__((export_name(A)))
#else
#define WASM_IMPORT(A, B)
#define WASM_EXPORT(A)
#endif 

#endif // WASM_LINKING_CONTROLS_H_