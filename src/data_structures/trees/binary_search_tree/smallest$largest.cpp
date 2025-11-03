#include "./strucuture.cpp"

int cnt = 0;
int result1 = -1;
int result2 = -1;
void inorder(Node* root, int k){
    if(!root) return ;
    inorder(root->left,k);
    cnt++;
    if(cnt==k){
        result1 = root->data;
        return;
    }
    inorder(root->right,k);
}

void reverseInorder(Node* root, int k){
    if(!root) return ;
    reverseInorder(root->right,k);
    cnt++;
    if(cnt==k){
        result2= root->data;
        return;
    }
    reverseInorder(root->left,k);
}

int kthSmallest(Node* root ,int k){
    cnt = 0 ;
    inorder(root,k);
    return result1;
}

int kthLargest(Node* root, int k){
    cnt = 0; 
    reverseInorder(root,k);
    return result2;
}