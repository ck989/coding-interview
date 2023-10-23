#include <stdio.h>

#define MAX_ARRAY_SZ 8

void swap(int* x, int* y){
    *x = *x ^ *y;
    *y = *y ^ *x;
    *x = *y ^ *x;
}

/*
refer this youtube: https://www.youtube.com/watch?v=Q_eia3jC9Ts&t=44s
*/
void MaxHeapify(int* arr, int n, int i){
    int largeIndex = i;
    int leftIndex = 2*i + 1;
    int rightIndex = 2*i + 2;
    
    if(leftIndex < n && arr[leftIndex] > arr[largeIndex])
        largeIndex = leftIndex;
    
    if(rightIndex < n && arr[rightIndex] > arr[largeIndex])
        largeIndex = rightIndex;
        
    if(largeIndex != i){
        swap(&arr[largeIndex], &arr[i]);
        MaxHeapify(arr, n, largeIndex);
    }
}

void HeapSort(int* arr, int n){
    for(int i = n/2; i >= 0; i--){
        MaxHeapify(arr, n, i);
    }
    
    for(int i = n - 1; i >= 1; i--){ //deletion of node from root node
        swap(&arr[0], &arr[i]);
        MaxHeapify(arr, i, 0);
    }
}

int main() {
    
    int arr[MAX_ARRAY_SZ] = {3, 6, 8, 2, 5, 1, 4, 7};
    HeapSort(arr, MAX_ARRAY_SZ);
    for(int i = 0; i < MAX_ARRAY_SZ; i++){
        printf("%d\t",arr[i]);
    }
    
    return 0;
}   

/*
output: 
1       2       3       4       5       6       7       8
*/
