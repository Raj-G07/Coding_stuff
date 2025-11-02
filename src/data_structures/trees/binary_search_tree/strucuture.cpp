#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr) , right(nullptr){}
};

int findMinimum(Node* root){
    if(!root) return NULL;
    while(root && root->left){
        root= root->left;
    }
    return root->data;
}

int findMaximum(Node* root){
    if(!root) return NULL;
    while(root && root->right){
        root = root->right;
    }
    return root->data;
}

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
Node* findSuccessor(Node* root){
    while(root && root->left){
        root= root->left;
    }
    return root;
}

Node* deleteN(Node* root,int key){
    if(!root) return nullptr;
    if(root->data>key){
        root->left = deleteN(root->left,key);
    }else if(root->data<key){
        root->right = deleteN(root->right,key);
    }
    if(!root->left){
        return root->right;
    }
    if(!root->right){
        return root->left;
    }
    Node* successor = findSuccessor(root->right);
    root->data= successor->data;
    root->right = deleteN(root->right,successor->data);
    return root;
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