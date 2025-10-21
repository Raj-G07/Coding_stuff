// Cycle Detection Using BFS (Kahn’s Algorithm)
// For DAGs

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool detectCycleKahns(int n, vector<vector<int>> &adj)
{
    vector<int> indegree(n, 0);
    for (auto u : adj)
    {
        for (auto v : u)
        {
            indegree[v]++;
        }
    }
    queue<int> q;
    for (auto it : indegree)
    {
        if (it == 0)
        {
            q.push(it);
        }
    }
    int cnt = 0;
    while (!q.empty())
    {
        auto top = q.front();
        q.pop();
        cnt++;
        for (auto it : adj[top])
        {
            indegree[it]--;
            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }
    return cnt != n;
}