// Bipartite Graph Check 
// BFS Approach 
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

bool BFS(int n, vector<vector<int>>& adj,vector<int>&dis) {
    queue<int>q;
    q.push(0);
    dis[0]=1;
    while(!q.empty()){
        auto top = q.front();
        q.pop();
        for(auto it:adj[top]){
            if(!dis[it]){
                dis[it] = -dis[top]+3;
                q.push(it);
            }else if(dis[it]==dis[top]) return false;
        }
    }
    return true;
}

bool isBipartite(int n,vector<vector<int>>&adj){
    vector<int>dis(n,0);
    for(int i=0;i<n;i++){
       if(!dis[i]){
        if(!BFS(i,adj,dis)) return false;
       }
    }
    return true;
}