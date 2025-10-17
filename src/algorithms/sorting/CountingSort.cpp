#include "../include/algorithms/sorting/CountingSort.h"

void countingSort(vector<int>& arr) {
    int n = arr.size();
    int largest = *max_element(arr.begin(),arr.end());
    vector<int>count(largest+1,0);
    for(auto it:arr){
        count[it]++;
    }
    for(int i=1;i<=largest;i++){
       count[i]+= count[i-1];
    }
    vector<int>output(n);
    for(int i=n-1;i>=0;i--){
        output[count[arr[i]]-1]=arr[i];
        count[arr[i]]--;
    }
    for(int i=0;i<n;i++){
        arr[i]=output[i];
    }
}