// Kruskal's Algorithm is a Greedy Algorithm to find the MST. It sorts all edges by weight and incrementally adds the smallest edge to the tree, ensuring no cycles.

#include <iostream> 
#include <vector> 
#include <algorithm> 
using namespace std;
struct Edge {
    int src, dest, weight;
};
bool edgeCompare(Edge a, Edge b) {
    return a.weight < b.weight;
}
struct DisjointSet {
    vector<int> parent, rank;
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int find(int u) {
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }
    void unionSets(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV) {
            if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};
vector<Edge> kruskalMST(int V, vector<Edge> &edges) {
    sort(edges.begin(), edges.end(), edgeCompare);
    DisjointSet ds(V);
    vector<Edge> mst;
    for (const auto &edge : edges) {    
        int u = edge.src;
        int v = edge.dest;
        if (ds.find(u) != ds.find(v)) {
            ds.unionSets(u, v);
            mst.push_back(edge);
        }
    }
    return mst;
}   