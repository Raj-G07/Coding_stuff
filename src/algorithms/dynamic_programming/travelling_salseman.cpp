// Given: 
// A set of n cities and a distance matrix dist[i][j], representing the distance between city i and city j. 
// Objective: 
// Find the minimum cost to complete a tour that starts at any city, visits every other city exactly once, and returns to the starting city.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Recursive approach

int tsp_recursive(int mask, int pos, vector<vector<int>>& dist, int n) {
    // mask = bitmask representing visited cities
    // pos = current city

    if (mask == (1 << n) - 1)  // all cities visited
        return dist[pos][0];   // return to start city

    int ans = INT_MAX;
    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) { // if city not visited
            int newAns = dist[pos][city] + tsp_recursive(mask | (1 << city), city, dist, n);
            ans = min(ans, newAns);
        }
    }
    return ans;
}

// Top Down Dynamic Programming (Memoization)

int tsp_memoization(int mask, int pos, vector<vector<int>>& dist, vector<vector<int>>& dp, int n) {
    if (mask == (1 << n) - 1)
        return dist[pos][0];

    if (dp[mask][pos] != -1)
        return dp[mask][pos];

    int ans = INT_MAX;
    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) {
            int newAns = dist[pos][city] + tsp_memoization(mask | (1 << city), city, dist, dp, n);
            ans = min(ans, newAns);
        }
    }
    return dp[mask][pos] = ans;
}

// Bottom Up Dynamic Programming (Tabulation)

int tsp_tabulation(vector<vector<int>>& dist, int n) {
    int N = 1 << n;
    vector<vector<int>> dp(N, vector<int>(n, INT_MAX));
    dp[1][0] = 0; // start from city 0

    for (int mask = 1; mask < N; mask++) {
        for (int u = 0; u < n; u++) {
            if (mask & (1 << u)) { // if u is visited
                for (int v = 0; v < n; v++) {
                    if ((mask & (1 << v)) == 0) { // if v not visited
                        int newMask = mask | (1 << v);
                        dp[newMask][v] = min(dp[newMask][v], dp[mask][u] + dist[u][v]);
                    }
                }
            }
        }
    }

    int ans = INT_MAX;
    for (int i = 1; i < n; i++) {
        ans = min(ans, dp[N - 1][i] + dist[i][0]); // return to start
    }
    return ans;
}

// Optimized Bottom Up Dynamic Programming 

int tsp_optimization(vector<vector<int>>& dist, int n) {
    int N = 1 << n;
    vector<int> prev(n, INT_MAX), curr(n, INT_MAX);
    prev[0] = 0;

    for (int mask = 1; mask < N; mask++) {
        fill(curr.begin(), curr.end(), INT_MAX);
        for (int u = 0; u < n; u++) {
            if (mask & (1 << u)) {
                for (int v = 0; v < n; v++) {
                    if ((mask & (1 << v)) == 0) {
                        int newMask = mask | (1 << v);
                        curr[v] = min(curr[v], prev[u] + dist[u][v]);
                    }
                }
            }
        }
        prev = curr;
    }

    int ans = INT_MAX;
    for (int i = 1; i < n; i++) {
        ans = min(ans, prev[i] + dist[i][0]);
    }
    return ans;
}