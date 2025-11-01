// A Binary Tree is said to be height-balanced if, for every node:
// | height(leftSubtree) − height(rightSubtree) | ≤ 1
// and both left and right subtrees are also balanced.


#include "./structure.cpp"

struct Pair {
    int height;
    bool is_balanced;
};

Pair check_balance(Node* node) {
    if (node == nullptr) {
        return {0, true};
    }

    Pair left = check_balance(node->left);
    Pair right = check_balance(node->right);

    int current_height = max(left.height, right.height) + 1;
    bool current_is_balanced = left.is_balanced && right.is_balanced &&
                               abs(left.height - right.height) <= 1;

    return {current_height, current_is_balanced};
}

bool is_balanced(Node* root) {
    return check_balance(root).is_balanced;
}