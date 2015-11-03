#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define max 1024 * 1024 // Use ulimit -s 65536 in bash to enable big enough stack

int main(){
   float a[max], b[max], c[max], d[max];
   
   int i;
   clock_t begin, end;
   double time_spent;
   printf("Starting to traverse 1024x1024 arrays\n");
   begin = clock();
   for(i = 0; i < max; i++)
     a[i] = b[i] + c[i] * d[i];
   end = clock();
   time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
   printf("Time spent: %fs\n", time_spent);  

   return EXIT_SUCCESS;
}
