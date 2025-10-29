#include<iostream>
#include<vector>
#include<queue>

using namespace std;


class TreeNode {
public:
    int val;
    vector<TreeNode*> children;
    TreeNode(int value) : val(value) {}

    void printTree(TreeNode* root){
        if(!root) return;
        cout << root->val << " ";
        for(auto child : root->children){
            printTree(child);
        }
    }

    void printLevelOrder(TreeNode* root) {
        if (!root) return;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            cout << node->val << " ";
            for (auto child : node->children) {
                q.push(child);
            }
        }
        cout << endl; // New line after each level
    }

    void deleteTree(TreeNode* root) {
        if (!root) return;
        for (auto child : root->children) {
            deleteTree(child);
        }
        delete root;
    }
};


