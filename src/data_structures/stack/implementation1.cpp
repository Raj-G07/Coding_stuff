// Stack using Array (Fixed Size)
#include<iostream>
using namespace std;

class Stack {
    int arr[100];
    int top;
public:
    Stack(){
        top = -1;
    }
    bool isFull(){
        return top == 99;
    }
    bool isEmpty(){
        return top == -1;
    }
    void push(int value){
        if(isFull()){
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top] = value;
    }
    int pop(){
        if(isEmpty()){
            cout << "Stack Underflow" << endl;
            return -1; // or throw an exception
        }
        return arr[top--];
    }
    int peek(){
        if(isEmpty()) return -1; // or throw an exception
        return arr[top];
    }
    int getSize(){  
        return top + 1;
    }
};