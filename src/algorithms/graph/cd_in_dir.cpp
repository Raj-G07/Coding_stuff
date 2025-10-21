// Cycle Detection in Directed Graph

#include <iostream>
#include <vector>
using namespace std;

bool hasCycleDirected(int node, vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &recStack)
{
    visited[node] = true;
    recStack[node] = true;

    for (auto it : adj[node])
    {
        if (!visited[node])
        {
            if (hasCycleDirected(it, adj, visited, recStack))
                return true;
        }
        else if (recStack[node])
        {
            return true;
        }
    }
    recStack[node] = false;
    return false;
}