// KMP (Knuth-Morris-Pratt) Algorithm

#include <iostream>
#include <vector>

using namespace std;

vector<int> prefix_fun(string s)
{
    int n = s.length();
    vector<int> lps(n, 0);
    int i = 1;
    while (i < n)
    {
        int prev_ind = lps[i - 1];
        while (prev_ind > 0 && s[i] != s[prev_ind])
        {
            prev_ind = lps[prev_ind - 1];
        }
        lps[i] = prev_ind + (s[i] == s[prev_ind] ? 1 : 0);
    }
    return lps;
}

vector<int> KMP_with_hash(string text, string pattern) {
    string combined = pattern + "#" + text;
    vector<int> pi = prefix_fun(combined);
    vector<int> result;
    int m = pattern.size();

    for (int i = m + 1; i < combined.size(); i++) {
        if (pi[i] == m)
            result.push_back(i - 2 * m); // match start index in text
    }
    return result;
}