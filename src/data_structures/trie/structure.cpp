#include <iostream>
#include <unordered_map>

using namespace std;

class TrieNode
{
public:
    unordered_map<char, TrieNode *> children;
    bool isEndofWord;
    TrieNode()
    {
        isEndofWord = false;
    }
};

class Trie
{
private:
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode *curr = root;
        for (auto c : word)
        {
            if (curr->children.find(c) == curr->children.end())
            {
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }
        curr->isEndofWord = true;
    }

    bool search(string word)
    {
        TrieNode *curr = root;
        for (auto c : word)
        {
            if (curr->children.find(c) == curr->children.end())
                return false;
            curr = curr->children[c];
        }
        return curr->isEndofWord;
    }

    bool startsWith(string prefix)
    {
        TrieNode *curr = root;
        for (auto c : prefix)
        {
            if (curr->children.find(c) == curr->children.end())
            {
                return false;
            }
            curr = curr->children[c];
        }
        return true;
    }
};