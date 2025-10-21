// Dijkstra’s algorithm is used to find the shortest path in a graph with non-negative weights.
#include "algorithms/graph/dijkstra's.h"

void dijkstra(int src, int n, vector<vector<pair<int, int>>> &adj)
{
    vector<int> dis(n, INT_MAX);
    dis[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    while (!pq.empty())
    {
        auto top = pq.top();
        pq.pop();
        auto w = top.first;
        auto u = top.second;
        if (w > dis[u])
            continue;
        for (auto it : adj[u])
        {
            if ((it.second + dis[u]) < dis[it.first])
            {
                dis[it.first] = it.second + dis[u];
                pq.push({dis[it.first], it.first});
            }
        }
    }
}