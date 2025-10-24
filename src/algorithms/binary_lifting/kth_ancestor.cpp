// Binary Lifting is a preprocessing technique used on trees to efficiently answer queries like:

// Find the k-th ancestor of a node

// It works by precomputing ancestors at powers of two — i.e.,
// for every node v, we store:
// up[v][j] = 2^j-th ancestor of v`

#include<iostream>
#include<vector>

using namespace std;

const int N = 1e5;
const int LOG = 20; // Because 2^20 > 10^6
int up[N+1][LOG]; // up[v][j] is the 2^j-th ancestor of node v

int depth[N+1]; // depth of each node in the tree
vector<int> adj[N+1]; // adjacency list of the tree

void dfs(int v,int p){
    up[v][0]=p;
    for(int j=1;j<LOG;j++){
        if(up[v][j-1]!=-1)
            up[v][j] = up[up[v][j-1]][j-1];
        else 
            up[v][j] = -1;
    }

    for(int u:adj[v]){
        if(u!=p){
            depth[u]=depth[v]+1;
            dfs(u,v);
        }
    }
}

int kth_ancestor(int v,int k){
    for(int j=0;j<LOG;j++){
        if(k & (1<<j)){
            v = up[v][j];
            if(v==-1) break; 
        }
    }
    return v;
}




