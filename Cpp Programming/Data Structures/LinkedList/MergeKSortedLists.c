#include <iostream>
#include <queue>
using namespace std;

/*
Refer the following youtube: https://www.youtube.com/watch?v=0_PSq3j8GrY
*/
// Definition for a singly-linked list node
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Comparator function for the priority queue
struct CompareNodes {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;  // Min-heap based on node values
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    // Priority queue to maintain the minimum node at the top
    priority_queue<ListNode*, vector<ListNode*>, CompareNodes> pq;

    // Push the heads of all k lists into the priority queue
    for (ListNode* node : lists) {
        if (node) {
            pq.push(node);
        }
    }

    ListNode* head = NULL;
    ListNode* tail = NULL;

    // Process nodes in the priority queue
    while (!pq.empty()) {
        ListNode* minNode = pq.top();
        pq.pop();

        if(head == NULL){
            head = minNode;
            tail = minNode;
        }else{
            tail->next = minNode;
            tail = tail->next;   
        }

        
        if (minNode->next) {
            pq.push(minNode->next);
        }
    }

    return head;
}

// Utility function to print the merged list
void printList(ListNode* node) {
    while (node) {
        cout << node->val << " -> ";
        node = node->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // Create example sorted linked lists
    ListNode* a = new ListNode(1);
    a->next = new ListNode(4);
    a->next->next = new ListNode(5);

    ListNode* b = new ListNode(1);
    b->next = new ListNode(3);
    b->next->next = new ListNode(4);

    ListNode* c = new ListNode(2);
    c->next = new ListNode(6);

    vector<ListNode*> lists = {a, b, c};

    // Merge k sorted lists
    ListNode* mergedList = mergeKLists(lists);

    // Print the merged list
    cout << "Merged list: ";
    printList(mergedList);

    // Free allocated memory for the lists
    for (ListNode* list : lists) {
        while (list != nullptr) {
            ListNode* temp = list;
            list = list->next;
            delete temp;
        }
    }

    return 0;
}

/*
Merged list: 1 -> 1 -> 2 -> 3 -> 4 -> 4 -> 5 -> 6 -> NULL
free(): double free detected in tcache 2
*/
