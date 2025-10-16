// Stack using Linked List (Dynamic Size)

#include "../src/data_structures/linked_lists/singly_ll/structure.cpp"

class Stack {
    Node* top;
public:
   Stack(){
    top = NULL;
   }
    bool isEmpty(){
     return top == NULL;
    }
    void push(int value){
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }
    int pop(){
        if(isEmpty()){
           cout<<"Stack Underflow"<<endl;
           return -1;
        }
        int value = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return value;
    }
    int peek(){
        if(isEmpty()) return -1; // or throw an exception
        return top->data;
    }
};