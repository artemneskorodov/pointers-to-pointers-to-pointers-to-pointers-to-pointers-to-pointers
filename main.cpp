#include <stdio.h>
#include <stdlib.h>
#include "triangle_array.h"

int main(void) {
    int triangle[10] = {};

    *get_tr(3, 2, triangle) = 10;
    print_triangle(5, triangle);
}
