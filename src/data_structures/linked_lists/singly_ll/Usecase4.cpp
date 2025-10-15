// Detecting a Cycle in ll

#include "./structure.cpp"

bool hasCyclell(Node* head){
    Node* slow= head;
    Node* fast = head->next;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return true;
    }
    return false;
}

// Time-complexity 
// Cycle Detection: O(n).