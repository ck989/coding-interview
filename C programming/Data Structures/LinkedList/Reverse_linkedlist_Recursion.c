#include <stdio.h>
#include <stdlib.h>

typedef struct _LinkedList{
    int data;
    struct _LinkedList* Next;
}LinkedList;

void InsertList(LinkedList** HeadPtr, int val){
    LinkedList* New_node = (LinkedList*)malloc(sizeof(LinkedList));
    New_node->data = val;
    New_node->Next = NULL;
    
    if(*HeadPtr == NULL){
        *HeadPtr = New_node;
    }else{
       LinkedList* Last_Node = *HeadPtr;
       while(Last_Node->Next != NULL){
           Last_Node = Last_Node->Next;
       }
       Last_Node->Next = New_node;
    }
}

/*
Refer this link: https://www.youtube.com/watch?v=KYH83T4q6Vs&list=PLGvfHSgImk4ZBo2ZsrW6wkM0AOCtX5xb_&index=14
*/
void Reverse_using_recursion(LinkedList** Curr_Node, LinkedList** HeadPtr){
    
    if((*Curr_Node)->Next == NULL){
        *HeadPtr = *Curr_Node;
        return;
    }
    
    Reverse_using_recursion(&(*Curr_Node)->Next, HeadPtr);
    LinkedList* Next_Node = (*Curr_Node)->Next;
    Next_Node->Next = *Curr_Node;
    (*Curr_Node)->Next = NULL;
}

void Print(LinkedList** HeadPtr){
    LinkedList* Curr_Node = *HeadPtr;
    
    while(Curr_Node != NULL){
        printf("%d\t", Curr_Node->data);
        Curr_Node = Curr_Node->Next;
    }
    printf("\n");
}

int main() {
    
    LinkedList* Head = NULL;
    
    InsertList(&Head, 1);
    InsertList(&Head, 2);
    InsertList(&Head, 3);
    InsertList(&Head, 4);
    InsertList(&Head, 5);  
    
    printf("Before\n");
    Print(&Head);
    
    LinkedList* Curr_Node = Head;
    Reverse_using_recursion(&Curr_Node, &Head);
    
    printf("After\n");
    Print(&Head);
    
    return 0;
}
