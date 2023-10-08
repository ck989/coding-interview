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

void RemoveDups(LinkedList** HeadPtr){
    HashMap* NewHmap = Set_Hmap(16);
    
    LinkedList* Curr_Node = *HeadPtr;
    LinkedList* Prev_Node = NULL;
    
    while(Curr_Node->Next != NULL){
        if(Search(NewHmap, Curr_Node->data)){
            Prev_Node->Next = Curr_Node->Next;
            free(Curr_Node);
            Curr_Node = Prev_Node->Next;
        }else{
            Insert(NewHmap, Curr_Node->data, (uint64_t)(void*)Curr_Node);
            Prev_Node = Curr_Node;
            Curr_Node = Curr_Node->Next;
        }   
    }
    
    return;
}

int main() {
    
    LinkedList* Head = NULL;
    
    InsertList(&Head, 1);
    InsertList(&Head, 1);
    InsertList(&Head, 2);
    InsertList(&Head, 3);
    InsertList(&Head, 3);
    InsertList(&Head, 4);
    InsertList(&Head, 5);
    InsertList(&Head, 6);
    InsertList(&Head, 3);
    InsertList(&Head, 6);
    InsertList(&Head, 7);
    InsertList(&Head, 8);

    printf("Before\n");
    Print(&Head);
    
    RemoveDups(&Head);
   
    printf("After\n");
    Print(&Head); 
    
    return 0;
}
