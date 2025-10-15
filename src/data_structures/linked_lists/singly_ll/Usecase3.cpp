// Find the Middle of the Linked List

#include "./structure.cpp"

Node* findMiddle(Node* head){
    Node* slow = head; 
    Node* fast = head->next;
    while(fast->next != NULL && fast->next->next!=NULL){
        slow = slow ->next; 
        fast = fast ->next->next;
    }
    return slow;
}

// Time Complexity
// Find the Middle: O(n).