#include <stdio.h>
#include <stdlib.h>

int** ReturnArray(void) {
    int** arr = (int**)malloc(5 * sizeof(int*));
    
    for(int i = 0; i < 5; i++) {
        arr[i] = (int*)malloc(5 * sizeof(int));
    }
    
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            arr[i][j] = i * 5 + j;
        }
    }
    
    return arr;
}

int main() {
    
    int** arr = ReturnArray();
    
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
    
    for(int i = 0; i < 5; i++){
        free(arr[i]);
    }
    
    free(arr);
    
    return 0;
}
