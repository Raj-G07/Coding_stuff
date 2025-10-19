// Huffman Encoding is a Greedy Algorithm used for lossless data compression. It reduces the total size of data by assigning variable-length binary codes to input characters based on their frequencies. Frequently occurring characters get shorter codes, while less frequent ones get longer codes.

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
struct Node
{
    char ch;
    int freq;
    Node *left, *right;

    Node(char character, int frequency) : ch(character), freq(frequency), left(nullptr), right(nullptr) {}
};
struct compare
{
    bool operator()(Node *l, Node *r)
    {
        return l->freq > r->freq;
    }
};
void printCodes(Node *root, string str, unordered_map<char, string> &huffmanCode)
{
    if (!root)
        return;

    if (root->left == nullptr && root->right == nullptr)
    {
        huffmanCode[root->ch] = str;
    }

    printCodes(root->left, str + "0", huffmanCode);
    printCodes(root->right, str + "1", huffmanCode);
}
unordered_map<char, string> huffmanEncoding(vector<char> characters, vector<int> frequencies)
{
    priority_queue<Node *, vector<Node *>, compare> minHeap;

    for (size_t i = 0; i < characters.size(); i++)
    {
        minHeap.push(new Node(characters[i], frequencies[i]));
    }

    while (minHeap.size() > 1)
    {
        Node *left = minHeap.top();
        minHeap.pop();
        Node *right = minHeap.top();
        minHeap.pop();

        Node *newNode = new Node('\0', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;
        minHeap.push(newNode);
    }

    Node *root = minHeap.top();
    unordered_map<char, string> huffmanCode;
    printCodes(root, "", huffmanCode);
    return huffmanCode;
}