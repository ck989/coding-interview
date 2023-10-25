#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_ARRAY 20

typedef struct _Stack{
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

int GetPrecedence(char op)
{
    int weight = -1;
    
    switch(op)
    {
        case '+':
        case '-':
        weight = 1;
        break;
        
        case '*':
        case '/':
        weight = 2;
        break;
    }
    
    return weight;
}

bool HasHigherPrecedence(char top, char curr) //says whether top element has higher prrecedence or not
{
    int op1 = GetPrecedence(top);
    int op2 = GetPrecedence(curr);
    
    if(op1 == op2)
    {
        return false;
    }
    
    return op1>op2?true:false;
}

bool IsOpeningParanthesis(char top)
{
    if(top == '(' || top == '[' || top == '{')
    {
        return true;
    }
    return false;
}

bool IsClosingParanthesis(char top)
{
    if(top == ')' || top == ']' || top == '}')
    {
        return true;
    }
    return false;
}

/*
Refer to this youtube link: https://www.youtube.com/watch?v=vq-nUF0G4fI&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=21
*/
void Infix2Postfix(char* str, char* res){
    int len = strlen(str);
    
    Stack_t s;
    s.top = -1; //init the empty stack
    
    int j = 0;
    for(int i = 0; i < len; i++){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            res[j++] = str[i];
        }else if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/'){
            while(!IsEmpty(&s) && HasHigherPrecedence(top(&s), str[i]) && !IsOpeningParanthesis(top(&s))){
                res[j++] = top(&s);
                Pop(&s);
            }
            Push(&s, str[i]);
        }else if(IsOpeningParanthesis(str[i])){
            Push(&s, str[i]);
        }else if(IsClosingParanthesis(str[i])){
            while(!IsEmpty(&s) && !IsOpeningParanthesis(top(&s))){
                res[j++] = top(&s);
                Pop(&s);
            }
            Pop(&s); //just pop last corresponding opening paranthesis
        }
    }
    
    while(!IsEmpty(&s))
    {
        res[j++] = top(&s);
        Pop(&s);
    }
}

int main()
{
    char str[30];
    
    char res[20];
    
    printf("Input a postfix expression\n");
    scanf("%s",str);
    
    Infix2Postfix(str,res);
    
    printf("%s",res);

    return 0;
}

/*
output:
Input a postfix expression
A+(B*C)
ABC*+
*/
