#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <limits.h>

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int *array = (int *)malloc(n * sizeof(int));
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    int max_value = array[0];
    #pragma omp parallel for reduction(max:max_value)
    for (int i = 0; i < n; i++) {
        if (array[i] > max_value) max_value = array[i];
    }
    printf("The largest number in the array is: %d\n", max_value);
    free(array);
    return 0;
}

