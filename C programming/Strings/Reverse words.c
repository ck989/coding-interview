#include <stdio.h>
#include <string.h>

void strrev(char* str, int start, int end){
    char temp;
    while(start < end){
        temp = str[end];
        str[end] = str[start];
        str[start] = temp;
        start++;
        end--;
    }
}

void Reversewords(char* str, int start, int end){
    
    strrev(str, start, end);
    
    int i = 0, j = 0;
    while(str[i] != '\0'){
        while(i < end && str[i] == ' ') i++; //check if there is any prepending space and eliminate it
        
        j = i + 1;
        while(j < end && str[j] != ' ') j++; //iterate until you find a space
        
        if(j == end) j++; //account the last missing char for reversing
        
        strrev(str, i, j - 1); //reverse only the selected range of indices
        i = j + 1; //skip space
    }
}

int main() {
    
    char str[50] = "This book is mine, the ruler of the world";
    int len = strlen(str);
    
    Reversewords(str, 0, len - 1);
    printf("%s",str);
    return 0;
}

/*
output:
world the of ruler the mine, is book This
*/
