// Binary Lifting is a preprocessing technique used on trees to efficiently answer queries like:

// Find the Lowest Common Ancestor (LCA) of two nodes

//It works by precomputing ancestors at powers of two — i.e.,
//for every node v, we store:
// up[v][j] = 2^j-th ancestor of v

#include <bits/stdc++.h>
#include "./kth_ancestor.cpp"
using namespace std;

const int N = 1e5;
const int LOG = 20;
vector<int> adj[N+1];
int up[N+1][LOG]; // up[v][j] is the 2^j-th ancestor of v
int depth[N+1];

void dfs(int v,int p){
    up[v][0] = p;
    for(int j=1;j<LOG;j++){
        up[v][j] = up[up[v][j-1]][j-1];
        if(up[v][j] == -1) break;
    }

    for(int u: adj[v]){
        if(u != p){
            depth[u] = depth[v] + 1;
            dfs(u,v);
        }
    }
}

int lca(int u,int v){
    if(depth[u] < depth[v]) swap(u,v);

    // Lift u to the same depth as v
    u = kth_ancestor(u, depth[u] - depth[v]);
    if(u == v) return u;

    // Lift both u and v until their parents are the same
    for(int j=LOG-1;j>=0;j--){
        if(up[u][j] != up[v][j]){
            u = up[u][j];
            v = up[v][j];
        }
    }

    return up[u][0]; // or up[v][0], both are same here
}