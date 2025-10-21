// Graph Coloring 

#include <iostream> 
#include <vector> 

using namespace std; 

bool isSafe(int node, vector<vector<int>>& adj, vector<int>& color, int c) {
     for(auto it:adj[node]){
        if(color[it]==c) return false;
     }
     return true;
}

bool graphColoringUtil(vector<vector<int>>& adj, int m, int node, vector<int>& color) {
     if(node==adj.size()){
        return true;
     }
     for(int c = 1 ; c<=color.size() ; c++){
         if(isSafe(node,adj,color,c)){
            color[node]=c;
            if(graphColoringUtil(adj,m,node+1,color)){
                return true;
            }
            color[node]=0;
         }
     }
     return false;
}

bool graphColoring(vector<vector<int>>& adj, int m) {
     int n = adj.size();
     vector<int>color(n,0);
     if(!graphColoringUtil(adj,m,0,color)){
        cout << "Solution does not exist with " << m << " colors." << endl; 
        return false;
     }
     return true;
}