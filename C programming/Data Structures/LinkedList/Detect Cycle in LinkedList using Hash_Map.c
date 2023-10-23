#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct _LinkedList{
    int data;
    struct _LinkedList* Next;
}LinkedList;

typedef struct _DataItem{
    int key;
    uint64_t value;
}DataItem;

typedef struct _HashMap{
    int HashSize;
    DataItem** HashTable;
}HashMap;

int HashCode(int size, int key){
    return key % size; 
}

HashMap* Set_Hmap(int size){
    HashMap* new_hmap = (HashMap*)malloc(sizeof(HashMap));
    if(new_hmap == NULL){
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);         
    }
    
    new_hmap->HashSize = size;
    new_hmap->HashTable = (DataItem**)calloc(size, sizeof(DataItem*));
    if(new_hmap->HashTable == NULL){
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);        
    } 
    
    return new_hmap;
}

void Insert(HashMap* Hash_Handler, int key, uint64_t value){
    int HashNum = HashCode(Hash_Handler->HashSize, key);
    
    while(Hash_Handler->HashTable[HashNum] != NULL){
        ++HashNum;
        HashNum %= Hash_Handler->HashSize;
    }
    
    DataItem* new_data = (DataItem*)malloc(sizeof(DataItem));
    new_data->key = key;
    new_data->value = value;
    Hash_Handler->HashTable[HashNum] = new_data;
}

DataItem* Search(HashMap* Hmap_handler, int key){
    int Hashnum = HashCode(Hmap_handler->HashSize, key);
    DataItem* search_data = NULL;
    
    while(Hmap_handler->HashTable[Hashnum] != NULL){
        search_data = Hmap_handler->HashTable[Hashnum];
        if(search_data->key == key)
            break;
        
        ++Hashnum;
        Hashnum %= Hmap_handler->HashSize;
    }
    
    return search_data;
}

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

LinkedList* HasCycle(LinkedList* HeadPtr, int len){
    HashMap* NewHmap = Set_Hmap(16);
    LinkedList* Curr_Node = HeadPtr;
    
    for(int i = 0; i < len; i++){
        if(Search(NewHmap, Curr_Node->data))
            return Curr_Node;
        else
            Insert(NewHmap, Curr_Node->data, (uint64_t)(void*)Curr_Node); 
       
        Curr_Node = Curr_Node->Next;
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
    Head->Next->Next->Next->Next->Next = Head->Next->Next ; //create a cycle
    int len = 9;
    
    LinkedList* Ptr = HasCycle(Head, len);
    if(Ptr == NULL)
        printf("No cycle detected\n");
    else
        printf("Cycle found for %d\n", Ptr->data);
        
    return 0;
}
