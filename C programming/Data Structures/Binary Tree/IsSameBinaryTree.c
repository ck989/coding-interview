#include <stdio.h>
#include <stdbool.h>

typedef struct _BSTNode{
    int val;
    struct _BSTNode* left;
    struct _BSTNode* right;
}BSTNode;

//Use Preorder Traversal
bool IsSameTree(BSTNode* Root1, BSTNode* Root2){
    if(Root1 == NULL || Root2 == NULL){
        return (Root1 == Root2);
    }    
    
    return ((Root1->val == Root2->val) && IsSameTree(Root1->left, Root2->left) 
            && IsSameTree(Root1->right, Root2->right));
}

int main()
{    
    BSTNode node1 = {1, NULL, NULL};
    BSTNode node2 = {2, NULL, NULL};
    BSTNode node3 = {3, NULL, NULL};
    BSTNode node4 = {4, &node1, &node2};
    BSTNode node5 = {5, NULL, &node3};
    BSTNode root1 = {0, &node4, &node5};

    BSTNode node11 = {1, NULL, NULL};
    BSTNode node21 = {2, NULL, NULL};
    BSTNode node31 = {3, NULL, NULL};
    BSTNode node41 = {4, &node11, &node21};
    BSTNode node51 = {5, NULL, &node31};
    BSTNode root2 = {0, &node41, &node51};

    if(IsSameTree(&root1, &root2)){
        printf("These are same Binary tree\n");
    }else{
        printf("These are not same Binary tree\n");
    }
    
    return 0;
}

/*
These are same Binary tree
*/
