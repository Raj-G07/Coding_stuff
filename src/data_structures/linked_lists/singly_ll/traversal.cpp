#include "../include/data_structures/linked_lists/singly_ll/traversal.h"

void printListll(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout<< "NULL" << endl;
}