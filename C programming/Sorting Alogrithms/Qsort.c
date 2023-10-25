#include <stdio.h>
#include <stdlib.h>

#define MAX_ARRAY_SZ 8

void swap(int* x, int* y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int* arr, int start, int end){
    int pIndex = start;
    int Pivot = arr[end];
    
    for(int i = start; i < end; i++){
        if(arr[i] <= Pivot){
            swap(&arr[i], &arr[pIndex]);
            pIndex++;
        }
    }
    swap(&arr[pIndex], &arr[end]);
    
    return pIndex;
}

void QSort(int* arr, int start, int end){
    int pIndex = 0;
    
    if(start < end){
        pIndex = partition(arr, start, end);
        QSort(arr, start, pIndex - 1);
        QSort(arr, pIndex + 1, end);
    }
    
}

int main() {
    
    int arr[MAX_ARRAY_SZ] = {3, 6, 8, 2, 5, 1, 4, 7};
    QSort(arr, 0, MAX_ARRAY_SZ - 1);
    for(int i = 0; i < MAX_ARRAY_SZ; i++){
        printf("%d\t",arr[i]);
    }
    
    return 0;
}
