// Topological Sorting 

#include <iostream> 
#include <vector> 
#include <stack> 

using namespace std; 

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st) {
     visited[node]=true;
     for(auto it:adj[node]){
        if(!visited[it]){
            dfs(it,adj,visited,st);
        }
     }
     st.push(node);
}

void topologicalSort(int n, vector<vector<int>>& adj) {
    stack<int>st;
    vector<bool>visited(n,0);
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(i,adj,visited,st);
        }
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}