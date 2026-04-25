#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main()
{
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int* array = (int*)malloc(n * sizeof(int));
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    int target;
    printf("Enter the target value: ");
    scanf("%d", &target);
    int local_count = 0;
    #pragma omp parallel for
    //int local_count = 0;
        for (int i = 0; i < n; i++)
        {
            if (array[i] < target)
            {
            #pragma omp critical
            {
                local_count++;
            }
            }
        }
        //count += local_count;

    printf("The count of elements less than %d is: %d\n", target, local_count);
    free(array);

    return 0;

}
