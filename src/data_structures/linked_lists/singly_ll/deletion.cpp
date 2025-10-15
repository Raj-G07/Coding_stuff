#include "../include/data_structures/linked_lists/singly_ll/deletion.h"

void deleteNodell(Node *head, int data)
{
    if (head == NULL)
        return;
    if (head->data = data)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node *curr = head;
    while (curr->next != NULL && curr->next->data != data)
    {
        curr = curr->next;
    }
    if (curr->next == NULL)
        return;
    Node *temp = curr->next;
    curr->next = curr->next->next;
    delete temp;
}