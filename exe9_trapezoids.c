#include <stdio.h>
#include <omp.h>


double f(double x) {
    return x * x;
}

int main() {
    int n, i;
    double a, b, h, sum = 0.0, x;

    printf("Enter lower limit (a): ");
    scanf("%lf", &a);

    printf("Enter upper limit (b): ");
    scanf("%lf", &b);

    printf("Enter number of trapezoids (n): ");
    scanf("%d", &n);

    h = (b - a) / n;

    sum = (f(a) + f(b)) / 2.0;

    #pragma omp parallel for private(x) reduction(+:sum)
    for (i = 1; i < n; i++) {
        x = a + i * h;
        sum += f(x);
    }

    double result = h * sum;

    printf("\n[Using Reduction] Integral = %lf\n", result);


    sum = (f(a) + f(b)) / 2.0;

    #pragma omp parallel for private(x)
    for (i = 1; i < n; i++) {
        x = a + i * h;

        #pragma omp critical
        {
            sum += f(x);
        }
    }

    result = h * sum;

    printf("[Using Critical] Integral = %lf\n", result);

    return 0;
}
