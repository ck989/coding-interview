#include <stdio.h>
#include <limits.h>

void Find_MaxElement(int* arr, int len){
    int max_element = arr[0];
    
    for(int i = 1; i < len; i++){
        if(arr[i] > max_element)
            max_element = arr[i];
    }
    
    printf("Max element: %d\n", max_element);
}

void Find_MinElement(int* arr, int len){
    int min_element = arr[0];
    
    for(int i = 1; i < len; i++){
        if(arr[i] < min_element)
            min_element = arr[i];
    }
    
    printf("Min element: %d\n", min_element);
}

/*
Refer this youtube link for algorithm: https://www.youtube.com/watch?v=37E9ckMDdTk
*/
void Find_SecondLarge(int* arr, int len){
    int f_largest = arr[0];
    int s_largest = INT_MIN;
    
    for(int i = 1; i < len; i++){
        if((arr[i] > f_largest) && (arr[i] != f_largest)){
            s_largest = f_largest;
            f_largest = arr[i];
        }else if((arr[i] > s_largest) && (arr[i] != f_largest)){
            s_largest = arr[i];
        }
    }
    
    printf("Second Largest: %d\n", s_largest);
}

void Find_SecondMin(int* arr, int len){
    int f_min = arr[0];
    int s_min = INT_MAX;
    
    for(int i = 1; i < len; i++){
        if((arr[i] < f_min) && (arr[i] != f_min)){
            s_min = f_min;
            f_min = arr[i];
        }else if((arr[i] < s_min) && (arr[i] != f_min)){
            s_min = arr[i];
        }
    }
    
    printf("Second Min: %d\n", s_min);
}

int main() {
    
    int arr[] = {6, 10, 8, 2, 44, 50, 72, 1, 6, 30, 100, 120, 160, 82, 53, 76, -120};
    // int arr[] = {6, 10, 8, 2, 50, 44, 72, 72, 1, 1, -1};
    int len = sizeof(arr)/sizeof(arr[0]);
    
    Find_MaxElement(arr, len);
    Find_MinElement(arr, len);
    Find_SecondLarge(arr, len);
    Find_SecondMin(arr, len);
    
    return 0;
}
