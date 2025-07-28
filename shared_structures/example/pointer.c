#include <stdio.h>
#include "crossplatformpointer.h"

xuint32Ptr u32pr;

uint32_t val = 42;

int main(int argc, const char* argv[]) {
    SET_NULL(u32pr);
    XPTR(u32pr) = NULL;
    printf("A small example to show cross platform pointers\n");
    XPTR(u32pr) = &val;
    printf("val is %u\n", val);
    *XPTR(u32pr) = 52;
    printf("val is %u\n", val);

    return 0;
}

