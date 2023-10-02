#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Add_Slash(char* str)
{
    int i;
    int j = 0;
    int n = strlen(str);
    char* str1 = malloc(sizeof(char)*n*2); //dynamically allocating the memory twice the char size
    
    for(i = 0;i < n; i++)
    {
        if(str[i] == '<' || str[i] == '>' || str[i] == '\\') // check for '<', '>', '/'
        {
            str1[j++] = '\\';   // if '/' found place 
        }
        str1[j++] = str[i];
    }
    
    strcpy(str,str1); // copying to the original string
    free(str1);// free the allocated string
    
}

int main()
{
    char str[20] = "<hello> world \\"; //inputting a stting
    
    printf("before adding the slash\n"); //print before adding the slash
    printf("%s\n",str);
    
    Add_Slash(str);
    
    printf("after adding the slash\n"); //print after adding the slah
    printf("%s\n",str);

    return 0;
}
