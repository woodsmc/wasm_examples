#include <stdio.h>

void function_a(void) {
    printf("I'm function %s with address %p\n", __func__, &function_a);
}


void function_b(void) {
    printf("I'm function %s with address %p\n", __func__, &function_b);
}

int main(void) {
    printf("A quick function pointer example, compare this as a native or wasm based application\n");
    #ifdef __wasm__
    printf("This is WebAssembly's version:\n");
    #else
    printf("This is the native version:\n");
    #endif // __wasm__

    function_a();
    function_b();
    printf("thanks.... bye..\n");
    return 0;
}