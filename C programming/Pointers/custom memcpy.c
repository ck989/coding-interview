#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX_ARRAY_SZ 8

void Mem_Cpy(void* dst, void* src, size_t bytes){
    
    if(src == NULL || dst == NULL){
        printf("ERROR: can't copy NULL address\n");
        return;
    }
    
    if(((src + bytes) < src) || ((src + bytes) < src)){
        printf("ERROR: Memory is out of range\n");
        return;
    }
    
    if(src < dst && dst < src + bytes){
        printf("Reverse Copy due to memory overlap\n");
        for(size_t i = bytes - 1; i >= 0; i--)
            *(uint8_t*)(dst + i) = *(uint8_t*)(src + i);
    }else{
        printf("Normal copy\n");
        for(size_t i = 0; i < bytes; i++){
            *(uint8_t*)(dst + i) = *(uint8_t*)(src + i);
        }
    }
}

int main() {
    
    int arr[MAX_ARRAY_SZ] = {3, 6, 8, 2, 5, 1, 4, 7};
    int new_arr[MAX_ARRAY_SZ] = {0};
    
    Mem_Cpy(new_arr, arr, MAX_ARRAY_SZ*sizeof(int));
    
    for(int i = 0; i < MAX_ARRAY_SZ; i++){
        printf("%d\t",new_arr[i]);
    }
    
    return 0;
}
