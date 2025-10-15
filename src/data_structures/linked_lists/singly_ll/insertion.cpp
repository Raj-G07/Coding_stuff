#include "../include/data_structures/linked_lists/singly_ll/insertion.h"

void insertAtBeginningll(Node* head,int data){
    Node* temp = new Node(data);
   if(head == NULL) {
    head = temp;
    return ;
   }
   temp->next = head; 
   head = temp;
}

void insertAtEndll(Node* head, int data) {
     Node* temp = new Node(data);
   if(head == NULL) {
    head = temp;
    return ;
   }
   Node* curr = head;
   while(curr->next!=NULL){
    curr = curr ->next;
   } 
   curr->next = temp;
}