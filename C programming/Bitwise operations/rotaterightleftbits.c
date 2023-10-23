#include <stdio.h>
#include <stdint.h>

#define INT_BITS 8

uint8_t leftrotate(uint8_t x, uint8_t d)
{
    return ((x << d) | (x >> (INT_BITS - d)));
}


uint8_t rightrotate(uint8_t x, uint8_t d)
{
    return ((x >> d) | (x << (INT_BITS - d)));
}

int main()
{
    printf("res1 : 0x%x\n\r", leftrotate(7,2));
    printf("res2 : 0x%x", rightrotate(7,2));
    
    return 0;
}

/*
output:
res1 : 0x1c
res2 : 0xc1
*/
