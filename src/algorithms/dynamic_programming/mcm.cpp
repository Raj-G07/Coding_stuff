// Given: 
// A sequence of matrices A1,A2,…,An. 
// The dimensions of these matrices are given as an array p such that matrix A has dimensions  p[i−1]×p[i]. 
// Objective: 
// Determine the optimal way to parenthesize the matrix product A1⋅A2⋅⋯⋅An such that the total number of scalar multiplications is minimized. 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Recursive approach

int mcm_recursive(vector<int>& p, int i, int j) {
    if (i == j) return 0;  // Only one matrix, no multiplication

    int minCost = INT_MAX;
    for (int k = i; k < j; k++) {
        int cost = mcm_recursive(p, i, k)
                 + mcm_recursive(p, k + 1, j)
                 + p[i - 1] * p[k] * p[j];
        minCost = min(minCost, cost);
    }
    return minCost;
}

// Top Down Dynamic Programming (Memoization)

int mcm_memoization(vector<int>& p, int i, int j, vector<vector<int>>& dp) {
    if (i == j) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    int minCost = INT_MAX;
    for (int k = i; k < j; k++) {
        int cost = mcm_memoization(p, i, k, dp)
                 + mcm_memoization(p, k + 1, j, dp)
                 + p[i - 1] * p[k] * p[j];
        minCost = min(minCost, cost);
    }
    return dp[i][j] = minCost;
}

// Bottom Up Dynamic Programming (Tabulation)

int mcm_tabulation(vector<int>& p) {
    int n = p.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // len = chain length
    for (int len = 2; len < n; len++) {
        for (int i = 1; i < n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }
    return dp[1][n - 1];
}

// Optimized Bottom Up Dynamic Programming 

// Note: Full space optimization is not possible because we need 2D dependencies