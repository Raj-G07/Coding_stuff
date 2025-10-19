// Prim's Algorithm is another Greedy Algorithm for MST. It grows the MST one vertex at a time, starting from an arbitrary vertex, by adding the smallest edge that connects a vertex in the MST to a vertex outside the MST.

#include <iostream> 
#include <vector> 
#include <climits> 
using namespace std;    
int primMST(int V, vector<vector<int>> &graph) {
    vector<bool> inMST(V, false);
    vector<int> key(V, INT_MAX);
    key[0] = 0; 
    int totalWeight = 0;

    for (int count = 0; count < V - 1; count++) {
        int minKey = INT_MAX, u;
        for (int v = 0; v < V; v++) {
            if (!inMST[v] && key[v] < minKey) {
                minKey = key[v];
                u = v;
            }
        }

        inMST[u] = true;
        totalWeight += minKey;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }

    return totalWeight;
}