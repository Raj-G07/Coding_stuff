#include "./structure.cpp"
#include <bits/stdc++.h>

bool isLeaf(Node *node)
{
    return node->left == nullptr && node->right == nullptr;
}

void addLeftBoundary(Node *root, vector<int> &res)
{
    Node *curr = root->left;
    while (curr)
    {
        if (!isLeaf(curr))
            res.push_back(curr->data);
        if (curr->left)
            curr = curr->left;
        else
            curr = curr->right;
    }
}

void addLeaves(Node *root, vector<int> &res)
{
    if (isLeaf(root))
    {
        res.push_back(root->data);
        return;
    }
    if (root->left)
        addLeaves(root->left, res);
    if (root->right)
        addLeaves(root->right, res);
}

void addRightBoundary(Node *root, vector<int> &res)
{
    Node *curr = root->right;
    vector<int> temp;
    while (curr)
    {
        if (!isLeaf(curr))
            temp.push_back(curr->data);
        if (curr->right)
            curr = curr->right;
        else
            curr = curr->left;
    }
    reverse(temp.begin(), temp.end());
    res.insert(res.end(), temp.begin(), temp.end());
}

vector<int> boundaryTraversal(Node *root)
{
    vector<int> res;
    if (!root)
        return res;

    if (!isLeaf(root))
        res.push_back(root->data);

    addLeftBoundary(root, res);
    addLeaves(root, res);
    addRightBoundary(root, res);

    return res;
}