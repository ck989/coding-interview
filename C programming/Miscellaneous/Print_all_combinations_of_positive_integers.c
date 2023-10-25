#include <stdio.h>
#include <stdlib.h>

void PrintCombo(int target, int start, int* combo, int length){
    
    if(target == 0){
        for(int i = 0; i < length; i++){
            printf("%d \t", combo[i]);
        }
        printf("\n");
    }
    
    for(int i=start; i <= target; i++){
        combo[length] = i;
        PrintCombo(target - i, start, combo, length + 1);
    }
}

void PrintAllCombinations(int target){
    int* combo = (int*)malloc(target*sizeof(int));
    PrintCombo(target, 1, combo, 0);
    free(combo);
}

int main() {
    int target = 3;
    printf("All possible combinations of positive integers that add up to %d:\n", target);
    PrintAllCombinations(target);
    return 0;
}


/*
Output:
All possible combinations of positive integers that add up to 3:
1       1       1 
1       2 
2       1 
3 
*/
