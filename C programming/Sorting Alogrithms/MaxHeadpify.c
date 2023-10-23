#include <stdio.h>
#include <stdlib.h>

#define MAX_ARRAY_SZ 8

void swap(int* x, int* y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void Heapify(int* arr, int n, int i){
    int largeIdx = i;
    int leftChildIdx = 2*i + 1;
    int rightChildIdx = 2*i + 2;
    
    if(leftChildIdx < n && arr[leftChildIdx] > arr[largeIdx])
        largeIdx = leftChildIdx;
    
    if(rightChildIdx < n && arr[rightChildIdx] > arr[largeIdx])
        largeIdx = rightChildIdx;
    
    if(largeIdx != i){
        swap(&arr[largeIdx], &arr[i]);
        Heapify(arr, n, largeIdx);
    }
}

void MaxHeapify(int* arr, int n){
    for(int i = n/2; i >= 0; i--){//start traversing from last child's parent
        Heapify(arr, n, i);
    }
}

int main() {
    
    int arr[MAX_ARRAY_SZ] = {3, 6, 8, 2, 5, 1, 4, 7};
    MaxHeapify(arr, MAX_ARRAY_SZ);
    for(int i = 0; i < MAX_ARRAY_SZ; i++){
        printf("%d\t",arr[i]);
    }
    
    return 0;
}
