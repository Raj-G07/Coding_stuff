#include "../include/data_structures/linked_lists/doubly_ll/deletion.h"

void deleteNode(dll *head, dll *delNode)
{
    if (head == NULL || delNode == NULL)
        return;
    if (head == delNode)
    {
        head = delNode->next;
    }
    if (delNode->next != nullptr)
    {
        delNode->next->prev = delNode->prev;
    }
    if (delNode->prev != nullptr)
    {
        delNode->prev->next = delNode->next;
    }
    delete delNode;
}