#include "triangle_array.h"
#include "matrices.h"

int main(void) {
    int triangle[10] = {};

    *get_tr(3, 2, triangle) = 10;
    print_triangle(5, triangle);

    double matrice1[][3] =
    {{15, 14, 12},
     {6 , 7 , 1 },
     {54, 5 , 7 }};

    printf("det = %f\n", determinant(*matrice1, 3));
    print_matrice(*matrice1, 3, 3);
    printf("--------------\n");

    const double matrice2[][3] =
    {{1 , 3, 5},
     {12, 1, 2},
     {2 , 5, 4}};

    double matrice[3][3] = {{}};

    multiply_matrices(*matrice, *matrice1, *matrice2, 3, 3, 3, 3);

    print_matrice(*matrice, 3, 3);

    const double m[2][3] =
        {{1, 2, 3},
         {4, 5, 6}};
    double res[3][2] = {{}};
    transpose_matrice(*res, *m, 3, 2);
    print_matrice(*res, 2, 3);
}
