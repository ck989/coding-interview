#include <stdio.h>

int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = (left + right)/2;

        // If target is found, return the index
        if (arr[mid] == target)
            return mid;

        // If target is greater, ignore the left half
        if (arr[mid] < target)
            left = mid + 1;

        // If target is smaller, ignore the right half
        else
            right = mid - 1;
    }

    // Target element is not present in the array
    return -1;
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 7;

    int index = binarySearch(arr, 0, size - 1, target);

    if (index != -1)
        printf("Element %d found at index %d.\n", target, index);
    else
        printf("Element %d not found in the array.\n", target);

    return 0;
}

/*
Element 7 found at index 3.
*/
