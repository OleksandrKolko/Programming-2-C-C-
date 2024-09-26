#include <stdio.h>
#include <math.h>
 int main() {
     unsigned int n;
     printf("n = \n");
     scanf("%u", &n);
     printf("n! = ");
     for (int i = 1; i < n; i++) {
         printf("%u*", i);
     }
     printf("%u", n);
 }