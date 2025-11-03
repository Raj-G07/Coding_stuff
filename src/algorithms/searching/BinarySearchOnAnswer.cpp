// Classic Example - Aggresive Cows
// You have n stalls and k cows. Place cows such that the minimum distance between any tow cows is maximized.

#include <bits/stdc++.h>
using namespace std;
bool canPlaceCows(vector<int> &stalls, int k, int dist)
{
    int cnt = 1;
    int last = stalls[0];
    for (int i = 1; i < stalls.size(); i++)
    {
        if (stalls[i] - last >= dist)
        {
            cnt++;
            last = stalls[i];
        }
    }
    return cnt >= k;
}
int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    int low = 1;
    int high = stalls.back() - stalls.front();
    int ans = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (canPlaceCows(stalls, k, mid))
        {
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return ans;
}