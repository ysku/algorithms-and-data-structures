#ifndef PATTERN_MATCHING_H
#define PATTERN_MATCHING_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

bool brute_force(char *pattern, size_t m, char *text, size_t n);

bool rabin_karp(char *pattern, size_t m, char *text, size_t n);

#endif
