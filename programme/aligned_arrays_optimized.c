#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define max 1024 * 1024 // Use ulimit -s 65536 in bash to enable big enough stack

int main(){
  float a[max * 4]; // Use only one array to reduce cache misses

  int i;
  clock_t begin, end;
  double time_spent;
  printf("Starting to traverse 1024x1024 arrays\n");
  begin = clock();
  for(i = 0; i < max; i++)
    a[i*4] = a[i*4+1] + a[i*4+2] * a[i*4+3];
  end = clock();
  time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("Time spent: %fs\n", time_spent);

  return EXIT_SUCCESS;
}
