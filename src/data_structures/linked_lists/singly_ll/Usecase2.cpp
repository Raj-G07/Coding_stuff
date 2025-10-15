// Reverse a Linked List from Position k

#include "./structure.cpp"

void reverseFromK(Node *head, int k)
{
    if (head == NULL || k == 0)
        return;
    int cnt = 1;
    Node *curr = head;
    Node *prev = NULL;
    while (curr != NULL && cnt < k)
    {
        prev = curr;
        curr = curr->next;
        cnt++;
    }
    if (curr == NULL)
        return;
    Node *revPrev = NULL;
    Node *revCurr = curr;
    while (revCurr != NULL)
    {
        Node *forw = revCurr->next;
        revCurr->next = revPrev;
        revPrev = revCurr;
        revCurr = forw;
    }
    if (prev != NULL)
    {
        prev->next = revPrev;
    }
    else
        head = revPrev;
}

// Time Complexity
// Reverse from Position k: O(n)(to traverse to k-th node and reverse).