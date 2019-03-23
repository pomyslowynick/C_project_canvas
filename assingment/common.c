#include "canvas.h"
#include "common.h"

//copied from Stack Overflow, it calculates square root for variable
//the math.h library function sqrt doesn't compile unless 
//you include -lm flag for compilation, so I include this one
//to make compilation process easier
static double root(double n){
  double lo = 0, hi = n, mid;
  for(int i = 0 ; i <= 100 ; i++){
      mid = (lo+hi)/2;
      if(mid*mid == n) return mid;
      if(mid*mid > n) hi = mid;
      else lo = mid;
  }
  return mid;
}

int getWidth(char *canvas) {
    int len = 0;
    for(;canvas[len] != -1;len++) { 
        if(len > 1000) {
            return WIDTH_UNKNOWN;
        }
    }
    double sqroot = root((double) len);
    return sqroot;
}

//implemented this function to avoid repetition in canvas 
int getLength(char *canvas) {
    int len = 0;
    for(;canvas[len] != -1;len++) { 
        if(len > 1000) {
            return LENGTH_UNKNOWN;
        }
    }
    return len;

}