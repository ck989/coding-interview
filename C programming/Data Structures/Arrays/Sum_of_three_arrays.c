#include <stdio.h>
#include <stdlib.h>

void merge(int* arr, int* left, int leftSize, int* right, int rightSize){
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
        arr[k] = left[i];
        i++;
        k++;
    }
    
    while(j < rightSize){
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergesort(int *arr, int n){
    if(n < 2) return;
    
    int mid = n/2;
    int left[mid];
    int right[n - mid];
    
    for(int i = 0; i < mid; i++){
        left[i] = arr[i];
    }
    
    for(int i = mid; i < n; i++){
        right[i - mid] = arr[i];
    }
    
    mergesort(left, mid);
    mergesort(right, n - mid);
    
    merge(arr, left, mid, right, n - mid);
}

/*
Refer to the following youtube link: https://www.youtube.com/watch?v=DhFh8Kw7ymk
*/
int* SumthreeArray(int* arr, int len, int target){
    
    mergesort(arr, len); //sort before proceeding...
    
    int* res = (int*)calloc(3,sizeof(int)); //init size 3 since the expected result array size is always 3
    
    for(int i = 0; i < len; i++){
        int j = i + 1;
        int k = len - 1;
        
        while(j < k){
            int sum = arr[i] + arr[j] + arr[k];
            if(sum < target){
                j++;
            }else if(sum > target){
                k--;
            }else{//found the combo
                res[0] = arr[i];
                res[1] = arr[j];
                res[2] = arr[k];
                break;
            }
        }
    }
    
    return res;
}

int main() {
    
    int arr[] = {3, 7, 1, 2, 8, 5};
    int target = 20;
    int len = sizeof(arr)/sizeof(arr[0]);
    
    int* arr1 = SumthreeArray(arr, len, target);
    for(int i = 0; i < 3; i++){
        printf("%d\t", arr1[i]);
    }
    free(arr1);
    
    return 0;
}

/*
output: 
5       7       8
*/
