// Given: 
// A rod of length n. 
// An array P where P[i] is the price of a rod of length i+1. 
// Objective: 
// Find the maximum profit that can be obtained by cutting the rod into pieces and selling the pieces.


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Recursive approach

int rodCutting_recursive(vector<int>& price, int n) {
    if (n == 0) return 0;

    int maxProfit = INT_MIN;
    for (int i = 0; i < n; i++) {
        int profit = price[i] + rodCutting_recursive(price, n - (i + 1));
        maxProfit = max(maxProfit, profit);
    }
    return maxProfit;
}

// Top Down Dynamic Programming (Memoization)

int rodCutting_memoziation(vector<int>& price, int n, vector<int>& dp) {
    if (n == 0) return 0;
    if (dp[n] != -1) return dp[n];

    int maxProfit = INT_MIN;
    for (int i = 0; i < n; i++) {
        int profit = price[i] + rodCutting_memoziation(price, n - (i + 1), dp);
        maxProfit = max(maxProfit, profit);
    }
    return dp[n] = maxProfit;
}

// Bottom Up Dynamic Programming (Tabulation)

int rodCutting_tabulation(vector<int>& price, int n) {
    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        int maxProfit = INT_MIN;
        for (int j = 0; j < i; j++) {
            maxProfit = max(maxProfit, price[j] + dp[i - j - 1]);
        }
        dp[i] = maxProfit;
    }
    return dp[n];
}

// Optimized Bottom Up Dynamic Programming 

int rodCutting_optimization(vector<int>& price, int n) {
    vector<int> dp(n + 1, 0);

    for (int len = 1; len <= n; len++) {
        for (int cut = 0; cut < len; cut++) {
            dp[len] = max(dp[len], price[cut] + dp[len - cut - 1]);
        }
    }
    return dp[n];
}
