#include "./structure.cpp"
#include <vector>
#include <map>
#include <queue>
vector<vector<int>> verticalOrderTraversal(Node* root){
      if(!root) return {};
        map<int, vector<int>> mp;
        vector<vector<int>> result;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            auto [node, col] = q.front();
            q.pop();
            mp[col].push_back(node->data);
            if(node->left) q.push({node->left, col-1});
            if(node->right) q.push({node->right, col+1});
        }
        for(auto& [col, nodes] : mp){
            result.push_back(nodes);
        }
        return result;
}