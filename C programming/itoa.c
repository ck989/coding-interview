#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void strrev(char* str){
    int i = 0;
    int j = strlen(str) - 1;
    char temp;
    
    while(i < j){
        temp = str[j];
        str[j] = str[i];
        str[i] = temp;
        i++;
        j--;
    }
}

char* itoa(int val){
    char* str = (char*)malloc(10*sizeof(char)); //assuming size of string to be 10
    int index = 0;
    
    if(val < 0){
        str[index++] = '-';
        val = -val;
    }
    
    while(val != 0){
        str[index++] = (val % 10) + '0';
        val /= 10;
    }
    
    strrev(&str[1]);
    
    return str;
}

int main() {
    
    int val = -1234;
    char* str = itoa(val);
    printf("%s", str);
    free(str);
    
    return 0;
}
