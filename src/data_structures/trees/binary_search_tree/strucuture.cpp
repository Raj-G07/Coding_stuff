#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr) , right(nullptr){}
};


Node* insert(Node* root, int key){
    if(!root) return new Node(key);
    if(key< root->data)
       root->left = insert(root->left,key);
    else if (key>root->data)
       root->right = insert(root->right,key);
    return root;
}

bool search(Node* root, int key){
    if(!root) return false;
    if(root->data == key) return true;
    if(root->data>key)
      return search(root->left,key);
    else 
        search(root->right,key); 
}

void inorder(Node* root){
    if(!root) return ;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

//  Time Complexity
// Operation   Average	Worst Case
// Search	   O(log N)	   O(N)
// Insert	   O(log N)	   O(N)
// Delete	   O(log N)	   O(N)

// Worst case occurs when tree becomes skewed (like a linked list).