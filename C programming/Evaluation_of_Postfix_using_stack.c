#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_ARRAY 5

typedef struct{
    int item[MAX_ARRAY];
    int top;
}Stack_t;

void Push(Stack_t* sp, int val){
    
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

int EvaluatePosfix(char* str){
    int len = strlen(str);
    Stack_t s;
    s.top = -1; //initialize an empty Stack
    
    int res;
    int op1 = 0;
    int op2 = 0;
    
    for(int i = 0; i < len; i++){
        if(str[i] >= '0' && str[i] <= '9'){
            int operand = str[i] - '0';
            Push(&s, operand);
        }else if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/'){
            op2 = top(&s);
            Pop(&s);
            op1 = top(&s);
            Pop(&s);
            
            switch(str[i]){
                case '+':
                    res = op1 + op2;
                    break;
                case '-':
                    res = op1 - op2;
                    break;
                case '*':
                    res = op1 * op2;
                    break;
                case '/':
                    res = op1 / op2;
                    break;
            }
            Push(&s, res);
        }
    }
    
    return top(&s);
}

int main() {
    char str[30];
    
    int res;
    
    printf("Input a postfix expression\n");
    scanf("%s",str);
    
    res = EvaluatePosfix(str);
    
    printf("%d",res);

    return 0;
}

/*
Input a postfix expression
23*54*+9-
17
*/
