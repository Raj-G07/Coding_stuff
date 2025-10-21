#include "algorithms/graph/dfs.h"

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node]=true;
    for(auto it:adj[node]){
        if(!visited[node]) {
            dfs(it,adj,visited);
        }
    }
}