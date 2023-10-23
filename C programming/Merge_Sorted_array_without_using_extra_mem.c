#include <stdio.h>

void SwapIfGreater(int* arr1, int* arr2, int index1, int index2){
    if(arr1[index1] > arr2[index2]){
        int temp = arr1[index1];
        arr1[index1] = arr2[index2];
        arr2[index2] = temp;
    }
}
/*
Check this link for merging: https://www.youtube.com/watch?v=txh1zq9PaFw&list=PLk6CEY9XxSIDApw_RB8cowBQmzrznmpTA&index=7
Gap Alogrithm is used here
*/
void Gap_Algorithm(int* arr1, int* arr2, int n, int m){
    int len = n + m;
    int Gap = (len / 2) + (len % 2); //take ceil of a num, that is if 3.5, consider it as 4 instead of 3.
    
    while(Gap > 0){
        int index1 = 0;
        int index2 = index1 + Gap;
        while(index2 < len){
            if((index1 < n) && (index2 >= n)){ //when one of them is in left and other one in right array
                SwapIfGreater(arr1, arr2, index1, index2 - n);
            }else if(index1 >= n){// when both of them are in right array
                SwapIfGreater(arr2, arr2, index1 - n, index2 - n);
            }else{//when both of them are in left array
                SwapIfGreater(arr1, arr1, index1, index2);
            }
            index1++;
            index2++;
        }
        if(Gap == 1) break;
        Gap = (Gap / 2) + (Gap % 2);
    }
}

int main() {
    //passing two sorted array
    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {0, 2, 6, 8, 9};
    
    int len1 = sizeof(arr1)/sizeof(arr1[0]);
    int len2 = sizeof(arr2)/sizeof(arr1[0]);
    
    Gap_Algorithm(arr1, arr2, len1, len2);
    
    printf("After Sorting\n");
    for(int i = 0; i < len1; i++){
        printf("%d\t", arr1[i]);
    }
    printf("\n");
    for(int i = 0; i < len2; i++){
        printf("%d\t", arr2[i]);
    }
    
    return 0;
}

/*
Output: 
After Sorting
0	1	2	3	
5   6	7	8	9	
*/
