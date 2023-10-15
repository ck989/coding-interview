#include <stdio.h>
#include <stdint.h>

#define SWAP_ENDAIAN(x) ((x & 0x000000FF) << 24 | \
                        (x & 0x0000FF00) << 8 | \
                        (x & 0x00FF0000) >> 8 | \
                        (x & 0xFF000000) >> 24)

void swap_bits(uint8_t* n, int pos1, int pos2)
{
    uint8_t bit1 = (*n >> pos1) & 0x01;
    uint8_t bit2 = (*n >> pos2) & 0x01;
    
    uint8_t xor_bit = bit1 ^ bit2;
    
    *n ^= (xor_bit << pos1 | xor_bit << pos2);
}

int main()
{
    uint8_t num = 0xC5;
    swap_bits(&num, 1, 6);
    printf("After swapping the bits 0x%x\n", num);
    
    printf("After swapping endians 0x%x\n",SWAP_ENDAIAN(0x12345678));
    
    return 0;
}

/*
output:
After swapping the bits 0x87
After swapping endians 0x78563412
*/
