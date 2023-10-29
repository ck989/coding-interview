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

BSTNode* Find(BSTNode*root, int data) {
	if(root == NULL) return NULL;
	else if(root->val == data) return root;
	else if(root->val < data) return Find(root->right,data);
	else return Find(root->left,data);
}

/*
Refer the following youtube video: https://www.youtube.com/watch?v=5cPbNCrdotA&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=37
*/
BSTNode* Get_succesor(BSTNode* RootPtr, int data){

    BSTNode* current = Find(RootPtr,data);
	if(current == NULL) return NULL;
	if(current->right != NULL) {  //Case 1: Node has right subtree
		return FindMin(current->right); // O(h)
	}
	else {   //Case 2: No right subtree  - O(h)
		BSTNode* successor = NULL;
		BSTNode* ancestor = RootPtr;
		while(ancestor != current) {
			if(current->val < ancestor->val) {
				successor = ancestor; // so far this is the deepest node for which current node is in left
				ancestor = ancestor->left;
			}
			else
				ancestor = ancestor->right;
		}
		return successor;
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
    
    BSTNode* successor_node = Get_succesor(root, 13);
    printf("successor_node is %d\n", successor_node->val);
}

/*
successor_node is 15
*/
*/
