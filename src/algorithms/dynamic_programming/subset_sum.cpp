// Given: 
// A set of integers S={s1,s2,…,sn}. 
// A target sum T. 
// Objective: 
// Determine whether there exists a subset of S whose sum equals T.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Recursive approach

bool subsetSum_recursive(vector<int>& arr, int n, int target) {
    if (target == 0) return true;        // Found a subset
    if (n == 0) return false;            // No elements left

    if (arr[n - 1] <= target) {
        // include or exclude current element
        return subsetSum_recursive(arr, n - 1, target - arr[n - 1]) ||
               subsetSum_recursive(arr, n - 1, target);
    } else {
        // can't include current element
        return subsetSum_recursive(arr, n - 1, target);
    }
}

// Top Down Dynamic Programming (Memoization)

bool subsetSum_memoization(vector<int>& arr, int n, int target, vector<vector<int>>& dp) {
    if (target == 0) return true;
    if (n == 0) return false;

    if (dp[n][target] != -1) return dp[n][target];

    if (arr[n - 1] <= target)
        return dp[n][target] = subsetSum_memoization(arr, n - 1, target - arr[n - 1], dp) ||
                               subsetSum_memoization(arr, n - 1, target, dp);
    else
        return dp[n][target] = subsetSum_memoization(arr, n - 1, target, dp);
}

// Bottom Up Dynamic Programming (Tabulation)

bool subsetSum_tabulation(vector<int>& arr, int target) {
    int n = arr.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

    // Base Case: sum = 0 → always possible
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    // Fill DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= target; j++) {
            if (arr[i - 1] <= j)
                dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][target];
}

// Optimized Bottom Up Dynamic Programming 

bool subsetSum_optimized(vector<int>& arr, int target) {
    int n = arr.size();
    vector<bool> prev(target + 1, false), curr(target + 1, false);

    prev[0] = true; // sum = 0 always possible

    for (int i = 0; i < n; i++) {
        curr[0] = true;
        for (int j = 1; j <= target; j++) {
            if (arr[i] <= j)
                curr[j] = prev[j - arr[i]] || prev[j];
            else
                curr[j] = prev[j];
        }
        prev = curr;
    }
    return prev[target];
}
