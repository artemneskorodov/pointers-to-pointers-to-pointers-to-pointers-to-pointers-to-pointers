#include "triangle_array.h"
#include "matrices.h"

int main(void) {
    const double matrice1[3][3] =
        {{12 , 32.4, 12  },
         {4.2, 32  , 1.5 },
         {7.5, 8   , 3.53}};

    const double matrice2[3][4] =
        {{43.3, 324, 23.5 , 12.4},
         {7   , 54 , 4.543, 61  },
         {42  , 4.3, 342.3, 32.3}};

    double multiplying_result[3][4] = {{}};
    multiply_matrices(*multiplying_result, *matrice1, *matrice2, 3, 3, 4, 3);
    print_matrice(*multiplying_result, 4, 3);
    printf("-------------\n");

    const double matrice3[3][3] =
        {{423.4, 43.4,  43  },
         {43.4 , 342.3, 34.3},
         {1    , 312.2, 32.1}};
    double adding_result[3][3] = {{}};
    add_matrices(*adding_result, *matrice1, *matrice3, 3, 3);
    print_matrice(*adding_result, 3, 3);
    printf("-------------\n");

    double transposing_result[4][3] = {{}};
    transpose_matrice(*transposing_result, *matrice2, 4, 3);
    print_matrice(*transposing_result, 3, 4);
    printf("-------------\n");

    printf("%lg", determinant(*matrice3, 3));
}
