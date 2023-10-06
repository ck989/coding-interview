#include <stdio.h>

#define INAVLID 0xFFFFFFF

int BinarySearch(int* arr, int target, int start, int end){
    
    while(start < end){
        int mid = (start + end)/2;
        
        if(arr[mid] == target)
            break;
        else if(arr[mid] < target)
            start = mid + 1;
        else if(arr[mid] > target)
            end = mid - 1;
    }
    
    return INAVLID;
}

int main() {
    
    int arr[] = {3, 6, 9, 10, 30, 52, 89};
    int len = sizeof(arr)/sizeof(arr[0]);
    int target = 52;
    // int target = 53;
    // int target = 100;
    //Binary serach work only on sorted array
    int index = BinarySearch(arr, target, 0, len - 1);
    
    if(index == INAVLID){
        printf("%d not found\n", target);
    }else{
        printf("%d found at index %d\n",target, index);
    }
    
    return 0;
}
