#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_ARRAY 5

typedef struct{
    char item[MAX_ARRAY];
    int top;
}Stack_t ;

void Push(Stack_t* sp, char val){
    
    if(sp->top == MAX_ARRAY - 1){
        printf("Stack overflow\n");
        return;
    }
    
    sp->top++;
    sp->item[sp->top] = val;
}

void Pop(Stack_t* sp){
    if(sp->top == -1){
        printf("Stack underflow\n");
        return;
    }
    
    sp->top--;
}

int top(Stack_t* sp){
    return sp->item[sp->top];
}

bool IsEmpty(Stack_t* sp){
    
    if(sp->top == -1)
        return true;
    
    return false;
}

bool IsMatchingCounterPart(char open, char close){
    if(open == '(' && close == ')') return true;
    else if(open == '[' && close == ']') return true;
    else if(open == '{' && close == '}') return true;
    
    return false;
}

bool Balanced_Parenthesis(char* str){
    int len = strlen(str);
    
    Stack_t s;
    s.top = -1; //initialize empty stack
    for(int i = 0; i < len; i++){
        if(str[i] == '(' || str[i] == '[' || str[i] == '{'){
            Push(&s, str[i]);
        }else if(str[i] == ')' || str[i] == ']' || str[i] == '}'){
            if(IsEmpty(&s) || !IsMatchingCounterPart(top(&s), str[i])){
                return false;
            }else{
                Pop(&s); 
            }
        }
    }
    
    return IsEmpty(&s);
}

int main() {
    char str[20];
    printf("Input the parenthesis expression\n");
    scanf("%s",str);
    
    if(Balanced_Parenthesis(str))
    {
        printf("parenthesis are balanced\n");
    }else{
        printf("Prenthesis are not balanced\n");
    }
}
