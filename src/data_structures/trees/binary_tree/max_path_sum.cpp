#include "./structure.cpp"

struct Pair {
    int max_gain;  // best path sum that can be extended upward
    int max_sum;   // best path sum within the subtree
};

Pair helper(Node* root) {
    if (!root) return {0, INT_MIN};

    Pair left = helper(root->left);
    Pair right = helper(root->right);

    // Best path that can be extended upwards (ignore negatives)
    int max_gain = root->data + max(0, max(left.max_gain, right.max_gain));

    // Best path found in this subtree
    int max_sum = max({left.max_sum, right.max_sum,
                       root->data + max(0, left.max_gain) + max(0, right.max_gain)});

    return {max_gain, max_sum};
}

int maxPathSum(Node* root) {
    return helper(root).max_sum;
}