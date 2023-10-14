#include <stdio.h>
#include <stdint.h>

#define NUM_BITS 8

uint8_t Reverse_bit_Itr(uint8_t n){
    uint8_t m = 0;
    for(int i = 0; i < NUM_BITS; i++)
    {
        m <<= 1;
        m |= (n & 1);
        n >>=1;
    }
    return m;
}

uint8_t Reverse_bit(uint8_t n){
    return (((n&0x01) << NUM_BITS - 1)|
            ((n&0x02) << NUM_BITS - 3)|
            ((n&0x04) << NUM_BITS - 5)|
            ((n&0x08) << NUM_BITS - 7)|
            ((n&0x10) >> NUM_BITS - 7)|
            ((n&0x20) >> NUM_BITS - 5)|
            ((n&0x40) >> NUM_BITS - 3)|
            ((n&0x80) >> NUM_BITS - 1));
}

int main()
{
    uint8_t num = 0xC5;
    
    printf("Reversing a bit using iterative method\n");
    uint8_t res1 = Reverse_bit_Itr(num);
    printf("0x%x\n", res1);
    
    printf("Reversing a bit using bitwise method\n");
    uint8_t res2 = Reverse_bit(num);
    printf("0x%x\n", res2);
    
    if(res1 == res2)
        printf("Both passed\n");

    return 0;
}

/*
output:
Reversing a bit using iterative method
0xa3
Reversing a bit using bitwise method
0xa3
Both passed
*/
