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

void Reverse(LinkedList** HeadPtr){
    LinkedList* Prev_Node = NULL;
    LinkedList* Curr_Node = *HeadPtr;
    LinkedList* Next_Node;
    
    while(Curr_Node != NULL){
        Next_Node = Curr_Node->Next;
        Curr_Node->Next = Prev_Node;
        Prev_Node = Curr_Node;
        Curr_Node = Next_Node;
    }
    *HeadPtr = Prev_Node;
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
    InsertList(&Head, 6);
    InsertList(&Head, 7);
    InsertList(&Head, 8);
    
    printf("Before\n");
    Print(&Head);
    
    Reverse(&Head);
    
    printf("After\n");
    Print(&Head);
    
    return 0;
}
