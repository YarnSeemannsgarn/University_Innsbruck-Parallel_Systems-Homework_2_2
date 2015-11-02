#include <stdlib.h>

#define max 1024 * 1024 // Use ulimit -s 65536 in bash to enable big enough stack

int main(){
   float a[max], b[max], c[max], d[max];

   int i;
   for(i = 0; i < max; i++)
     a[i] = b[i] + c[i] * d[i];

   return EXIT_SUCCESS;
}
