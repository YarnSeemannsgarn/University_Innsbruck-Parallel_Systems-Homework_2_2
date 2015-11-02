#include <stdlib.h>

#define max 1024 * 1024 // Use ulimit -s 65536 in bash to enable big enough stack

int main(){
  float a[max * 4]; // Use only one array to reduce cache misses

  int i;
  for(i = 0; i < max; i++)
    a[i*4] = a[i*4+1] + a[i*4+2] * a[i*4+3];

   return EXIT_SUCCESS;
}
