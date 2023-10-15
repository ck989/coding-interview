#include <stdio.h>
#include <stdint.h>

uint8_t countnumsetbits(uint8_t n){
    uint8_t count = 0;
    
    while(n){
        n &= (n - 1);
        count++;
    }
    return count;
}

int main()
{
    uint8_t num = 0xCA;
    
    uint8_t cnt = countnumsetbits(num);
    printf("Num of set bits = %d\n", cnt);
    
    return 0;
}
