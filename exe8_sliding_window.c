#include <stdio.h>
#include <omp.h>

int main() {
    int n, w, i, j;

    printf("Enter size of array (n): ");
    scanf("%d", &n);

    int A[n];

    printf("Enter array elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    printf("Enter window size: ");
    scanf("%d", &w);

    int result_size = n - w + 1;


    if (w > n || w <= 0) {
        printf("Invalid window size!\n");
        return 0;
    }

    int sum[result_size];


    #pragma omp parallel for private(j)
    for (i = 0; i < result_size; i++) {
        sum[i] = 0;
        for (j = 0; j < w; j++) {
            sum[i] += A[i + j];
        }
    }


    printf("\nSliding Window Sums:\n");
    for (i = 0; i < result_size; i++) {
        printf("%d ", sum[i]);
    }
    printf("\n");

    return 0;
}

