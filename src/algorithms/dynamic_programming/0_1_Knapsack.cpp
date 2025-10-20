// 0-1 Knapsack Problem using Dynamic Programming
// Given n items, each with a weight and a value, determine the maximum value that can be carried in a knapsack of capacity W.

// Recursive approach 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapsack_recursive(int W, vector<int>& weights, vector<int>& values, int n) {
    if (n == 0 || W == 0) return 0;
    if (weights[n-1] > W) return knapsack_recursive(W, weights, values, n-1);
    return max(values[n-1] + knapsack_recursive(W - weights[n-1], weights, values, n-1),  knapsack_recursive(W, weights, values, n-1));
}


// Top Down Dynamic Programming (Memoization)

int knapsack_memoization(int W, vector<int>& weights, vector<int>& values, int n, vector<vector<int>>& dp) {
    if (n == 0 || W == 0) return 0;
    if (dp[n][W] != -1) return dp[n][W];
    if (weights[n-1] > W) return dp[n][W] = knapsack_memoization(W, weights, values, n-1, dp);
    return dp[n][W] = max(values[n-1] + knapsack_memoization(W - weights[n-1], weights, values, n-1, dp), knapsack_memoization(W, weights, values, n-1, dp));
}


// Bottom Up Dynamic Programming (Tabulation)

int knapsack_tabulation(int W, vector<int>& weights, vector<int>& values, int n) {
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (weights[i-1] <= w) {
                dp[i][w] = max(values[i-1] + dp[i-1][w - weights[i-1]], dp[i-1][w]);
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    return dp[n][W];
}

// Optimized Bottom Up Dynamic Programming (Space Optimization)

int knapsack_optimized(int W, vector<int>& weights, vector<int>& values, int n) {
    vector<int> dp(W+1, 0);
    for (int i = 0; i < n; i++) {
        for (int w = W; w >= weights[i]; w--) {
            dp[w] = max(dp[w], values[i] + dp[w - weights[i]]);
        }
    }
    return dp[W];
}