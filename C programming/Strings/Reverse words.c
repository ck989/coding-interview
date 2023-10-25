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
        while(i < end && str[i] == ' ')
            i++;
        
        j = i + 1;
        while(j < end && str[j] != ' ')
            j++;
        
        strrev(&str[i], i, j - i - 1);
        i = j + 1;
    }
}

int main() {
    
    char str[20] = "This book is mine";
    int len = strlen(str);
    
    Reversewords(str, 0, len - 1);
    printf("%s",str);
    return 0;
}
