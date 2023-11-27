/*
Given two strings str1 and str2, they are of equal length.
An extra char is added str2 and it is jumbled, find that extra char
*/

#include <stdio.h>
#include <string.h>

char find_extra_char(char* str1, char* str2){
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    
    char char1 = str1[0];
    for(int i = 1; i < len1; i++){
        char1 ^= str1[i];
    }
    
    char char2 = str2[0];
    for(int i = 1; i < len2; i++){
        char1 ^= str2[i];
    }
    
    return char1 ^ char2;
}

int main()
{
    char* str1 = "abdc";
    char* str2 = "eacdb";
    
    char res = find_extra_char(str1, str2);
    
    printf("extra char is %c\n", res);

    return 0;
}

/*
output: extra char is e
*/
