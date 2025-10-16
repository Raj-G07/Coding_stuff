#include<iostream>
using namespace std;

class dll {
public:
    int data;
    dll* next;
    dll* prev;
    dll(int val){
        this->data=val;
        this->next=NULL;
        this->prev=NULL;
    }
};