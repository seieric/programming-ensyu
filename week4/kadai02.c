#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void eig(double[2][2], double *, double *, double *, double *);

int main()
{
    double val1;
    double val2;
    double vec1[2];
    double vec2[2];
    double mat[2][2] = {{1, 5}, {6, 2}};
    eig(mat, &val1, &val2, vec1, vec2);
    printf("[%f, %f]\n", mat[0][0], mat[0][1]);
    printf("[%f, %f]\n", mat[1][0], mat[1][1]);
    printf("eigenvalue = %f, eigenvector = (%f, %f)\n", val1, vec1[0], vec1[1]);
    printf("eigenvalue = %f, eigenvector = (%f, %f)\n", val2, vec2[0], vec2[1]);
    return 0;
}

void eig(double mat[2][2], double *val1, double *val2, double *vec1, double *vec2)
{
    double tmp = sqrt(mat[0][0] * mat[0][0] - 2 * mat[0][0] * mat[1][1] + 4 * mat[0][1] * mat[1][0] + mat[1][1] * mat[1][1]);
    *val1 = (-1.0 * tmp + mat[0][0] + mat[1][1]) * 0.5;
    *val2 = (tmp + mat[0][0] + mat[1][1]) * 0.5;
    vec1[0] = (-1.0 * tmp + mat[0][0] - mat[1][1]) * 0.5 / mat[1][0];
    vec1[1] = 1.0;
    vec2[0] = (tmp + mat[0][0] - mat[1][1]) * 0.5 / mat[1][0];
    vec2[1] = 1.0;
}