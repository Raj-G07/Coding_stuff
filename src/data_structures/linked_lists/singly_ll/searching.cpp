#include "../include/data_structures/linked_lists/singly_ll/searching.h"

bool searchNodell(Node *head, int key)
{
    if (head == NULL)
        return false;
    Node *curr = head;
    while (curr != NULL)
    {
        if (curr->data == key)
        {
            return true;
        }
        curr = curr->next;
    }
    return false;
}