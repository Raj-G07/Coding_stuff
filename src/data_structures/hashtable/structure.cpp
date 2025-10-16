// Implementing a Hash Table

#include <iostream>
#include <list>
using namespace std;

class HashTable
{
    int capacity;
    list<int> *table;
    HashTable(int size)
    {
        capacity = size;
        table = new list<int>[size];
    }

    int hashFunction(int value)
    {
        return value % capacity;
    }

    void insert(int key)
    {
        int ind = hashFunction(key);
        table[ind].push_back(key);
    }

    void remove(int key)
    {
        int ind = hashFunction(key);
        table[ind].remove(key);
    }

    bool search(int key)
    {
        int ind = hashFunction(key);
        for (auto it : table[ind])
        {
            if (it == key)
                return true;
        }
        return false;
    }

    void display()
    {
        for (int i = 0; i < capacity; i++)
        {
            cout << "Bucket " << i << ": ";
            for (auto it : table[i])
            {
                cout << it << " ";
            }
            cout << endl;
        }
    }
    ~HashTable()
    {
        delete[] table;
    }
};
