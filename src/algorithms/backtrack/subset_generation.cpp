#include <iostream>
#include <vector>

using namespace std;
// Approach 1: Backtracking 
void generateSubsets(vector<int> &nums, vector<int> &subset, int index)
{
    for (int num : subset)
    {
        cout << num << " ";
    }
    cout << endl;
    // Generate further subsets
    for (int i = index; i < nums.size(); i++)
    {
        subset.push_back(nums[i]);
        generateSubsets(nums, subset, i + 1);
        subset.pop_back(); // Backtrack
    }
}

// Approach 2: Bitmasking

void generateSubsets(vector<int>& nums) {
    int n = nums.size();
    int totalSubset = 1<<n;
    for(int mask=0;mask<totalSubset;mask++){
        vector<int>subsets;
        for(int i=0;i<n;i++){
            if(mask&&(1>>i)){
               subsets.push_back(nums[i]);
            }
        }
        for(auto it:subsets){
            cout<<it<<" ";
        }
        cout<<endl;
    }
}