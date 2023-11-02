/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

// Structure to represent a LinkedList Node
typedef struct _Node{
    int val;
    struct _Node* Next;
}Node;

void Add2List(Node** HeadPtr, int val){
    Node* New_Node = (Node*)malloc(sizeof(Node));
    New_Node->val = val;
    
    if(*HeadPtr == NULL){
        *HeadPtr = New_Node;
        New_Node->Next = NULL;
    }else{
        
        Node* Curr_node = *HeadPtr;
        while (Curr_node->Next != NULL){
            Curr_node = Curr_node->Next;
        }
        Curr_node->Next = New_Node;
        New_Node->Next = NULL;
    }
}

Node* MergeLinkList(const Node* l1, const Node* l2){
    Node* Res_List = NULL;
    
    while(l1 != NULL && l2 != NULL){
        if(l1->val <= l2->val){
            Add2List(&Res_List, l1->val);
            l1 = l1->Next;
        }else{
            Add2List(&Res_List, l2->val);
            l2 = l2->Next;            
        }
    }
    
    if(l1 != NULL){
        Add2List(&Res_List, l1->val);
        l1 = l1->Next;        
    }
    
    if(l2 != NULL){
        Add2List(&Res_List, l2->val);
        l2 = l2->Next;        
    }
    
    return Res_List;
}

void Print_LinkList(Node* HeadPtr){
    Node* Curr_node = HeadPtr;
    while(Curr_node != NULL){
        printf("%d\t", Curr_node->val);
        Curr_node = Curr_node->Next;
    }
    printf("\n");
}

int main()
{
    Node* Head1 = NULL;
    Node* Head2 = NULL;
    
    //linklist 1
    Add2List(&Head1, 1);
    Add2List(&Head1, 1);
    Add2List(&Head1, 6);
    Add2List(&Head1, 7);
    Add2List(&Head1, 8);
    printf("Printing LinkedList1...\n");
    Print_LinkList(Head1);
    
    Add2List(&Head2, 3);
    Add2List(&Head2, 4);
    Add2List(&Head2, 9);
    printf("Printing LinkedList2...\n");
    Print_LinkList(Head2);
    
    Node* Res_List = MergeLinkList(Head1, Head2);
    printf("Printing LinkedList2...\n");
    Print_LinkList(Res_List);    
    return 0;
}

/*
Printing LinkedList1...
1       1       6       7       8
Printing LinkedList2...
3       4       9
Printing LinkedList2...
1       1       3       4       6       7       8       9
  */
