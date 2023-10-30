#include <stdio.h>

/*
Refer to this youtube: https://www.youtube.com/watch?v=5qGrJbHhqFs
*/
int binarySearch(int arr[], int low, int high, int target) {
    while (low <= high) {
        int mid = (low + high)/2;

        // If target is found, return the index
        if (arr[mid] == target)
            return mid;
        
        //If left half is sorted
        if(arr[low] <= arr[mid]){
            if(arr[low] <= target && target <= arr[mid]){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }else{//if right half is sorted
            if(arr[mid] <= target && target <= arr[high]){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
    }

    // Target element is not present in the array
    return -1;
}

int main() {
    int arr[] = {7, 8, 9, 1, 2, 3, 4, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 1;

    int index = binarySearch(arr, 0, size - 1, target);

    if (index != -1)
        printf("Element %d found at index %d.\n", target, index);
    else
        printf("Element %d not found in the array.\n", target);

    return 0;
}

/*
Element 1 found at index 3.
*/
