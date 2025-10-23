// Z Algorithm
#include <iostream>
#include <vector>
using namespace std;

vector<int> computeZ(string s) { // aabxaab  // 0, 1, 0, 0, 3, 1, 0
    int n = s.length();
    vector<int> Z(n, 0);
    int L = 0, R = 0;

    for (int i = 1; i < n; i++) {
        if (i <= R)
            Z[i] = min(R - i + 1, Z[i - L]);
        while (i + Z[i] < n && s[Z[i]] == s[i + Z[i]]) 
            Z[i]++;
        if (i + Z[i] - 1 > R)
            L = i, R = i + Z[i] - 1;
    }
    return Z;
}

vector<int> searchPattern(string text, string pattern) {
    string s = pattern + "$" + text;
    vector<int> Z = computeZ(s);
    vector<int> result;
    int pLen = pattern.length();

    for (int i = 0; i < (int)Z.size(); i++)
        if (Z[i] == pLen)
            result.push_back(i - pLen - 1); // index in text
    return result;
}
