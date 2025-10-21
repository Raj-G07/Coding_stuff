// Floyd Warshall is used to find the shortest path between all pairs of nodes in a graph. It handles negative weights but not negative weight cycles. 

#include <iostream> 
#include <vector> 
#include <climits> 
using namespace std; 
void floydWarshall(int n, vector<vector<int>>& graph) {
    vector<vector<int>> dist = graph;
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dist[i][j]>dist[i][k]+dist[k][j] && dist[i][k]!=INT_MAX && dist[k][j]!=INT_MAX){
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }
}

// In this algo, the order of loops (k->i->j) is crucial for correctness. The outermost loop must iterate over k, the intermediate vertex, because the algorithm progressively allows more intermediate vertices as potential parts fo the path.