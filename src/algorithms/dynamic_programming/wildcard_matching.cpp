// Given: 
// A string s (the text) and a pattern p. 
// The pattern p can contain two special characters: 
// '*' (asterisk) which matches any sequence of characters (including an empty sequence). 
// '?' (question mark) which matches exactly one character. 
// Objective:
// Your task is to check whether the string s matches the pattern p. 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Recursive approach

bool wildCard_recursive(string &s, string &p, int i, int j) {
    if (i < 0 && j < 0) return true;
    if (j < 0 && i >= 0) return false;

    if (i < 0) {
        for (int k = 0; k <= j; k++) {
            if (p[k] != '*') return false;
        }
        return true;
    }

    if (p[j] == s[i] || p[j] == '?')
        return wildCard_recursive(s, p, i - 1, j - 1);

    if (p[j] == '*')
        return wildCard_recursive(s, p, i - 1, j) || wildCard_recursive(s, p, i, j - 1);

    return false;
}

// Top Down Dynamic Programming (Memoization)

bool wildCard_memoization(string &s, string &p, int i, int j, vector<vector<int>> &dp) {
    if (i < 0 && j < 0) return true;
    if (j < 0 && i >= 0) return false;
    if (i < 0) {
        for (int k = 0; k <= j; k++) {
            if (p[k] != '*') return false;
        }
        return true;
    }

    if (dp[i][j] != -1) return dp[i][j];

    if (p[j] == s[i] || p[j] == '?')
        return dp[i][j] = wildCard_memoization(s, p, i - 1, j - 1, dp);

    if (p[j] == '*')
        return dp[i][j] = (wildCard_memoization(s, p, i - 1, j, dp) || wildCard_memoization(s, p, i, j - 1, dp));

    return dp[i][j] = false;
}

// Bottom Up Dynamic Programming (Tabulation)

bool wildCard_tabulation(string &s, string &p) {
    int n = s.size(), m = p.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

    dp[0][0] = true;

    // pattern only of '*' can match empty string
    for (int j = 1; j <= m; j++) {
        if (p[j - 1] == '*')
            dp[0][j] = dp[0][j - 1];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (p[j - 1] == s[i - 1] || p[j - 1] == '?')
                dp[i][j] = dp[i - 1][j - 1];
            else if (p[j - 1] == '*')
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            else
                dp[i][j] = false;
        }
    }
    return dp[n][m];
}

// Optimized Bottom Up Dynamic Programming 

bool wildCard_optimized(string &s, string &p) {
    int n = s.size(), m = p.size();
    vector<bool> prev(m + 1, false), curr(m + 1, false);

    prev[0] = true;

    for (int j = 1; j <= m; j++) {
        if (p[j - 1] == '*')
            prev[j] = prev[j - 1];
    }

    for (int i = 1; i <= n; i++) {
        curr[0] = false;
        for (int j = 1; j <= m; j++) {
            if (p[j - 1] == s[i - 1] || p[j - 1] == '?')
                curr[j] = prev[j - 1];
            else if (p[j - 1] == '*')
                curr[j] = prev[j] || curr[j - 1];
            else
                curr[j] = false;
        }
        prev = curr;
    }
    return prev[m];
}