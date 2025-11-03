#include "./strucuture.cpp"
#include "./sortedArrayToBST.cpp"

void inorder(Node* root,vector<int>&nodes){
    if(!root) return ;
    inorder(root->left,nodes);
    nodes.push_back(root->data);
    inorder(root->right,nodes);
}

Node* balancedBST(Node* root){
    vector<int>nodes;
    inorder(root,nodes);
    return sortedArrayToBSTHelper(nodes,0,nodes.size()-1);
}