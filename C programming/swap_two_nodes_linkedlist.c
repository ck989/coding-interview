#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

void Print(LinkedList** HeadPtr){
    LinkedList* Curr_Node = *HeadPtr;
    
    while(Curr_Node != NULL){
        printf("%d\t", Curr_Node->data);
        Curr_Node = Curr_Node->Next;
    }
    printf("\n");
}

bool Swap_Nodes(LinkedList** HeadPtr, int val1, int val2){
    LinkedList* Node1 = *HeadPtr;
    LinkedList* Prev_Node1 = NULL;
    LinkedList* Node2 = *HeadPtr;
    LinkedList* Prev_Node2 = NULL;
    
    while(Node1 != NULL){
        if(Node1->data == val1)
            break;
        
        Prev_Node1 = Node1;
        Node1 = Node1->Next;
    }
    
    while(Node2 != NULL){
        if(Node2->data == val2)
            break;
        
        Prev_Node2 = Node2;
        Node2 = Node2->Next;
    }
    
    if((Node1 == NULL) || (Node2 == NULL) || (Node1 == Node2)){
        printf("ERROR: Cannot perfrom swap operation..\n");
        return false;
    }
    
    //swapping beings
    LinkedList* temp_node;
    
    if((Node1 == *HeadPtr) || (Node2 == *HeadPtr)){ //if either node1 or node2 is head node
        if(Node1 == *HeadPtr){
            temp_node = Node1->Next;
            Prev_Node2->Next = Node1;
            Node1->Next = Node2->Next;
            *HeadPtr = Node2;
        }else{
            temp_node = Node2->Next;
            Prev_Node1->Next = Node2;
            Node2->Next = Node1->Next;
            *HeadPtr = Node1;
        }
        (*HeadPtr)->Next = temp_node; //asisgn back temp node addr to Head node
    }else if((Node1 == Prev_Node2) || (Node2 == Prev_Node1)){ //when there is swapping between two adjacent nodes
        if(Node1 == Prev_Node2){
            temp_node = Node2->Next;
            Prev_Node1->Next = Node2;
            Node2->Next = Node1;
            Node1->Next = temp_node;
        }else{
            temp_node = Node1->Next;
            Prev_Node2->Next = Node1;
            Node1->Next = Node2;
            Node2->Next = temp_node;            
        }
    }else{ //if the swapping between two different nodes which are not adjacent.
        temp_node = Node2->Next; //temp node stores node2's next address for a while
        Prev_Node1->Next = Node2;
        Node2->Next = Node1->Next;
        Prev_Node2->Next = Node1;
        Node1->Next = temp_node;
    }
    
    return true;
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
    
    bool swap_flag = Swap_Nodes(&Head, 4, 8);    
    
    if(swap_flag){
        printf("After\n");
        Print(&Head);        
    }
    
    return 0;
}
