#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#define SIZE 1000000
int main(){
   int i;
   int *A,*B,*C;
   A = (int*)malloc(SIZE*sizeof(int));
   B = (int*)malloc(SIZE*sizeof(int));
   C = (int*)malloc(SIZE*sizeof(int));
   for(i=0;i<SIZE;i++){
      A[i] = i;
      B[i] = 2*i;
   }
#pragma omp parallel for
   for(i=0;i<SIZE;i++){
      C[i] = A[i] + B[i];
   }
   printf("First 10 elements of result array: \n");
   for (i=0;i<10;i++){
      printf(" %d ", C[i]);
   }
   free(A);
   free(B);
   free(C);
   return 0;
}

