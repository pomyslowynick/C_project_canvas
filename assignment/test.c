
#include <stdio.h>
#include <math.h>


double root(double n){
  double lo = 0, hi = n, mid;
  for(int i = 0 ; i < 1000 ; i++){
      mid = (lo+hi)/2;
      if(mid*mid == n) return mid;
      if(mid*mid > n) hi = mid;
      else lo = mid;
  }
  return mid;
}

int main () {
   static double len = 200.0;
   printf("Square root of %lf is %lf\n", 4.0, sqrt(len) );
   printf("Square root of %lf is %lf\n", 5.0, root(5.0) );
   
   return(0);
}