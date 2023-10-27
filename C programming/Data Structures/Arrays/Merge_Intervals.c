#include <stdio.h>
#include <stdlib.h>

typedef struct _Pairs{
    int first;
    int second;
}Pairs;

Pairs* MergeInterval(Pairs* interval, int n, int* mergedlen){
    
    Pairs* res = (Pairs*)malloc(10 * sizeof(Pairs));
    int i = 0, j = 0;
    
    for(i = 0, j = 0; i < n; i++){
        if(i == 0 || interval[i].first > res[j - 1].second) res[j++]  = interval[i];
        else{
            if(interval[i].first < res[j - 1].second && interval[i].second > res[j - 1].second){
                res[j - 1].second = interval[i].second;
            }
        }
    }
    
    *mergedlen = j;
    return res;
}

int main()
{
    Pairs interval[] = {{1, 5},{3, 7},{4, 6},{6, 8},{10, 12},{20,30},{25,36}}; //assuming sorted array
    int len = sizeof(interval)/sizeof(interval[0]);
    int mergedlen = 0;
    
    Pairs* res = MergeInterval(interval, len, &mergedlen);
    for(int i = 0; i < mergedlen; i++)
        printf("%d %d\n",res[i].first, res[i].second);
    
    free(res);
    return 0;
}

/*
output:
1 8
10 12
20 36
*/
