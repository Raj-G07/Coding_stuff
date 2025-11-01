// The LCA of two nodes p and q in a binary tree is the lowest (deepest) node that has both p and q as descendants (a node can be a descendant of itself).

#include "./structure.cpp"

Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
    if (!root || root == p || root == q)
        return root;

    Node* left = lowestCommonAncestor(root->left, p, q);
    Node* right = lowestCommonAncestor(root->right, p, q);

    // Case 1: p and q found in different subtrees
    if (left && right) return root;

    // Case 2: both are in same subtree
    return left ? left : right;
}