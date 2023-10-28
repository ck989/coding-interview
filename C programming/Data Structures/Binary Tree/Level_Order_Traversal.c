#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _BSTNode{
    int val;
    struct _BSTNode* left;
    struct _BSTNode* right;
}BSTNode;

typedef struct _Node{
    void* Qnode;
    struct _Node* Next;
}Node;

typedef struct _Queue{
   Node* front;
   Node* rear;
}Queue_t;

void Enqueue(Queue_t* q, void* nodeptr){
    Node* LlistNode = (Node*)malloc(sizeof(Node));
    LlistNode->Qnode = nodeptr;
    LlistNode->Next = NULL;
    
    if(q->front == NULL && q->rear == NULL){
       q->front = q->rear = LlistNode;
    }else{
        q->rear->Next = LlistNode;
        q->rear = LlistNode;
    }
}

void Dequeue(Queue_t* q){
    if(q->front == NULL){
        printf("Empty queue..\n");
        return;
    }
        
    Node* Curr_Node = q->front;
    
    q->front = Curr_Node->Next;
    free(Curr_Node);
}

void* Front(Queue_t* q){
    if(q->front == NULL) return NULL;
    
    return q->front->Qnode;
}

bool IsEmpty(Queue_t* q){
    if(q->front == NULL){
        q->rear = NULL;
        return true;
    } 
    
    return false;
}

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
Algorithm uses Queue to do level order traversal.
Refer the following youtube video: https://www.youtube.com/watch?v=86g8jAQug04&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=33
*/
void LevelOrderTraversal(BSTNode* RootPtr){
    Queue_t q;
    q.front = NULL;
    q.rear = NULL;
    
    Enqueue(&q, (void*)RootPtr);
    
    printf("LevelOrderTraversal:\n");
    while(!IsEmpty(&q)){
        BSTNode* curr_rtnode = (BSTNode*)Front(&q);
        if(curr_rtnode == NULL){
            printf("root node is null, exiting..\n");
            return;
        }
        
        printf("%d\t",curr_rtnode->val);
        if(curr_rtnode->left) Enqueue(&q, curr_rtnode->left);
        if(curr_rtnode->right) Enqueue(&q, curr_rtnode->right);
        
        Dequeue(&q);
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
    
    LevelOrderTraversal(root);
    return 0;
}

/*
output:
LevelOrderTraversal:
25      15      66      12      52      102     6       13      40      8
*/
