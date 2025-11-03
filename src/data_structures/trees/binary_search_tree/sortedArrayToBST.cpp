#include "./strucuture.cpp"
Node *sortedArrayToBSTHelper(vector<int> &nums, int s, int e)
{
    if (s > e)
        return NULL;
    int mid = s + (e - s) / 2;
    Node *root = new Node(nums[mid]);
    root->left = sortedArrayToBSTHelper(nums, s, mid - 1);
    root->right = sortedArrayToBSTHelper(nums, mid + 1, e);
    return root;
}

Node *sortedArrayToBST(vector<int> &nums)
{
    return sortedArrayToBSTHelper(nums, 0, nums.size() - 1);
}