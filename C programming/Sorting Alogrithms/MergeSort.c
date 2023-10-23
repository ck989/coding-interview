#include <stdio.h>
#include <stdlib.h>

#define MAX_ARRAY_SZ 8

void merge(int* arr, int* left, int leftSize, int* right, int rightSize) {
    int i = 0, j = 0, k = 0;

    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < leftSize) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < rightSize) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void MergeSort(int* arr, int n) {
    if (n < 2)
        return;

    int mid = n / 2;
    int left[mid];
    int right[n - mid];

    for (int i = 0; i < mid; i++)
        left[i] = arr[i];
    for (int i = mid; i < n; i++)
        right[i - mid] = arr[i];

    MergeSort(left, mid);
    MergeSort(right, n - mid);
    
    merge(arr, left, mid, right, n - mid);
}

int main() {
    
    int arr[MAX_ARRAY_SZ] = {3, 6, 8, 2, 5, 1, 4, 7};
    MergeSort(arr, MAX_ARRAY_SZ);
    for(int i = 0; i < MAX_ARRAY_SZ; i++){
        printf("%d\t",arr[i]);
    }
    
    return 0;
}
