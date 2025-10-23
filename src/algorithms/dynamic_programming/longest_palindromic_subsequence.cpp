// Longest Palindromic Subsequence (LPS)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int longestPalindromicSubsequence(string S)
{
    int n = S.length();
    string S_rev = S;
    reverse(S_rev.begin(), S_rev.end());

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (S[i - 1] == S_rev[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][n];
}