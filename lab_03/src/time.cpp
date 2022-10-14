#include "../inc/time.hpp"

#include <stdio.h>
#include <string>
#include <cstdint>

uint64_t tick(void)
{
    uint32_t high, low;
    __asm__ __volatile__ (
        "rdtsc\n"
        "movl %%edx, %0\n"
        "movl %%eax, %1\n"
        : "=r" (high), "=r" (low)
        :: "%rax", "%rbx", "%rcx", "%rdx"
        );

    uint64_t ticks = ((uint64_t)high << 32) | low;

    return ticks;
}

void print_result(int64_t start, int64_t end)
{
    printf("%lld processor cycles, %.10lf seconds\n", end - start, (double)(end - start)/HZ);  
}