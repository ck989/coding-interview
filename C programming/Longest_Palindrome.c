/*************************************************************************************************
should print longest palindrome substring in a given string
Refer this youtube link: https://www.youtube.com/watch?v=XYQecbcd6_c
*************************************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Print_Palindrome(char* str, char* res_str, int left, int right, int len){
    
    static int resLen = 0;
    while(left >= 0 && right < len && str[left] == str[right]){
        if(right - left + 1 > resLen){
            resLen = right - left + 1;
            strncpy(res_str, &str[left], right - left + 1);
        }   
        
        left--;
        right++;
    }
}

char* longest_Palindrome(char* str, int len){
    int i = 0;
    char* res_str = (char*)malloc(len*sizeof(char));
    
    while(i < len){
        Print_Palindrome(str, res_str, i, i, len);
        Print_Palindrome(str, res_str, i, i + 1, len);
        i++;
    }
    
    return res_str;
}

int main()
{
    char* str = "eexieeixaaabaa";
    int len = strlen(str);
    
    char* res = longest_Palindrome(str, len);
    printf("%s\n", res);
    free(res);
    return 0;
}

/*
output:
xieeix
*/
