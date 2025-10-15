// Rotate a Linked List from Position k

#include "./structure.cpp"

void rotate(Node* head, int k){
    if(head == NULL || k==0) return ;
    Node* curr = head ; int cnt = 1;
    while(curr->next!=NULL && cnt<k){
       curr = curr->next;
       cnt++;
    }
    if(curr->next == NULL) return ;
    Node* newHead = curr->next;
    Node* newTail = curr;
    while(curr->next!=NULL){
        curr= curr->next;
    }
    curr->next= head;
    head = newHead;
    newTail ->next = NULL;
}

// Time Complexity
// Rotate a Linked List: O(n) (to find the k-th node and relink).