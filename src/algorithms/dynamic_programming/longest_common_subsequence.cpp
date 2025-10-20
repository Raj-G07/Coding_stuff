// Given: 
// Two strings X and Y of lengths m and n.
// Objective: 
// Find the length of the longest subsequence present in both strings.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Recursive approach 

int lcs_recursive(string& X, string& Y, int m, int n) {
    if (m == 0 || n == 0) return 0;
    if (X[m-1] == Y[n-1]) return 1 + lcs_recursive(X, Y, m-1, n-1);
    return max(lcs_recursive(X, Y, m, n-1), lcs_recursive(X, Y, m-1, n));
}

// Top Down Dynamic Programming (Memoization)

int lcs_memoization(string& X, string& Y, int m, int n, vector<vector<int>>& dp) {
    if (m == 0 || n == 0) return 0;
    if (dp[m][n] != -1) return dp[m][n];
    if (X[m-1] == Y[n-1]) return dp[m][n] = 1 + lcs_memoization(X, Y, m-1, n-1, dp);
    return dp[m][n] = max(lcs_memoization(X, Y, m, n-1, dp), lcs_memoization(X, Y, m-1, n, dp));
}

// Bottom Up Dynamic Programming (Tabulation)

int lcs_tabulation(string& X, string& Y, int m, int n) {
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i-1] == Y[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}

// Optimized Bottom Up Dynamic Programming (Space Optimization)

int lcs_optimized(string& X, string& Y, int m, int n) {
    vector<int> prev(n+1, 0), curr(n+1, 0);
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i-1] == Y[j-1]) {
                curr[j] = 1 + prev[j-1];
            } else {
                curr[j] = max(prev[j], curr[j-1]);
            }
        }
        prev = curr;
    }
    return prev[n];
}