// Disjoint Set Union (DSU) 
// Disjoint Set Union (DSU), also known as Union-Find, is a data structure used to keep track of elements partitioned into disjoint (non-overlapping) subsets. It is widely used in graph algorithms, such as finding connected components, Kruskal's algorithm for MST, and more.

#include <iostream> 
#include <vector> 

using namespace std;

class DSU{
    private:
     vector<int>parent;
     vector<int>rank;
    
    public:
     DSU(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);

        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
     }

     int find(int x){
        if(parent[x]==x) return x;
        return parent[x] = find(parent[x]);
     }

     void unionByRank(int x,int y){
        int rootX= find(x);
        int rootY= find(y);
        if(rootX!=rootY){
            if(rank[rootX]>rank[rootY]){
                parent[rootY]=rootX;
            }else if(rank[rootY]>rank[rootX]) {
                parent[rootX]=rootY;
            }else {
                parent[rootX]=rootY;
                rank[rootY]++;
            }
        }
     }
};