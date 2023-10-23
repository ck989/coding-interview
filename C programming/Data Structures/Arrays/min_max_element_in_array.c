#include <stdio.h>
#include <stdbool.h>

#define MAX_ARRAY_SZ 8

void Merge(int* arr, int* left, int leftSize, int* right, int rightSize){
    int i = 0, j = 0, k = 0;
    
    while(i < leftSize && j < rightSize){
        if(left[i] <= right[j]){
            arr[k] = left[i];
            i++;
        }else{
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    
    while(i < leftSize){
        arr[k++] = left[i++];
    }
    
    while(j < rightSize){
        arr[k++] = right[j++];
    }
}

void MergeSort(int* arr, int len){
    
    if(len < 2) return;
    
    int mid = len/2;
    
    int left[mid];
    int right[len - mid];
    
    for(int i = 0; i < mid; i++)
        left[i] = arr[i];
    
    for(int i = mid; i < len; i++)
        right[i - mid] = arr[i];
    
    MergeSort(left, mid);
    MergeSort(right, len - mid);
    
    Merge(arr, left, mid, right, len - mid);
}

int main() {
    
    int arr[MAX_ARRAY_SZ] = {6, 9 , 8, 7, 9, 2, 0, 10};
    MergeSort(arr, MAX_ARRAY_SZ); //sort an array before finding min and max element

    int min_element = arr[0];
    int max_element = arr[MAX_ARRAY_SZ - 1];
    
    printf("min_element = %d, max_element = %d\n", min_element, max_element);
    return 0;
}
