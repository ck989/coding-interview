#include <stdio.h>

void swap_without_temp(int* x, int* y){
    
    *x = *x ^ *y;
    *y = *y ^ *x;
    *x = *y ^ *x;
    
}

int main() {
    
    int a = 10, b = 3;
    swap_without_temp(&a, &b);
    printf("%d %d\n", a,b);
    
    return 0;
}
