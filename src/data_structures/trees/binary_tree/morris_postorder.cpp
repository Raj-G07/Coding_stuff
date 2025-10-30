#include "./structure.cpp"

void printReverse(Node *start, Node *end)
{
    reversePath(start, end);

    Node *node = end;
    while (true)
    {
        cout << node->data << " ";
        if (node == start)
            break;
        node = node->right;
    }

    reversePath(end, start); // restore original links
}

void reversePath(Node *start, Node *end)
{
    if (start == end)
        return;
    Node *prev = nullptr;
    Node *current = start;
    Node *next;

    while (current != end)
    {
        next = current->right;
        current->right = prev;
        prev = current;
        current = next;
    }
    current->right = prev;
}

void morrisPostorderTraversal(Node *root)
{
    Node *dummy = new Node(0);
    dummy->left = root;
    Node *current = dummy;
    Node *pre;

    while (current != NULL)
    {
        if (current->left == NULL)
        {
            current = current->right;
        }
        else
        {
            pre = current->left;
            while (pre->right != NULL && pre->right != current)
            {
                pre = pre->right;
            }
            if (pre->right == NULL)
            {
                pre->right = current;
                current = current->left;
            }
            else
            {
                printReverse(current->left, pre);
                pre->right = NULL;
                current = current->right;
            }
        }
    }

    delete dummy;
}