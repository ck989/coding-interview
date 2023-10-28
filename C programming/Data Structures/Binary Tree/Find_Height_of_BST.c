#include <stdio.h>
#include <stdlib.h>

typedef struct _BSTNode{
    int val;
    struct _BSTNode* left;
    struct _BSTNode* right;
}BSTNode;

void Insert(BSTNode** RootPtr, int data){
    if(*RootPtr == NULL){
        BSTNode* New_Node = (BSTNode*)malloc(sizeof(BSTNode));
        New_Node->val = data;
        New_Node->left = NULL;
        New_Node->right = NULL;
        
        *RootPtr = New_Node;
    }else if(data <= (*RootPtr)->val){
        Insert(&(*RootPtr)->left, data);
    }else{
        Insert(&(*RootPtr)->right, data);
    }
}

/*
Refer youtube vedio: https://www.youtube.com/watch?v=_O-mK2g_jhI
*/
int FindHeight(BSTNode** RootPtr){
    
    if(*RootPtr == NULL)
        return 0;
    
    int left_height = FindHeight(&(*RootPtr)->left);
    int right_height = FindHeight(&(*RootPtr)->right);
    
    return (left_height > right_height)?(1 + left_height):(1 + right_height);
}

int main()
{
    BSTNode* root = NULL;
    
    Insert(&root, 25);
    Insert(&root, 15);
    Insert(&root, 12);
    Insert(&root, 66);
    Insert(&root, 52);
    Insert(&root, 6);
    Insert(&root, 40);
    Insert(&root, 8);
    Insert(&root, 13);
    Insert(&root, 102);
    
    int height = FindHeight(&root);
    printf("height of BST: %d\n", height);
    return 0;
}

/*
output:
height of BST: 5
*/
