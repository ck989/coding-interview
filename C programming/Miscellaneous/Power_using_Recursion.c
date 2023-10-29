#include <stdio.h>
/*
Refer to this youtube: https://www.youtube.com/watch?v=wAyrtLAeWvI
*/
int PowerRecur(int x, int n){
    if(n == 0)
        return 1;
    else if(n%2 == 0){
        int y = PowerRecur(x, n/2);
        return y*y;
    }else{
        return x * PowerRecur(x, n - 1);
    }
}

int main()
{    
    int Base = 3, exponent = 10;
    
    int res = PowerRecur(Base, exponent);
    printf("%d\n", res);
    return 0;
}

/*
59049
*/
