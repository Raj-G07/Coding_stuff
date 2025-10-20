// Given: 
// Two strings XXX (of length mmm) and YYY (of length nnn). 
// Objective: 
//  Transform XXX into YYY using a minimum number of the following operations: 
// 1. Insertion: Insert a character. 
// 2. Deletion: Remove a character. 
// 3. Substitution: Replace one character with another. 

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Recursive approach

int edit_distance_recursive(string& X, string& Y, int m, int n) {
    if (m == 0) return n; // If first string is empty, insert all characters of second string
    if (n == 0) return m; // If second string is empty, remove all characters of first string

    if (X[m-1] == Y[n-1]) {
        return edit_distance_recursive(X, Y, m-1, n-1); // Characters match, move to next
    }

    // If characters don't match, consider all possibilities and find the minimum
    int insertOp = edit_distance_recursive(X, Y, m, n-1);
    int deleteOp = edit_distance_recursive(X, Y, m-1, n);
    int substituteOp = edit_distance_recursive(X, Y, m-1, n-1);

    return 1 + min({insertOp, deleteOp, substituteOp});
}

// Top Down Dynamic Programming (Memoization)

int edit_distance_memoization(string& X, string& Y, int m, int n, vector<vector<int>>& dp) {
    if (m == 0) return n;
    if (n == 0) return m;
    if (dp[m][n] != -1) return dp[m][n];

    if (X[m-1] == Y[n-1]) {
        return dp[m][n] = edit_distance_memoization(X, Y, m-1, n-1, dp);
    }

    int insertOp = edit_distance_memoization(X, Y, m, n-1, dp);
    int deleteOp = edit_distance_memoization(X, Y, m-1, n, dp);
    int substituteOp = edit_distance_memoization(X, Y, m-1, n-1, dp);

    return dp[m][n] = 1 + min({insertOp, deleteOp, substituteOp});
}

// Bottom Up Dynamic Programming (Tabulation)

int edit_distance_tabulation(string& X, string& Y, int m, int n) {
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0) {
                dp[i][j] = j; // If first string is empty
            } else if (j == 0) {
                dp[i][j] = i; // If second string is empty
            } else if (X[i-1] == Y[j-1]) {
                dp[i][j] = dp[i-1][j-1]; // Characters match
            } else {
                int insertOp = dp[i][j-1];
                int deleteOp = dp[i-1][j];
                int substituteOp = dp[i-1][j-1];
                dp[i][j] = 1 + min({insertOp, deleteOp, substituteOp});
            }
        }
    }

    return dp[m][n];
}

// Optimized Bottom Up Dynamic Programming (Space Optimization)

int edit_distance_optimized(string& X, string& Y, int m, int n) {
    vector<int> prev(n+1, 0), curr(n+1, 0);

    for (int j = 0; j <= n; j++) {
        prev[j] = j; // If first string is empty
    }

    for (int i = 1; i <= m; i++) {
        curr[0] = i; // If second string is empty
        for (int j = 1; j <= n; j++) {
            if (X[i-1] == Y[j-1]) {
                curr[j] = prev[j-1]; // Characters match
            } else {
                int insertOp = curr[j-1];
                int deleteOp = prev[j];
                int substituteOp = prev[j-1];
                curr[j] = 1 + min({insertOp, deleteOp, substituteOp});
            }
        }
        prev = curr;
    }

    return prev[n];
}

