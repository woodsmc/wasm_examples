#include <stdio.h>
#include <stdint.h>
#include <string.h>

struct Flags {
    unsigned a : 1;
    unsigned b : 1;
    unsigned c : 2;
    unsigned d : 4;
}; // total 8 bits declared

int main(void) {
    struct Flags f = {0};

    f.a = 1;   // 0000 0001
    f.b = 0;   // 0000 0000
    f.c = 3;   // 0000 1100
    f.d = 9;   // 1001 0000 (only lower 4 bits kept)

    uint8_t bytes[sizeof f] = {0};
    memcpy(bytes, &f, sizeof f);

    printf("sizeof(struct Flags) = %zu bytes\n", sizeof f);
    printf("Bitfield bytes: ");
    for (size_t i = 0; i < sizeof f; i++)
        printf("%02X ", bytes[i]);
    printf("\n");

    // Sanity-check by reading fields back
    printf("a=%u b=%u c=%u d=%u\n", f.a, f.b, f.c, f.d);

    return 0;
}

