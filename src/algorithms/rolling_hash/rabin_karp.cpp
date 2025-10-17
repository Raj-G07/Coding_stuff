// Rolling Hash is a hashing technique that efficiently computes the hash value of a sliding window (substring) in a string. It is primarily used for pattern matching algorithms like RabinKarp because it allows for fast recalculation of hash values when the window slides over one character.

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
const int p = 31; // Prime base

const int m = 1e9 + 9; // Large prime modulus

// Function to calculate a polynomial hash
long long calculateHash(string s)
{
    long long hashValue = 0;
    long long p_pow = 1;
    for (auto c : s)
    {
        hashValue = (hashValue + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hashValue;
}

// Rolling Hash function to find pattern occurrences in a text
vector<int> rabinKarp(string &text, string &pattern)
{
    int T = text.length(), P = pattern.length();
    vector<int> ans;
    long long pattern_hash = calculateHash(pattern);
    long long text_hash = calculateHash(text.substr(0, P));
    if (pattern_hash == text_hash && pattern == text.substr(0, P))
        ans.push_back(0);
    int p_pow = 1;
    for (int i = 0; i < P; i++)
        p_pow = (p_pow * p) % m;
    for (int i = 1; i <= T - P; i++)
    {
        text_hash = ((text_hash - (text[i - 1] - 'a' + 1)) * p + (text[P + i - 1] - 'a' + 1) * p_pow) % m;
        if (text_hash < 0)
        {
            text_hash += m;
        }
        if (pattern_hash == text_hash && pattern == text.substr(i, P))
            ans.push_back(i);
    }
    return ans;
}

// Time Complexity: O(T+P)where T is the length of the text and P is the length of the pattern. 
// The hash values are updated in O(1) for each character shift, and hash comparisons are done in constant time.