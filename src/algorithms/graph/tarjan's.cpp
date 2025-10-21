// Tarjan’s Algorithm for SCC (Strongly Connected Components)

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

void tarjanDFS(int node, vector<vector<int>> &adj, vector<int> &disc, vector<int> &low, stack<int> &st, vector<bool> &inStack, int &time, vector<vector<int>> &sccs)
{
    disc[node] = low[node] = time++;
    st.push(node);
    inStack[node] = true;
    for (int neighbor : adj[node])
    {
        if (disc[neighbor] == -1)
        {
            tarjanDFS(neighbor, adj, disc, low, st, inStack, time, sccs);
            low[node] = min(low[node], low[neighbor]);
        }
        else if (inStack[neighbor])
        {
            low[node] = min(low[node], disc[neighbor]);
        }
    }
    if (low[node] == disc[node])
    {
        vector<int> scc;
        while (true)
        {
            int top = st.top();
            st.pop();
            inStack[top] = false;
            scc.push_back(top);
            if (top == node)
                break;
        }
        sccs.push_back(scc);
    }
}

void findSCCs(int n, vector<vector<int>> &adj)
{
    vector<int> disc(n, -1), low(n, -1);
    vector<bool> inStack(n, false);
    stack<int> st;
    vector<vector<int>> sccs;
    int time = 0;
    for (int i = 0; i < n; i++)
    {
        if (disc[i] == -1)
        {
            tarjanDFS(i, adj, disc, low, st, inStack, time, sccs);
        }
    }
    // Print all SCCs
    for (auto &scc : sccs)
    {
        cout << "SCC: ";
        for (int node : scc)
        {
            cout << node << " ";
        }
        cout << "\n";
    }
}