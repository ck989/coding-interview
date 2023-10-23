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

    // Allocate memory with extra bytes for alignment
    ptr = malloc(size + alignment - 1);
    if (ptr == NULL) {
        perror("malloc");
        return NULL;
    }

    // Calculate the aligned pointer within the allocated block
    uintptr_t addr = (uintptr_t)ptr;
    size_t offset = (alignment - (addr % alignment)) % alignment;
    aligned_ptr = (void*)(addr + offset);

    return aligned_ptr;
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
        free(aligned_memory);  // Don't forget to free the allocated memory
    }

    return 0;
}
