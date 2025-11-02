#include "./strucuture.cpp"
using namespace std;

Node *LCAinBst(Node *root, int p, int q)
{
    if (!root)
        return NULL;
    if (root->data > p && root->data > q)
    {
        return LCAinBst(root->left, p, q);
    }
    if (root->data < p && root->data < q)
    {
        return LCAinBst(root->right, p, q);
    }
    return root;
}