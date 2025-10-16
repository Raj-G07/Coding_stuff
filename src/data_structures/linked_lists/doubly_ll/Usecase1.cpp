// Reverse a Doubly Linked List 

#include "./structure.cpp"

void reversedll(dll* &head){
    dll* temp = NULL;
    dll* curr = head;
    while(curr!=NULL){
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr= curr->prev;
    }
    if(temp!=NULL){
        head= temp->prev;
    }
}

// Time Complexity
// Reversing: O(n) 