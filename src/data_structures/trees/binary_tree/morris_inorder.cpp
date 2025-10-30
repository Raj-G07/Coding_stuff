#include "./structure.cpp"

void morrisInorderTraversal(Node* root){
    Node* current = root;
    Node* pre;

    while(current!=NULL){
        if(current->left == NULL){
            cout<< current->data<<"";
            current = current->right;
        }else{
            pre = current->left;
            while(pre->right != NULL && pre->right != current){
                pre = pre->right;
            }
            if(pre->right == NULL){
                pre->right = current;
                current = current->left;
            }else{
                pre->right = NULL;
                cout<< current->data<<"";
                current = current->right;
            }
        }
    }
}