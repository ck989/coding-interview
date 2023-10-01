#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct _LinkedList{
    int a;
    struct _LinkedList* Next;
}LinkedList;

void* AlignedMalloc(size_t type){
    size_t alignment = type;
    void* RetPtr;
    
    while(1){
        RetPtr = malloc(type);
        
        if(((uintptr_t)RetPtr & (alignment - 1)) == 0){
            printf("%p\n", (uintptr_t)RetPtr);
            printf("address is %d byte aligned\n",alignment);
            break;
        }
        
        free(RetPtr);
    }
    
    return RetPtr;
}

int main() {
    // Write C code here
    //input any data type here
    LinkedList* a = (LinkedList*)AlignedMalloc(sizeof(LinkedList));
    printf("Aligned malloc success..\n");
    free(a);

    return 0;
}
