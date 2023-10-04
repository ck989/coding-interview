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

void Reverse(Node** HeadPtr){
    
    Node* Prev_Node = NULL;
    Node* Curr_Node = *HeadPtr;
    Node* Next_Node;
    
    while(Curr_Node != NULL){
        Next_Node = Curr_Node->Next;
        Curr_Node->Next = Prev_Node;
        Prev_Node = Curr_Node;
        Curr_Node = Next_Node;
    }
    *HeadPtr = Prev_Node;
}

void AddLinkList(Node** l1, Node** l2, Node** Result_Head){
    int carry = 0, val1 = 0, val2 = 0, Rem = 0, DivBy10 = 0, Res = 0;
    Node* Res_Head = *Result_Head;
    
    while((*l1 != NULL) && (*l2 != NULL)){
        val1 = (*l1)->val;
        val2 = (*l2)->val;
        Res = val1 + val2 + carry;
        
        DivBy10 = Res/10;
        if(DivBy10 != 0){
            carry = DivBy10;
            Rem = Res % 10;
            Add2List(&Res_Head, Rem);
        }else{
            carry = DivBy10;
            Add2List(&Res_Head, Res);
        }
        (*l1) = (*l1)->Next;
        (*l2) = (*l2)->Next;
    }
    
    if(*l1 != NULL){
        while (*l1 != NULL){
            if(carry != 0){
                val1 = (*l1)->val;
                Res = val1 + carry;
                DivBy10 = Res/10;
                if(DivBy10 != 0){
                    carry = DivBy10;
                    Rem = Res % 10;
                    Add2List(&Res_Head, Rem);
                }else{
                    carry = DivBy10;
                    Add2List(&Res_Head, Res);
                }             
            }else{
                val1 = (*l1)->val;
                Add2List(&Res_Head, val1);
            }
            (*l1) = (*l1)->Next;
        }
    }
    
    if(*l2 != NULL){
        while (*l2 != NULL){
            if(carry != 0){
                val2 = (*l2)->val;
                Res = val2 + carry;
                DivBy10 = Res/10;
                if(DivBy10 != 0){
                    carry = DivBy10;
                    Rem = Res % 10;
                    Add2List(&Res_Head, Rem);
                }else{
                    carry = DivBy10;
                    Add2List(&Res_Head, Res);
                }
            }else{
                val2 = (*l2)->val;
                Add2List(&Res_Head, val2);
            }
            (*l2) = (*l2)->Next;
        }
    }
    
    if(carry != 0){
        Add2List(&Res_Head, carry);
    }
    
    *Result_Head = Res_Head;
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
    printf("LinkedList1:\n");
    Print_LinkList(&Head1);
    
    Reverse(&Head1);
    
    Add2List(&Head2, 3);
    Add2List(&Head2, 4);
    Add2List(&Head2, 9);
    // Add2List(&Head2, 7);
    // Add2List(&Head2, 8);
    printf("LinkedList2:\n");
    Print_LinkList(&Head2);
    
    Reverse(&Head2);
    
    Node* Result_Head = NULL;
    AddLinkList(&Head1, &Head2, &Result_Head);
    
    Reverse(&Result_Head);
    printf("Addition Result:\n");
    Print_LinkList(&Result_Head);
    
    return 0;
}
