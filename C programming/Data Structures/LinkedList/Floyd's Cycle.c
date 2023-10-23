#include <stdio.h>
#include <stdlib.h>

typedef struct _LinkedList{
    int data;
    struct _LinkedList* Next;
}LinkedList;

LinkedList* New_Node(int val){
    LinkedList* New_Node = (LinkedList*)malloc(sizeof(LinkedList));
    if(New_Node == NULL){
        printf("Out of memory resources\n");
        return NULL;
    }
    
    New_Node->data = val;
    New_Node->Next = NULL;
    
    return New_Node;
}

LinkedList* FloydCycle(LinkedList* HeadPtr){
    if(!HeadPtr || !HeadPtr->Next)
        return NULL;
        
    LinkedList* slow = HeadPtr;
    LinkedList* fast = HeadPtr;
    
    while(fast->Next && fast->Next->Next){
        slow = slow->Next;
        fast = fast->Next->Next;
        
        if(fast == slow)
            return slow;
    }
    
    return NULL;
}

int main() {
    
    LinkedList* Head = New_Node(5);
    Head->Next = New_Node(7);
    Head->Next->Next = New_Node(2);
    Head->Next->Next->Next = New_Node(4);
    Head->Next->Next->Next->Next = New_Node(9);
    Head->Next->Next->Next->Next->Next = New_Node(20);
    Head->Next->Next->Next->Next->Next = Head->Next->Next; //create a cycle
    
    LinkedList* Ptr = FloydCycle(Head);
    if(Ptr == NULL)
        printf("No cycle detected\n");
    else
        printf("Cycle found for %d\n", Ptr->data);
        
    return 0;
}
