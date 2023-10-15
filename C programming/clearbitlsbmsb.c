#include <stdio.h>
#include <stdint.h>

uint8_t clrmsbtoi(uint8_t n, uint8_t pos){
    uint8_t mask = (1 << pos) - 1;
    
    return n & mask;
}

uint8_t clrlsbtoi(uint8_t n, uint8_t pos){
    uint8_t mask = (1 << pos + 1) - 1;
    
    return n & ~mask;
}

int main()
{
    uint8_t num = 0xFF;
    uint8_t res1 = clrmsbtoi(num, 3); //clears all bits from 8th to 3rd bit
    printf("res1 0x%x\n", res1);
    
    uint8_t res2 = clrlsbtoi(num, 3); //clears all bits from 0 to 3 bit
    printf("res2 0x%x", res2);
    
    return 0;
}

/*
output:
res1 0x7
res2 0xf0 
*/
