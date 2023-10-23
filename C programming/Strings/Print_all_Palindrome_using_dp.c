/*************************************************************************************************
should print all the palindromes in a given string, use dynamic programming algorithm
Refer this youtube link: https://www.youtube.com/watch?v=biHfMygdoCE
*************************************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Print_all_Palindrome_using_dp(char* str, int len){
    
    int** dp = (int**)calloc(len, sizeof(int*));
    for(int i = 0; i < len; i++){
        dp[i] = (int*)calloc(len, sizeof(int));
    }
    
    for(int diff = 0; diff < len; diff++){
        for(int i = 0, j = diff; j < len; i++, j++){
            
            if(i == j) dp[i][j] = 1; //all the diagonal elements will be will 1 since, single char itself is a palindrome
            else if(diff == 1) dp[i][j] = (str[i] == str[j])?1:0;
            else{
                if(str[i] == str[j]){
                    dp[i][j] = dp[i + 1][j - 1]; //dp algorithm
                }
            }
            
            if(dp[i][j]){
                for(int k = i; k <= j; k++){//prints all the palindrome here
                  printf("%c",str[k]);
                }
                printf("\n");
            }
        }
    }
        
    for(int i = 0; i < len; i++){
        free(dp[i]);
    }
    free(dp);
}
    

int main()
{
    char* str = "aaab";
    int len = strlen(str);
    
    Print_all_Palindrome_using_dp(str, len);
    return 0;
}

/*
output:
a
a
a
b
aa
aa
aaa
*/
