/******************************************************************************
prints all possible palindrome string in the given string.
It will consider single chararcter itself as a 
palindrome as well and prints all the possible combo

Refer the youtube link for algorithm: https://www.youtube.com/watch?v=4RACzI5-du8&t=613s
*******************************************************************************/

#include <stdio.h>
#include <string.h>

void Print_Palindrome(char* str, int left, int right, int len){

    while(left >= 0 && right < len && str[left] == str[right]){
        for(int i = left; i <= right; i++){
            printf("%c",str[i]);
        }
        printf("\n");
        
        left--;
        right++;            
    }
}

void Plindrome(char* str, int len){
    int i = 0;
    while(i < len){
       Print_Palindrome(str, i, i, len);
       Print_Palindrome(str, i, i + 1, len);
       i++;
    }
}

int main()
{
    char* str = "aaab";
    int len = strlen(str);
    
    Plindrome(str, len);
    return 0;
}


/*
a
aa
a
aaa
aa
a
b
*/
