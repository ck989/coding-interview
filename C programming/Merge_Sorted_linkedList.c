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

void Merge_Sorted_LinkList(Node** l1, Node** l2, Node** Final_head){
    
    Node* S = NULL;
    
    if((*l1)->val < (*l2)->val){
        S = *l1;
        *l1 = S->Next;
    }else{
        S = *l2;
        *l2 = S->Next;
    }
    
    *Final_head = S;
    
    while((*l1 != NULL) && (*l2 != NULL)){
        
        if((*l1)->val <= (*l2)->val){
            S->Next = *l1;
            S = *l1;
            *l1 = S->Next;
        }else{
            S->Next = *l2;
            S = *l2;
            *l2 = S->Next;    
        }
    }
    
    if(*l1 != NULL){
        S->Next = *l1;
    }
    
    if(*l2 != NULL){
        S->Next = *l2;
    }
}

void Print_LinkList(Node** HeadPtr){
    Node* Curr_node = *HeadPtr;
    while(Curr_node != NULL){
        printf("%d\t", Curr_node->val);
        Curr_node = Curr_node->Next;
    }
    printf("\n");
}

int main() {
    
    Node* Head1 = NULL;
    Node* Head2 = NULL;
    
    //linklist 1
    Add2List(&Head1, 1);
    Add2List(&Head1, 1);
    Add2List(&Head1, 6);
    Add2List(&Head1, 7);
    Add2List(&Head1, 8);
    printf("Printing LinkedList1...\n");
    Print_LinkList(&Head1);
    
    Add2List(&Head2, 3);
    Add2List(&Head2, 4);
    Add2List(&Head2, 9);
    printf("Printing LinkedList2...\n");
    Print_LinkList(&Head2);
    
    Node* Final_head = Head1;
    Merge_Sorted_LinkList(&Head1, &Head2, &Final_head);
    printf("Merged LinkedList...\n");
    Print_LinkList(&Final_head);
    
    return 0;
}
