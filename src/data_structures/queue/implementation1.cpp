// Queue: A linear data structure that follows a First In, First Out (FIFO) principle, where the first element added is the first one removed.
// Queue using Array (Fixed Size)
#include <iostream>
using namespace std;
class Queue
{
    int arr[100];
    int front, rear;

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }
    bool isFull()
    {
        return rear == 99;
    }
    bool isEmpty()
    {
        return front == -1 || front > rear;
    }
    void enqueue(int value)
    {
        if (isFull())
        {
            cout << "Queue Overflow" << endl;
            return;
        }
        if (front == -1)
            front = 0; // Initialize front on first enqueue
        arr[++rear] = value;
    }
    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow" << endl;
            return -1;
        }
        int data = arr[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
            front++;
        return data;
    }
    int peek()
    {
        return isEmpty() ? -1 : arr[front];
    }
};

// Queue Operations (Push, Pop, Enqueue, Dequeue): O(1)