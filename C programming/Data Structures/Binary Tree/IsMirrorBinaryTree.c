#include <stdio.h>
#include <stdbool.h>

typedef struct _BSTNode{
    int val;
    struct _BSTNode* left;
    struct _BSTNode* right;
}BSTNode;

//Use Preorder Traversal
bool IsMirrorTree(BSTNode* Root1, BSTNode* Root2){
    if(Root1 == NULL || Root2 == NULL){
        return (Root1 == Root2);
    }    
    
    return ((Root1->val == Root2->val) && IsMirrorTree(Root1->left, Root2->right) 
            && IsMirrorTree(Root1->right, Root2->left));
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
    BSTNode node41 = {4, &node21, &node11};
    BSTNode node51 = {5, &node31, NULL};
    BSTNode root2 = {0, &node51, &node41};

    if(IsMirrorTree(&root1, &root2)){
        printf("These are Mirror Binary tree\n");
    }else{
        printf("These are not Mirror Binary tree\n");
    }
    
    return 0;
}

/*
These are Mirror Binary tree
*/
