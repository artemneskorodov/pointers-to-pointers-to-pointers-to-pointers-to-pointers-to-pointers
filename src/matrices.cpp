#include <assert.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include "matrices.h"

static bool is_zero(double number);

void print_matrice(const double *matrice, size_t width, size_t height) {
    assert(matrice != NULL);

    for(size_t y = 0; y < height; y++) {
        printf("|");
        for(size_t x = 0; x < width; x++)
            printf("%f  ", matrice[y * width + x]);
        printf("|\n");
    }
}

matrice_state_t add_matrices(double *result, const double *first, const double *second, size_t width, size_t height) {
    assert(result != NULL);
    assert(first  != NULL);
    assert(second != NULL);

    for(size_t y = 0; y < height; y++)
        for(size_t x = 0; x < width; x++)
            result[y * width + x] = first[y * width + x] + second[y * width + x];
    return MATRICE_SUCCESS;
}

matrice_state_t multiply_matrices(double *result, const double *first, const double *second, size_t width_first, size_t height_first, size_t width_second, size_t height_second) {
    assert(result != NULL);
    assert(first  != NULL);
    assert(second != NULL);

    if(width_first != height_second)
        return MATRICE_ERROR;

    for(size_t y = 0; y < height_first; y++)
        for(size_t x = 0; x < width_second; x++) {
            result[y * width_second + x] = 0;
            for(size_t k = 0; k < width_first; k++)
                result[y * width_second + x] += first[y * width_first + k] * second[k * height_second + x];
        }
    return MATRICE_SUCCESS;
}

matrice_state_t multiply_constant_matrice(double *result, double multiplier, const double *matrice, size_t width, size_t height) {
    assert(matrice != NULL);
    assert(result  != NULL);

    for(size_t y = 0; y < height; y++)
        for(size_t x = 0; x < width; x++)
            result[y * width + x] = matrice[y * width + height] * multiplier;
    return MATRICE_SUCCESS;
}

matrice_state_t transpose_matrice(double *result, const double *matrice, size_t width, size_t height) {
    assert(result  != NULL);
    assert(matrice != NULL);

    for(size_t y = 0; y < height; y++)
        for(size_t x = 0; x < width; x++)
            result[x * height + y] = matrice[y * width + x];
    return MATRICE_SUCCESS;
}

double determinant(const double *matrice, size_t n) {
    assert(matrice != NULL);
    double *copy = (double *)calloc(n * n, sizeof(double));
    if(copy == NULL)
        return NAN;
    for(size_t y = 0; y < n; y++)
        for(size_t x = 0; x < n; x++)
            copy[y * n + x] = matrice[y * n + x];
    double determinant = 1;
    for(size_t line = 0; line < n; line++) {
        for(size_t y = line; y < n; y++) {
            double divisor = copy[y * n + line];
            if(is_zero(divisor)) {
                free(copy);
                return 0;
            }
            determinant *= divisor;
            for(size_t x = line; x < n; x++)
                copy[y * n + x] /= divisor;
        }

        for(size_t y = line + 1; y < n; y++)
            for(size_t x = 0; x < n; x++)
                copy[y * n + x] -= copy[line * n + x];
    }
    free(copy);
    return determinant;
}

static bool is_zero(double number) {
    const double epsilon = 1e-9;
    if(fabs(number) < epsilon)
        return true;
    return false;
}
