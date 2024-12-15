
#define WASM_EXPORT(A) __attribute__((export_name(A)))
#define WASM_IMPORT(A, B) __attribute__((__import_module__((A)), __import_name__((B))))

WASM_IMPORT("host", "addanswer") void addanswer(int result); 

WASM_EXPORT("add") void add(int a, int b) {
    addanswer( a + b );
}

