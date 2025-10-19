// The Coin Change Problem involves finding the minimum number of coins needed to make a given amount (or counting the ways to make the amount). 

#include <iostream> 
#include <vector> 
#include <climits> 
using namespace std;

int minCoins(vector<int> coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0; // Base case: 0 coins are needed to make amount 0

    for (int coin : coins) {
        for (int x = coin; x <= amount; x++) {
            if (dp[x - coin] != INT_MAX) {
                dp[x] = min(dp[x], dp[x - coin] + 1);
            }
        }
    }

    return dp[amount] == INT_MAX ? -1 : dp[amount];
}
