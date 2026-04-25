#include <stdio.h>
#include <omp.h>

int main() {
    int r, c, i, j;

    printf("Enter number of rows: ");
    scanf("%d", &r);

    printf("Enter number of columns: ");
    scanf("%d", &c);

    int A[r][c], B[r][c], C[r][c];


    printf("Enter matrix elements:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &A[i][j]);
        }
    }


    #pragma omp parallel for private(j)
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            B[i][j] = A[i][c - j - 1];
        }
    }


    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            C[i][j] = B[i][j];
        }
    }


    printf("\nOriginal Matrix:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }


    printf("\nHorizontally Mirrored Matrix:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
