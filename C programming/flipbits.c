#include <stdio.h>
#include <stdint.h>

uint8_t flippbits(uint8_t n){

    uint8_t i = 0;
    uint8_t flipped = 0;
    
    while(n > 0)
    {
        flipped += ((n & 0x01)^1) << i;
        i++;
        n >>=1;
    }
    return flipped;
}

uint8_t flippbits_bitwise(uint8_t n){

    return ~n;
}

int main()
{
    uint8_t num = 0xCA;
    
    uint8_t res1 = flippbits(num);
    printf("0x%x\n",res1);
    
    uint8_t res2 = flippbits_bitwise(num);
    printf("0x%x\n",res2);
    
    if(res1 == res2)
        printf("Passed\n");
    
    return 0;
}
