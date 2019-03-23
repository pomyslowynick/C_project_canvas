#include <stdio.h>

void foo ( int* n );

int main() {
    int num1 = 99;
    //int num2 = 22;
    //int *pAddressOfNum1 =&num1;
    //int *pAddressOfNum2 =&num2;
    // printf("\n pAddressOfNum1 stores the address %p\n", pAddressOfNum1);
    // printf("\n pAddressOfNum2 stores the address %p\n", pAddressOfNum2);
    foo(&num1);
    foo(&num1);
    printf("%d\n", num1);
    return 0;
}

void foo ( int* n ) {
    printf(" Value %d, address %p\n", *n, n);
    ++*n; 
}