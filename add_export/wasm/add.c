
#define WASM_EXPORT(A) __attribute__((export_name(A)))

WASM_EXPORT("add") int add(int a, int b) {
    return a + b;
}

