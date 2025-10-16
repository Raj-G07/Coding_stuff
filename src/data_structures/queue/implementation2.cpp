// Queue using Linked List

#include "../src/data_structures/linked_lists/singly_ll/structure.cpp"

class Queue{
    Node* front;
    Node* rear;
public: 
    Queue(){
        front = NULL;
        rear = NULL;
    }
    bool isEmpty(){
        return front == NULL;
    }
    void enqueue(int value){
        Node* newNode = new Node(value);
        if(isEmpty()) {
            front = rear = newNode;
        }else{
            rear->next = newNode;
            rear = newNode;
        }
    }
    int dequeue(){
        if(isEmpty()){
            cout<< "Queue Underflow"<<endl;
            return -1;
        }
        Node* temp = front;
        int x = temp->data;
        front = front->next;
        if(front==NULL) rear=NULL;
        delete temp;
        return x;
    }
    int peek(){
        return isEmpty() ? -1 : front->data;
    }
};