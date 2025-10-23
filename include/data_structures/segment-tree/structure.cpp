// A Segment Tree is a binary tree-like data structure used for efficiently solving range query problems on arrays

#include <iostream>
#include <vector>

using namespace std;

class SegmentTree
{
private:
    vector<int> tree;
    int n;

    void buildTree(vector<int> &arr, int node, int start, int end)
    {
        if (start == end)
        {
            tree[node] = arr[start];
        }
        int mid = (start + end) / 2;
        buildTree(arr, 2 * node + 1, start, mid);
        buildTree(arr, 2 * node, mid + 1, end);
        tree[node] = tree[2 * node + 1] + tree[2 * node];
    }

    int queryTree(int node, int start, int end, int l, int r)
    {
        if (r < start || l > end)
        {
            return 0;
        }
        if (l <= start && end <= r)
        {
            return tree[node];
        }
        int mid = (start + end) / 2;
        int left = queryTree(2 * node, start, mid, l, r);
        int right = queryTree(2 * node + 1, mid + 1, end, l, r);
        return left + right;
    }

    void updateTree(int node, int start, int end, int idx, int value)
    {
        if (start == end)
        {
            tree[node] = value;
            return;
        }
        int mid = (start + end) / 2;
        if (idx > mid && idx <= end)
        {
            updateTree(2 * node + 1, mid + 1, end, idx, value);
        }
        else
        {
            updateTree(2 * node, start, mid, idx, value);
        }
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

public:
    SegmentTree(vector<int> &arr)
    {
        n = arr.size();
        tree.resize(4 * n, 0);
        buildTree(arr, 1, 0, n - 1);
    }
    int query(int l, int r)
    {
        return queryTree(1, 0, n - 1, l, r);
    }
    void update(int idx, int value)
    {
        updateTree(1, 0, n - 1, idx, value);
    }
};