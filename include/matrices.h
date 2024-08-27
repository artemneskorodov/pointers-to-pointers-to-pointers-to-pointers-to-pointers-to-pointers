#ifndef MATRICES_H
#define MATRICES_H

#include <stdio.h>
#include <stdlib.h>

enum matrice_state_t {
    MATRICE_ERROR,
    MATRICE_SUCCESS
};

void print_matrice(double *matrice, size_t width, size_t height);

matrice_state_t add_matrices(double *result, const double *first, const double *second, size_t width, size_t height);

matrice_state_t multiply_matrices(double *result, const double *first, const double *second, size_t width_first, size_t height_first, size_t width_second, size_t height_second);

matrice_state_t multiply_constant_matrice(double *result, double multiplier, const double *matrice, size_t width, size_t height);

matrice_state_t transpose_matrice(double *result, const double *matrice, size_t width, size_t height);

double determinant(const double *matrice, size_t n);

#endif
