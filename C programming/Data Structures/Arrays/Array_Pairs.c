/*****************************************************************************************
Given an array, return pairs that satisfies the following conditions:
* i < j < k -> these are array indices
* arr[i] < arr[k] < arr[j] -> these are values at respective indices.

For Example: In the input array, arr[] = {2, 4, 8, 10, 6, 1};
the pairs that satisfies the above 2 conditions are {2, 6, 8}, {4, 6, 8}, {2, 6, 10}
and {4, 6, 10} respectively. NOTE: These are values at respective indices.
Observe the indices of those pairs and those pairs itself.
*******************************************************************************************/

#include <stdio.h>

typedef struct {
    int arr[10][3];
    int count;
} arr_int;

/*
ToDo: This logic is not returning all the possible pairs. Needs to be corrected
*/
arr_int Pairs_exists(int* arr, int n){
    arr_int res;
    res.count = 0;
    int j, k;
    
    for(int i = 0; i < n; i++){
        j = i + 1;
        k = n - 1 - i;
        while(j < k){
            while(arr[i] > arr[j]) i++;
            
            j = i+1;
            
            while(arr[j] < arr[k]) j++;
            
            if(arr[i] < arr[k] && arr[k] < arr[j]){
                res.arr[res.count][0] = arr[i];
                res.arr[res.count][1] = arr[k];
                res.arr[res.count][2] = arr[j];
                res.count++;
            }
            j++;
            k--;
        }
    }
    
    return res;
}

int main() {
    int arr[] = {2, 4, 8, 10, 6, 1};
    int len = sizeof(arr)/sizeof(arr[0]);
    
    arr_int res = Pairs_exists(arr, len);
    
    for(int i = 0; i < res.count; i++){
        for(int j = 0; j < 3; j++){
            printf("%d\t",res.arr[i][j]);
        }
        printf("\n");
    }
}

/*
output:
2       6       8
4       6       8
*/
