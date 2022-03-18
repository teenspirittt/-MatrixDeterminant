#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double gauss_determinant(double *a, int n);
double *triangulation(double *a, int n);

int main() {
    srand(time(NULL));

    FILE *f;
    if ((f = fopen("read.txt", "r")) == NULL)
        return 0;

    int size;
    double *matrix;
    clock_t time_start, time_finish;
    while (fscanf(f, "%d", &size) == 1) {
        matrix = (double *) malloc(size * size * sizeof(double ));
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                fscanf(f, "%lf", &matrix[i * size + j]);
            }
        }
        time_start = clock();
        matrix = triangulation(matrix, size);
        double det = gauss_determinant(matrix, size);
        time_finish = clock();
        printf("%ld\n", time_finish - time_start);

        free(matrix);
    }
    fclose(f);
    return 0;
}

double *triangulation(double *a, int n) {
    for (int k = 0; k < n; k++) {
        for (int i = k + 1; i < n; i++) {
            double mu = a[i * n + k] / a[k * n + k];
            for (int j = 0; j < n; j++)
                a[i * n + j] -= a[k * n + j] * mu; // todo cuda
        }
    }
    return a;
}

double gauss_determinant(double *a, int n) {
    double det = 1;
    for (int i = 0, j = 0; i < n, j < n; ++i, ++j) {
        det *= a[i * n + j];
    }
    return det;
}
