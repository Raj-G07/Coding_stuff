// Cycle Detection in Undirected Graph 

#include <iostream> 
#include <vector> 
using namespace std;

bool hasCycleUndirected(int node, int parent, vector<vector<int>>& adj, vector<bool>& visited) {
      visited[node]=true;
      for(auto it:adj[node]){
        if(!visited[it]){
            if(hasCycleUndirected(it,node,adj,visited)) return true;
        }else if (it!=parent){
            return true;
        }
      }
      return false;
}