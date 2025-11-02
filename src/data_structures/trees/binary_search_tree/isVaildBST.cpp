#include "./strucuture.cpp"

bool isValidBstUtil(Node *root, int mini, int maxi)
{
    if (!root)
        return true;
    if (root->data <= mini || root->data >= maxi)
        return false;
    return isValidBstUtil(root->left, mini, root->data) && isValidBstUtil(root->right, root->data, maxi);
}

bool isValidBst(Node *root)
{
    return isValidBstUtil(root, LLONG_MIN, LLONG_MAX);
}