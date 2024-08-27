#ifndef TRIANGLE_ARRAY_H
#define TRIANGLE_ARRAY_H

#include <stdio.h>
#include <stdlib.h>

size_t count_offset_in_triangle(size_t y, size_t x);

void print_triangle(size_t sizeY, int *triangle);

int *get_tr(size_t y, size_t x, int *triangle);

#endif
