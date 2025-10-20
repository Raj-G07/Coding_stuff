// Given: 
// An array arr of size n. 
// Objective: 
// Find the length of the longest increasing subsequence. 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Recursive approach

int lis_recursive(vector<int>& arr, int n) {
    if (n == 1) return 1;
    int maxEndingHere = 1;
    for (int i = 1; i < n; i++) {
        int res = lis_recursive(arr, i);
        if (arr[i-1] < arr[n-1]) {
            maxEndingHere = max(maxEndingHere, res + 1);
        }
    }
    return maxEndingHere;
}

// Top Down Dynamic Programming (Memoization)

int lis_memoization(vector<int>& arr, int n, vector<int>& dp) {
    if (dp[n-1] != -1) return dp[n-1];  
    int maxEndingHere = 1;
    for (int i = 1; i < n; i++) {
        int res = lis_memoization(arr, i, dp);
        if (arr[i-1] < arr[n-1]) {
            maxEndingHere = max(maxEndingHere, res + 1);
        }
    }
    return dp[n-1] = maxEndingHere;
}

// Bottom Up Dynamic Programming (Tabulation)

int lis_tabulation(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n, 1);   
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}

// Optimized Bottom Up Dynamic Programming (Using Binary Search)

int lis_optimized(vector<int>& arr) {
    vector<int> tail;
    for (int num : arr) {
        auto it = lower_bound(tail.begin(), tail.end(), num);
        if (it == tail.end()) {
            tail.push_back(num);
        } else {
            *it = num;
        }
    }
    return tail.size();
}