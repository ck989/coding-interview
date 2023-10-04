#include <stdio.h>
#include <stdlib.h>

void printCombinations(int target, int start, int *combination, int length) {
    if (target == 0) {
        // Print the combination
        for (int i = 0; i < length; i++) {
            printf("%d ", combination[i]);
        }
        printf("\n");
        return;
    }

    for (int i = start; i <= target; i++) {
        combination[length] = i;
        printCombinations(target - i, i, combination, length + 1);
    }
}

void printAllCombinations(int target) {
    int* combination = (int*)malloc(target * sizeof(int));
    printCombinations(target, 1, combination, 0);
    free(combination); // Free the dynamically allocated memory
}

int main() {
    int target = 3;
    printf("All possible combinations of positive integers that add up to %d:\n", target);
    printAllCombinations(target);
    return 0;
}
