// Bellman Ford works for graphs with negative weights but detects negative weight cycles. 
#include "algorithms/graph/bellmann_ford.h"

void bellmanFord(int src, int n, vector<vector<int>>& edges) {
    vector<int>dis(n,0);
    dis[src]=0;
    for(int i=0;i<n-1;i++){
        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            if(dis[u]!=INT_MAX && dis[u]+w<dis[v]){
                dis[v] = dis[u] + w;
            }
        }
    }
    for(auto it:edges){
        int u = it[0];
        int v = it[1];
        int w = it[2];
        if(dis[u]!=INT_MAX && dis[u]+w<dis[v]){
            cout << "Graph contains a negative weight cycle.\n"; 
            return;
        }
    }
}