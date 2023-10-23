#include <stdio.h>
#include <stdint.h>

uint8_t negate_given_range_of_bits(uint8_t n, uint8_t pos1, uint8_t pos2){
    uint8_t mask = ((1 << pos1 + 1) - 1) ^ ((1 << pos2) - 1); //calculate the mask value that fits in this range
    
    return n ^ mask;
}

int main()
{
    uint8_t num = 0x5D;
    
    uint8_t res = negate_given_range_of_bits(num, 7, 2);
    printf("0x%02x",res);
    
    return 0;
}

/*
output:
0xa1
*/
