#include <stdio.h>

#define NONE 0xDEADBEEF //magic cookie to define no missing number

int Find_Missing_num(int* arr, int n){
    
    int expected_sum = (n + 1) * (n + 2)/2;
    int actual_sum = 0;
    
    for(int i = 0; i < n; i++){
        actual_sum += arr[i];
    }
    
    int diff = expected_sum - actual_sum;
    if(diff == 0)
        return NONE;
    
    return diff;
}

int Find_Missing_num_XOR(int* arr, int n){
    
    int xorArray = arr[0];
    for(int i = 1; i < n; i++){
        xorArray ^= arr[i]; 
    }
    
    int xorNums = 1;
    for(int i = 1; i < n; i++){
        xorNums ^= i; 
    }    
    
    int missing_num = xorArray ^ xorNums;
    if(missing_num == 0)
        return NONE;
    
    return missing_num;
}

int main() {
    
    int arr[] = {4, 3, 2, 7, 8, 1, 6, 5};
    int len = sizeof(arr)/sizeof(arr[0]);
    
    int num = Find_Missing_num(arr, len);
    if(num == NONE)
        printf("No numbers are missing\n");
    else
        printf("missing num:%d\n", num);
    
    num = Find_Missing_num_XOR(arr, len);
    if(num == NONE)
        printf("No numbers are missing\n");
    else
        printf("missing num:%d\n", num);   
    
    return 0;
}
