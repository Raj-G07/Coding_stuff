#include "./structure.cpp"
#include <algorithm>

struct Pair {
    int height;
    int diameter;
}; 

Pair diameterUtil(Node* root) {
    if (root == NULL) {
        return {0, 0};
    }

    Pair leftPair = diameterUtil(root->left);
    Pair rightPair = diameterUtil(root->right);

    int currentHeight = max(leftPair.height, rightPair.height) + 1;

    int diameterThroughRoot = leftPair.height + rightPair.height + 1;
    int currentDiameter = max({leftPair.diameter, rightPair.diameter, diameterThroughRoot});

    return {currentHeight, currentDiameter};
}

int diameter(Node* root) {
    Pair result = diameterUtil(root);
    return result.diameter;
}

//Definition Style	Height of Leaf	Diameter Formula	    Meaning
//Height = nodes	    1	        left + right + 1	Counts total nodes in longest path
//Height = edges	    0	         left + right	    Counts total edges in longest path