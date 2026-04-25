#include <stdio.h>
#include<stdlib.h>
#include <omp.h>
#define size 1000000
#define CONST_VAL 5
int main(){
   int i;
   int *A;
   A = (int*)malloc (size*sizeof(int));
   for(i=0;i<size;i++){
      A[i] = i;
   }
#pragma omp parallel for
for (i=0;i<size;i++){
   A[i] = A[i] + CONST_VAL;
}
printf(" First 10 elements after adding constant: \n");
for (i=0;i<10;i++){
   printf(" %d ", A[i]);
}
free(A);
return 0;
}

