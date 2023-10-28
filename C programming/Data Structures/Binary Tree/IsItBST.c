#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

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

bool IsBSTUtil(BSTNode* Root, int minval, int maxval){
    if(Root == NULL) return true;
    
    if(Root->val > minval && Root->val < maxval
       && IsBSTUtil(Root->left, minval, Root->val)
       && IsBSTUtil(Root->right, Root->val, maxval))
       return true;
    
    return false;
} 

bool IsBinarySerachTree(BSTNode* Root){
    return IsBSTUtil(Root, INT_MIN, INT_MAX);
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
    
    if(IsBinarySerachTree(root)){
        printf("It is a Binary search tree\n");
    }else{
        printf("It is not a Binary search tree\n");
    }
}
/*
It is a Binary search tree
*/
