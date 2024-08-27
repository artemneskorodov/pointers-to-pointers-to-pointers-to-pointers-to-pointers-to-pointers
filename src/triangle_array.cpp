#include "triangle_array.h"

void print_triangle(size_t sizeY, int *triangle) {
    size_t offset = 0;
    for(size_t y = 0; y < sizeY; y++) {
        for(size_t x = 0; x < y; x++, offset++)
            printf("tr[%llu][%llu] = %d ", y, x, triangle[offset]);
        printf("\n");
    }
}

size_t count_offset_in_triangle(size_t y, size_t x) {
    return y * (y - 1) / 2 + x;
}

int *get_tr(size_t y, size_t x, int *triangle) {
    return triangle + count_offset_in_triangle(y, x);
}
