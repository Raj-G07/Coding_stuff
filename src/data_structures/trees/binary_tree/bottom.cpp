#include "./structure.cpp"
#include <map>
#include <vector>
#include <queue>

vector<int> bottomOrderTraversal(Node* root) {
    vector<int> result;
    if(!root) return result;
    map<int, int> bottomNodeMap; // horizontal distance -> node data
    queue<pair<Node*, int>> q; // pair of node and its horizontal distance
    q.push({root, 0});
    while(!q.empty()) {
        auto front = q.front();
        q.pop();
        Node* currentNode = front.first;
        int hd = front.second;

        // Update the bottom node for this horizontal distance
        bottomNodeMap[hd] = currentNode->data;

        if(currentNode->left) {
            q.push({currentNode->left, hd - 1});
        }
        if(currentNode->right) {
            q.push({currentNode->right, hd + 1});
        }
    }
    // Extract the bottom view from the map
    for(auto& it : bottomNodeMap) {
        result.push_back(it.second);
    }
    return result;
}