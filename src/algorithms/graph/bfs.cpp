#include "algorithms/graph/bfs.h"

void bfs(int start, vector<vector<int>>& adj, vector<bool>& visited) {
    queue<int>q;
    q.push(start);
    visited[start]=true;
    while(!q.empty()){
       auto front = q.front();
       q.pop();
       for(auto it:adj[front]){
        if(!visited[it]){
            visited[it]= true;
            q.push(it);
        }
       }
    }
}