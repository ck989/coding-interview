#include <stdio.h>
#include <stdlib.h>

typedef struct _HashData{
    char key;
    int value;
}HashData;

typedef struct _HashMap{
    int Hash_size;
    HashData** Hash_Table;
}HashMap;

HashMap* HT_SetUp(int size){
    
    HashMap* new_hmap = (HashMap*)malloc(sizeof(HashMap));
    if(new_hmap == NULL){
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);        
    }
    
    new_hmap->Hash_size = size;
    new_hmap->Hash_Table = (HashData**)calloc(size, sizeof(HashData*));
    if(new_hmap->Hash_Table == NULL){
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);        
    } 
    
    return new_hmap;
}

int Hash_Code(int Size, int key){
    return key % Size;
}

void Insert(HashMap* Hmap_handler, char key, int value){
    int Hashnum = Hash_Code(Hmap_handler->Hash_size, key);
    HashData* search_data = NULL;
    
    while(Hmap_handler->Hash_Table[Hashnum] != NULL){
        
        search_data = Hmap_handler->Hash_Table[Hashnum];
        
        if(search_data->key == key)
            search_data->value++;
            return;
            
        ++Hashnum;
        Hashnum %= Hmap_handler->Hash_size;
    }
    
    HashData* new_data = (HashData*)malloc(sizeof(HashData));
    new_data->key = key;
    new_data->value = value;
    Hmap_handler->Hash_Table[Hashnum] = new_data;
}

HashData* Search(HashMap* Hmap_handler, char key){
    int Hashnum = Hash_Code(Hmap_handler->Hash_size, key);
    HashData* search_data = NULL;
    
    while(Hmap_handler->Hash_Table[Hashnum] != NULL){
        
        search_data = Hmap_handler->Hash_Table[Hashnum];
        if(search_data->key == key)
            break;
        
        ++Hashnum;
        Hashnum %= Hmap_handler->Hash_size;
    }
    
    return search_data;
}

int main() {
        
    int hm_size = 16;
    char char_ary[] = {'a', 'b', 'c', 'd', 'e', 'a', 'g', 'k', 'b', 'b'};
    int dummy_val = 1;
    
    int len = sizeof(char_ary)/sizeof(char_ary[0]);
    HashMap* new_hm = HT_SetUp(hm_size);
    for(int i = 0; i < len; i++){
        
        if(Search(new_hm, char_ary[i])){
            Insert(new_hm, char_ary[i], dummy_val);
        }else{
            Insert(new_hm, char_ary[i], dummy_val);
        }
    }
    
    HashData* hm_data = NULL;
    printf("Number of occurance of alphabets:\n");
    for(int i = 0; i < len; i++){
        hm_data = Search(new_hm, char_ary[i]);
        if(hm_data != NULL){
            printf("%c : %d\n", char_ary[i], hm_data->value);
        }
    }
    
    return 0;
}
