cmake_minimum_required(VERSION 3.14)
include(CheckPIESupported)
include(CMakePrintHelpers)

project(CallBackExample VERSION 1.0.0 DESCRIPTION "A WAMR host environment will a call back")

#if(POLICY CMP0079)
#    cmake_policy(SET CMP0079 NEW)
#endif()

# Resetdefault linker flags
set(CMAKE_SHARED_LIBRARY_LINK_C_FLAGS "")
set(CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS "")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Wformat -Wformat-security")

set (WAMR_BUILD_PLATFORM "linux")
set (WAMR_BUILD_TARGET "X86_64")
set (WAMR_BUILD_INTERP 1)
set (WAMR_BUILD_FAST_INTERP 1)
set (WAMR_BUILD_AOT 1)
set (WAMR_BUILD_LIBC_BUILTIN 1)
set (WAMR_BUILD_LIBC_WASI 1)
set(WAMR_BUILD_REF_TYPES 1)
# set (WAMR_BUILD_SIMD 1)
set (WAMR_ROOT_DIR /home/mad/wasm-micro-runtime)

# The VMLib Here
include (${WAMR_ROOT_DIR}/build-scripts/runtime_lib.cmake)
add_library(vmlib ${WAMR_RUNTIME_LIB_SOURCE})

include (${WAMR_ROOT_DIR}/core/shared/utils/uncommon/shared_uncommon.cmake)

set(sources ${sources} 
   ./main.c
   ${UNCOMMON_SHARED_SOURCE}
)

cmake_print_variables(sources)

add_executable(callbackexample ${sources} )
target_include_directories(callbackexample PRIVATE ../h)
target_include_directories(callbackexample PRIVATE ${WAMR_ROOT_DIR}/core/iwasm/include)


check_pie_supported()
set_target_properties(callbackexample PROPERTIES POSITION_INDPENDENT_CODE ON)

target_link_libraries (callbackexample vmlib -lm -dl -lpthread -lrt)
# target_link_libraries(callbackexample m)


