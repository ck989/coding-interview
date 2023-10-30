#include <stdio.h>

#define max(x,y) (x>y)?x:y

//kadane's algorithm: https://www.youtube.com/watch?v=86CQq3pKSUw
int Max_Sum_SubArray(int* arr, int n){
    
    int curr_max = arr[0], global_max = arr[0];
    
    for(int i = 1; i < n; i++){
        curr_max = max(arr[i], curr_max + arr[i]);
        if (curr_max > global_max)
            global_max = curr_max;
    }
    printf("Max_Sum_SubArray is %d\n", global_max);
}

int main()
{    
    int arr[] = {-4, 2, -5, 1, 2, 3, 6, -5, 1};
    int len = sizeof(arr)/sizeof(arr[0]);
    
    Max_Sum_SubArray(arr, len);
}

/*
Max_Sum_SubArray is 12
*/
