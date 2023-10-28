#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
Refer this youtube video: https://www.youtube.com/watch?v=gm8DUJJhmY4&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=34
*/
void PreOrder(BSTNode* RootPtr){
    if(RootPtr == NULL)
        return;
    
    printf("%d\t", RootPtr->val);
    PreOrder(RootPtr->left);
    PreOrder(RootPtr->right);
}

void InOrder(BSTNode* RootPtr){
    if(RootPtr == NULL)
        return;
    
    InOrder(RootPtr->left);
    printf("%d\t", RootPtr->val);
    InOrder(RootPtr->right);    
}

void PostOrder(BSTNode* RootPtr){
    if(RootPtr == NULL)
        return;
    
    PostOrder(RootPtr->left);
    PostOrder(RootPtr->right);  
    printf("%d\t", RootPtr->val);
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
    
    printf("PreOrder Traversal\n");
    PreOrder(root);
    
    printf("\n");
    printf("InOrder Traversal\n");
    InOrder(root);

    printf("\n");
    printf("PostOrder Traversal\n");
    PostOrder(root);    
    
    return 0;
}

/*
PreOrder Traversal
25      15      12      6       8       13      66      52      40      102
InOrder Traversal
6       8       12      13      15      25      40      52      66      102
PostOrder Traversal
8       6       13      12      15      40      52      102     66      25
*/
