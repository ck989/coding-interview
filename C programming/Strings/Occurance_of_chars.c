#include <stdio.h>
#include <string.h>

void char_Occurance(char* str){
    char Alphabets[26] = {0};
    int index = 0;
    int len = strlen(str);
    printf("%d\n",len);
    
    for(int i = 0; i < len; i++){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            index = str[i] - 'A';
            Alphabets[index]++;//Get the alphabet's index and increment it's value
        }
    }
    
    for(int i = 0; i < 26; i++){
        if(Alphabets[i] > 0){
            char c = 'A' + i;
            printf("%c : %d\n", c, Alphabets[i]);
        }
    }
} 

int main() {
    
    char* str = "AABHEDDMNQQPQST";
    char_Occurance(str);
    return 0;
}
