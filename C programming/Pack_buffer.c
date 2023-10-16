#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define INT_BITS 8

//if itr 1, the mask bit is 1'b, if it is 2, the mask bit is 11'b and so online

/*
ToDo: Optimize mask_bits function
*/
uint8_t mask_bits(uint8_t itr){
    if(itr == 1) return 0x01;
    else if(itr == 2) return 0x03;
    else if(itr == 3) return 0x07;
    else if(itr == 4) return 0x0F;
    else if(itr == 5) return 0x1F;
}

//Insert bit 1 for every 8 bits..
void pack_buffer(uint8_t* in_buff, uint32_t in_buff_len, uint8_t* out_buff){
    
    uint8_t prev_missed_bits = 0;
    out_buff[0] = in_buff[0]; //assign first byte
    for(uint8_t i = 1; i <= in_buff_len; i++){
        
        out_buff[i] = prev_missed_bits << (INT_BITS - (i - 1)) | (1 << INT_BITS - i) | in_buff[i] >> i; //account missed_bits from the previous iteration, insert bit 1 with corresponding offset 
                                                                                                        //and right shift the input buffer by respective offset (offset depends in iteration value)
        prev_missed_bits = in_buff[i] & mask_bits(i);
    }
}

int main() {
    uint8_t in_buff[4] = {0x00, 0x01, 0x02, 0x03};
    uint8_t out_buff[5] = {0};

    printf("Input Buff: ");
    for(uint8_t i = 0; i < 4; i++){
        printf("0x%02x\t", in_buff[i]);
    }  
    printf("\n");
  
    pack_buffer(in_buff, 4, out_buff);

    printf("Output Buff: ");
    for(uint8_t i = 0; i < 5; i++){
        printf("0x%02x\t", out_buff[i]);
    }
    return 0;
}

/*
Input Buff: 0x00        0x01    0x02    0x03
Output Buff: 0x00       0x80    0xc0    0xa0    0x70
*/

