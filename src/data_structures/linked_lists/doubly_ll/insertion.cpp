#include "../include/data_structures/linked_lists/doubly_ll/insertion.h"


void insertAtBeginning(dll* head, int data){
    dll* temp = new dll(data);
    temp->next = head;
    if(head!=NULL){
        head->prev= temp;
    }
    head = temp;
}

void insertAtEnd(dll* head, int data){
    dll* temp = new dll(data);
    if(head == NULL){
        head = temp;
        return ;
    }
    dll* curr = head;
    while(curr->next!=NULL){
        curr = curr->next;
    }
    curr->next = temp;
    temp->prev= curr;
}