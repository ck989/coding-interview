#include <stdio.h>
#include <string.h>

int a2i(char* str){
    
    if(str == NULL){
        printf("str cannot be NULL.Terminating..\n");
        return 0xFFFFFFFF;
    }
    
    int len = strlen(str);
    int i = 0;
    int negsign = 1;
    int res = 0;
    
    if(str[0] == '-'){
        negsign = -1;
        i++;
    }
    
    while(i < len){
        res = res*10 + (str[i] - '0');
        i++;
    }
    
    return res*negsign;
}

int main() {
    // Write C code here
    char* str = NULL;
    int a = a2i(str);
    printf("%d\n", a);

    return 0;
}
