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
// crossplatformpointer.h
#pragma once
#include <stdint.h>

/*
Note: I refer the reader the following blog posts:
- https://iafisher.com/blog/2020/06/type-safe-generics-in-c
*/

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

#define XPTR_SET_NULL(A) (A).wasm.ptr = NULL; (A).host.ptr = NULL
#define XPTR_IS_COMPLETELY_NULL(A) ((A).wasm.ptr == NULL && (A).host.ptr == NULL)
#define XPTR_IS_HOST_NULL(A) ((A).host.ptr == NULL)
#define XPTR_IS_WASM_NULL(A) ((A).wasm.ptr == NULL)
#define XPTR_GET_WASM_ADDR(A) ((A).wasm.u64)

#define XPTR_SET(A, P) (A).wasm.ptr = (P).wasm.ptr; (A).host.ptr = (P).host.ptr
#define XPTR_PRINT(A) printf("XPTR: wasm.ptr=%p host.ptr=%p\n", (void*)(A).wasm.ptr, (void*)(A).host.ptr)

#ifdef __wasm__
#define XPTR(A) ((A).wasm.ptr)
#define _XPTR wasm.ptr
#else // ! __wasm__
#define XPTR(A) ((A).host.ptr)
#define _XPTR host.ptr
#define XPTR_RESOLVE_HOST(module_inst, A) if( (A).wasm.ptr && !(A).host.ptr ) { (A).host.ptr = wasm_runtime_addr_app_to_native( (module_inst), (A).wasm.u64); }
#endif // __wasm__





