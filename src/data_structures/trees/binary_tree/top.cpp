#include "./structure.cpp"
#include<vector>
#include<map>
#include<queue>
vector<int> topOrderTraversal(Node* root) {
    vector<int> ans;
    if (!root) return ans;

     map<int, int> topNode;
    // Queue for level order traversal
    queue<pair<Node*, int>> q;

    q.push({root, 0});

    while (!q.empty()) {
        auto [node, hd] = q.front();
        q.pop();

        // Record the node if this HD is not seen before
        if (topNode.find(hd) == topNode.end())
            topNode[hd] = node->data;

        if (node->left)
            q.push({node->left, hd - 1});
        if (node->right)
            q.push({node->right, hd + 1});
    }

    // Extract values from map (sorted by HD)
    for (auto& it : topNode)
        ans.push_back(it.second);

    return ans;
}