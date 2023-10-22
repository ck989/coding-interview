/******************************************************************************
print all palindrome strings in the given string under the following conditions.
conditions:
 1. xieeix is a palindrome in the main string but you are not supposed to 
    print ieei since it is substring of previosuly printed palindrome
 2. Observe the end of the input string "lelelvele", you see "lelel" and "ele"
    are two different palindrome, "ele" can be again printed because you see
    "ele" is at different indices.
*******************************************************************************/

#include <stdio.h>
#include <string.h>

void Print_palindrome(char* str, int* mid, int len){
    int init_index = *mid, end_index = *mid+1; //fetch two adjacent characters
    
    if(str[init_index] != str[end_index]){ // compare those
        end_index++;         //if not equal increment second index
        if(str[init_index] != str[end_index]){ //again compare those chars
            return;         //there won't be any palindrome possibility, hence exit
        }
    }
    
    while(init_index >= 0 && end_index < len){
        if(str[init_index] != str[end_index]){
            break;
        }else{
            init_index--;
            end_index++;
        }
    }
    
    init_index++;
    end_index--; //minor correction before printing
    
    for(int i = init_index; i <= end_index; i++){
        printf("%c", str[i]);
    }
    printf("\n");
    
    *mid = end_index;   //update mid with updated value to avoid printing the substring palindrome                     
}

void Plindrome(char* str, int len){
    int i = 0;
    while(i < len){
        Print_palindrome(str, &i, len);
        i++;
    }
}

int main()
{
    char* str = "xieeixlbiblelelvele";
    int len = strlen(str);
    
    Plindrome(str, len);

    return 0;
}

/*
output:
xieeix
lbibl
lelel
ele
*/
