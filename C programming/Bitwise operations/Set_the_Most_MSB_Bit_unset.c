#include <stdio.h>
#include <stdint.h>

void Set_the_Most_MSB_Bit_unset(uint8_t* input){
    *input |= (*input + 1);
}

int main()
{
    uint8_t num = 0xC4;
    
    Set_the_Most_MSB_Bit_unset(&num);
    
    printf("After setting the MSB unset bit 0x%x\n", num);
    return 0;
}
