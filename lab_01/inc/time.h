#ifndef TIME_H
#define TIME_H

#define NUMBER_OF_RUNS 10
#define HZ 1600000

#include <stdio.h>
#include <cstdint>

uint64_t tick(void);
void print_result(int64_t start, int64_t end);
#endif