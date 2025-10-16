#include "../include/data_structures/linked_lists/doubly_ll/traversal.h"



void printListForward(dll* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<"NULL"<<endl;
}

void printListBackWard(dll* head){
     while(head!=NULL){
        cout<<head->data<<" ";
        head = head->prev;
    }
    cout<<"NULL"<<endl;
}