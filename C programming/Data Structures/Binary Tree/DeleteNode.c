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

BSTNode* FindMin(BSTNode* RootPtr){
    if(RootPtr == NULL) return NULL;
    
    while(RootPtr->left != NULL){
        RootPtr = RootPtr->left;
    }
    
    return RootPtr;
}

void InOrder(BSTNode* RootPtr){
    if(RootPtr == NULL)
        return;
    
    InOrder(RootPtr->left);
    printf("%d\t", RootPtr->val);
    InOrder(RootPtr->right);    
}

void DeleteNode(BSTNode** RootPtr, int data){
    if(*RootPtr == NULL) return;
    else if(data < (*RootPtr)->val) DeleteNode(&(*RootPtr)->left, data);
    else if(data > (*RootPtr)->val) DeleteNode(&(*RootPtr)->right, data);
    else{
        // No child
        if((*RootPtr)->left == NULL && (*RootPtr)->right == NULL){
            free(*RootPtr);
            *RootPtr = NULL;
        }
        //one child
        else if((*RootPtr)->left == NULL){
            BSTNode* temp = *RootPtr;
            *RootPtr = (*RootPtr)->right;
            free(temp);
        }
        else if((*RootPtr)->right == NULL){
            BSTNode* temp = *RootPtr;
            *RootPtr = (*RootPtr)->left;
            free(temp);            
        }
        else{
            BSTNode* temp = FindMin((*RootPtr)->right);
            (*RootPtr)->val = temp->val;
            DeleteNode(&(*RootPtr)->right, temp->val);
        }
    }
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
    
    printf("Before:\n");
    InOrder(root);
    
    DeleteNode(&root, 66);
    
    printf("\nAfter:\n");
    InOrder(root);
}

/*
output:
Before:
6       8       12      13      15      25      40      52      66      102
After:
6       8       12      13      15      25      40      52      102
*/
