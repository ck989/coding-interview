/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

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

LinkedList* GetNode(LinkedList* HeadPtr, int val){
    LinkedList* Curr_Node = HeadPtr;
    while(Curr_Node->data != val){
        Curr_Node = Curr_Node->Next;
    }
    return Curr_Node;
}

LinkedList* GetPrevNode(LinkedList* HeadPtr, int val){
    LinkedList* Curr_Node = HeadPtr;
    LinkedList* Prev_Node = NULL;
    while(Curr_Node->data != val){
        Prev_Node = Curr_Node;
        Curr_Node = Curr_Node->Next;
    }
    return Prev_Node;
}

//Refer to this youtube link: https://www.youtube.com/watch?v=RF_M9tX4Eag
void Reverse_SubList(LinkedList** HeadPtr, int val1, int val2){
    
    //1. get the essential nodes
    LinkedList* Left_Prev_Node = GetPrevNode(*HeadPtr, val1);
    LinkedList* Curr_Node = GetNode(*HeadPtr, val1);
    LinkedList* Node2 = GetNode(*HeadPtr, val2);
     
    //2. Perform reversing by declaring the new prev_node = NULL 
    LinkedList* Next_Node;
    LinkedList* temp_Node = Curr_Node;
    LinkedList* Prev_node = NULL; 
    
    while(Curr_Node != Node2->Next){
        Next_Node = Curr_Node->Next;
        Curr_Node->Next = Prev_node;
        Prev_node = Curr_Node;
        Curr_Node = Next_Node;
    }
    
    //3. Update pointers after reversing the sublists
    Left_Prev_Node->Next = Prev_node;
    temp_Node->Next = Node2;
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
    
    Reverse_SubList(&Head, 3, 7);
    
    printf("After\n");
    Print(&Head);
    
    return 0;
}
