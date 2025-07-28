#pragma once
#include <stdint.h>

// Borrowing concepts from - https://iafisher.com/blog/2020/06/type-safe-generics-in-c

#define CONCAT(A, B) A##B
#define MONIKER _XPLATFORM
#define CREATE_XPLATFORM_PTR_TYPE(payload_type, new_type_name) \
    typedef union new_type_name { \
        uint64_t u64; \
        payload_type* ptr; \
    } new_type_name

#define CREATE_CACHED_XPLATFORM(payload_type, name) \
    CREATE_XPLATFORM_PTR_TYPE(payload_type, CONCAT(payload_type, MONIKER));\
    typedef struct name {\
        CONCAT(payload_type, MONIKER) wasm;\
        CONCAT(payload_type, MONIKER) host;\
    } name

#define SET_NULL(A) (A).wasm.ptr = NULL; (A).host.ptr = NULL

#ifdef __wasm__
#define XPTR(A) ((A).wasm.ptr)
#else // ! __wasm__
#define XPTR(A) ((A).host.ptr)
#endif // __wasm__

CREATE_CACHED_XPLATFORM(uint32_t, xuint32Ptr);



