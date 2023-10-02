#include <stdio.h>

#define MAX_ARRAY_SZ 8

void BubbleSort(int* arr, int n){
    
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(arr[i] > arr[j]){
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}

int main() {
    
    int arr[MAX_ARRAY_SZ] = {3, 6, 8, 2, 5, 1, 4, 7};
    BubbleSort(arr, MAX_ARRAY_SZ);
    
    for(int i = 0; i < MAX_ARRAY_SZ; i++){
        printf("%d\t",arr[i]);
    }
    
    return 0;
}
