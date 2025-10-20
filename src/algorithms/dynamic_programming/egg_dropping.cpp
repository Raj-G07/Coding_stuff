// Given:
// 1. n: The number of eggs.
// 2. k: The number of floors in a building.
// Objective:
// Determine the minimum number of attempts needed to find the highest floor f (0 ≤ f ≤k)  from which the egg can be dropped without breaking.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Recursive approach
int eggDrop_recursive(int n, int k)
{
    if (k == 1 || k == 0)
        return k;
    if (n == 1)
        return k;

    int mini = INT_MAX;

    for (int f = 1; f <= k; f++)
    {
        int temp = 1 + max(eggDrop_recursive(n - 1, f - 1), eggDrop_recursive(n, k - f));
        if (temp < mini)
        {
            mini = temp;
        }
    }
    return mini;
}

// Top Down Dynamic Programming (Memoization)

int eggDrop_recursive(int n, int k, vector<vector<int>> &dp)
{
    if (k == 1 || k == 0)
        return k;
    if (n == 1)
        return k;
    if (dp[n][k] != -1)
        return dp[n][k];
    int mini = INT_MAX;

    for (int f = 1; f <= k; f++)
    {
        int temp = 1 + max(eggDrop_recursive(n - 1, f - 1), eggDrop_recursive(n, k - f));
        if (temp < mini)
        {
            mini = temp;
        }
    }
    return dp[n][k] = mini;
}

// Bottom Up Dynamic Programming (Tabulation)

int eggDrop_tabulation(int n, int k)
{
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    // Base cases
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = 0; // 0 floors
        dp[i][1] = 1; // 1 floor
    }
    for (int j = 1; j <= k; j++)
    {
        dp[1][j] = j; // 1 egg
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j <= k; j++)
        {
            dp[i][j] = INT_MAX;
            for (int f = 1; f <= j; f++)
            {
                int temp = 1 + max(dp[i - 1][f - 1], dp[i][j - f]);
                dp[i][j] = min(dp[i][j], temp);
            }
        }
    }
    return dp[n][k];
}

// Optimized Bottom Up Dynamic Programming

int eggDrop_optimized(int n, int k)
{
    vector<int> dp(n + 1, 0);
    int cnt = 0;
    while (dp[n] < k)
    {
        cnt++;
        for (int i = n; i > 0; i--)
        {
            dp[i] += 1 + dp[i - 1];
        }
    }
    return cnt;
}