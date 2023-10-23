/*************************************************************************************************
should print longest palindrome substring in a given string, use dynamic programming algorithm
Refer this youtube link: https://www.youtube.com/watch?v=fxwvVnBMN6I
*************************************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* long_Palindrome_using_dp(char* str, int len){
    int i = 0;
    char* res_str = (char*)malloc(len*sizeof(char));
    int resLen = 0;
    
    int** dp = (int**)calloc(len, sizeof(int*));
    
    for(i = 0; i < len; i++){
        dp[i] = (int*)calloc(len, sizeof(int));
    }
    
    for(int diff = 0; diff < len; diff++){
        for(int i = 0, j = i + diff; j < len; i++, j++){
            
            if(i == j) dp[i][j] = 1; //all the diagonal elements will be will 1 since, single char itself is a palindrome
            else if(diff == 1) dp[i][j] = (str[i] == str[j])?2:0; //just add 2 since you are comparing 2 chars
            else{
                if(str[i] == str[j] && dp[i + 1][j - 1]){
                    dp[i][j] = dp[i + 1][j - 1] + 2; //just add 2 since you are comparing 2 chars
                }
            }
            
            if(dp[i][j]){
                if(j - i + 1 > resLen){
                    resLen = j - i + 1;
                    strncpy(res_str, &str[i], j - i + 1);
                }
            }
        }
    }
    
    for(i = 0; i < len; i++){
        free(dp[i]);
    }
    free(dp);
    
    return res_str;
}

int main()
{
    char* str = "eexieeixaaabaa";
    int len = strlen(str);
    
    char* res = long_Palindrome_using_dp(str, len);
    printf("%s\n", res);
    free(res);
    return 0;
}

/*
output:
xieeix
*/
