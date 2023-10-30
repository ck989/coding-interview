#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition for a singly-linked list node
struct ListNode {
    int val;
    struct ListNode* next;
};

// Structure to represent a node and its list index
struct NodeWithIndex {
    struct ListNode* node;
    int index;
};

// Min heap structure
struct MinHeap {
    struct NodeWithIndex* array;
    int size;
};

// Function to initialize the heap
struct MinHeap* createMinHeap(int capacity) {
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->array = (struct NodeWithIndex*)calloc(capacity, sizeof(struct NodeWithIndex));
    return minHeap;
}

// Function to swap two nodes in the heap
void swapNodes(struct NodeWithIndex* a, struct NodeWithIndex* b) {
    struct NodeWithIndex temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify function to maintain the min-heap property
void heapify(struct MinHeap* minHeap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < minHeap->size && minHeap->array[left].node->val < minHeap->array[smallest].node->val) {
        smallest = left;
    }

    if (right < minHeap->size && minHeap->array[right].node->val < minHeap->array[smallest].node->val) {
        smallest = right;
    }

    if (smallest != index) {
        swapNodes(&minHeap->array[smallest], &minHeap->array[index]);
        heapify(minHeap, smallest);
    }
}

// Function to build the min heap
void buildHeap(struct MinHeap* minHeap) {
    int n = minHeap->size - 1;
    int i;
    for (i = (n - 1) / 2; i >= 0; --i) {
        heapify(minHeap, i);
    }
}

// Function to merge k sorted lists
struct ListNode* mergeKLists(struct ListNode* lists[], int k) {
    struct ListNode* mergedList = NULL;
    struct ListNode* tail = NULL;

    // Create a min heap and initialize it with heads of all k lists
    struct MinHeap* minHeap = createMinHeap(k);
    for (int i = 0; i < k; ++i) {
        if (lists[i] != NULL) {
            minHeap->array[minHeap->size].node = lists[i];
            minHeap->array[minHeap->size].index = i;
            minHeap->size++;
        }
    }

    // Build the min heap based on the initial values
    buildHeap(minHeap);

    // Merge the lists
    while (minHeap->size > 0) {
        struct NodeWithIndex root = minHeap->array[0];
        if (root.node->next != NULL) {
            minHeap->array[0].node = root.node->next;
        } else {
            // If the list has been fully processed, replace the root with the last node in the heap
            minHeap->array[0] = minHeap->array[minHeap->size - 1];
            minHeap->size--;
        }

        heapify(minHeap, 0);

        // Append the processed node to the merged list
        if (mergedList == NULL) {
            mergedList = root.node;
            tail = root.node;
        } else {
            tail->next = root.node;
            tail = tail->next;
        }
        tail->next = NULL;
    }

    free(minHeap->array);
    free(minHeap);

    return mergedList;
}

// Utility function to print the merged list
void printList(struct ListNode* node) {
    while (node) {
        printf("%d -> ", node->val);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    // Create example sorted linked lists
    struct ListNode* a = (struct ListNode*)malloc(sizeof(struct ListNode));
    a->val = 1;
    a->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    a->next->val = 4;
    a->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    a->next->next->val = 5;
    a->next->next->next = NULL;

    struct ListNode* b = (struct ListNode*)malloc(sizeof(struct ListNode));
    b->val = 1;
    b->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    b->next->val = 3;
    b->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    b->next->next->val = 4;
    b->next->next->next = NULL;

    struct ListNode* c = (struct ListNode*)malloc(sizeof(struct ListNode));
    c->val = 2;
    c->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    c->next->val = 6;
    c->next->next = NULL;

    struct ListNode* lists[] = {a, b, c};

    int k = 3; // Number of linked lists

    // Merge k sorted lists
    struct ListNode* mergedList = mergeKLists(lists, k);

    // Print the merged list
    printf("Merged list: ");
    printList(mergedList);

    // Free allocated memory for the lists
    free(a->next->next);
    free(a->next);
    free(a);
    free(b->next->next);
    free(b->next);
    free(b);
    free(c->next);
    free(c);

    return 0;
}

/*
Merged list: 1 -> 1 -> 2 -> 3 -> 4 -> 4 -> 5 -> 6 -> NULL
*/
