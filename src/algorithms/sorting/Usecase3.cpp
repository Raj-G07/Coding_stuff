//  Merge Sort in Linked Lists

#include <iostream>
#include "../../data_structures/linked_lists/singly_ll/structure.cpp"
#include "../../data_structures/linked_lists/singly_ll/Usecase3.cpp"
using namespace std;

Node *merge(Node *left, Node *right)
{
    if (left == NULL)
        return right;
    if (right == NULL)
        return left;

    if (left->data < right->data)
    {
        left->next = merge(left->next, right);
        return left;
    }
    else
    {
        right->next = merge(left, right->next);
        return right;
    }
}

Node *mergeSort(Node *head)
{
    if (head == NULL)
        return NULL;
    Node *mid = findMiddle(head);
    Node *left = mergeSort(head);
    Node *right = mergeSort(mid);
    return merge(left, right);
}

// Time Complexity: O(nlogn)
// Space Complexity: O(n) 