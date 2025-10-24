// Binary Indexed Tree (Fenwick Tree) 
// A Binary Indexed Tree (BIT), or Fenwick Tree, is a data structure used to efficiently perform prefix 
// sum queries and updates on an array. It provides an alternative to Segment Trees, with simpler 
// implementation and lower memory usage. 

#include <iostream> 
#include <vector> 

using namespace std; 

class FenwickTree {
    private:
     vector<int>BIT;
     int n;
    
    public:
     FenwickTree(int size){
        n = size;
        BIT.resize(n+1,0);
     }
     // Update the BIT at index idx by value 
     void update(int idx,int value){
        while(idx<=n){
            BIT[idx]+=value;
            idx+=(idx& -idx); // Move to the next index;
        }
     }
     // Get prefix sum from 1 to idx 
     int prefixSum(int idx){
        int sum = 0;
        while(idx>0){
            sum+=BIT[idx];
            idx-=(idx& -idx);  // Move to the parent index;
        }
        return sum;
     }

     int rangeSum(int l,int r){
        return prefixSum(r)-prefixSum(l-1);
     }
};

int main(){
    vector<int>arr = {3,2,4,1,-1};
    int n = arr.size();

    // Create a Fenwick Tree
    FenwickTree fenwick(n);

    // Build the tree

    for(int i=0;i<n;i++){
        fenwick.update(i+1,arr[i]);  // BIT is 1-indexed
    }
    return 0;
}