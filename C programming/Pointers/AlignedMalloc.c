#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void* aligned_malloc(size_t size, size_t alignment) {
    void *ptr = NULL;
    void *aligned_ptr = NULL;

    // Ensure alignment is a power of 2
    if ((alignment & (alignment - 1)) != 0) {
        fprintf(stderr, "Alignment must be a power of 2.\n");
        return NULL;
    }
    
    /*
     Allocate memory with extra bytes for alignment and Allocate for sizeof(void*),
     the reason sizeof(void*) is it will be useful for freeing the memory because
     we are not returning the address returned by the malloc, we need some space
     to store the actual address returned by the malloc
    */
    ptr = malloc(size + alignment + sizeof(void*));
    if (ptr == NULL) {
        perror("malloc");
        return NULL;
    }
    
    if (((uintptr_t)ptr & (alignment - 1)) == 0) {
        printf("returned address is already aligned.\n");
    }
    /*
     Calculate the aligned pointer within the allocated block, this math ensures that 
     the aligned_ptr address is multiple of alignment, overallocating sizeof(void*) to
     makespace to store the original malloc address
    */
    uintptr_t addr = (uintptr_t)ptr + alignment + sizeof(void*);
    // aligned_ptr = (void*)(addr & ~(alignment - 1));
    aligned_ptr = (void*)(addr - (addr % alignment));
    
    //store the original address above aligned_ptr address to freeing this address further
    *((uintptr_t*)aligned_ptr - 1) = (uintptr_t)ptr;
    
    return aligned_ptr;
}

void aligned_free(void* ptr){
    //deference the original malloc address to free
    free((void*)(*((uintptr_t*)ptr - 1)));
    printf("aligned_free done\n");
}

int main() {
    size_t size = 100;  // Size of memory to allocate
    size_t alignment = 16;  // Desired alignment

    // Allocate aligned memory
    void* aligned_memory = aligned_malloc(size, alignment);
    if (aligned_memory == NULL) {
        printf("Failed to allocate aligned memory.\n");
    } else {
        printf("Successfully allocated aligned memory at address: %p\n", aligned_memory);
        aligned_free(aligned_memory);
    }

    return 0;
}

/*
Successfully allocated aligned memory at address: 0x560f968f72b0
aligned_free done
*/
