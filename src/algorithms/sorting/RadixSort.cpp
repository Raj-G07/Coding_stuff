// Radix sort is efficient for fixed-length digit keys and performs well when sorting numbers or strings of uniform length.

#include "../include/algorithms/sorting/RadixSort.h"

int getDigit(int num,int exp){
    return (num/exp)%10;
}

void countingSort(vector<int>& arr,int exp) {
    int n = arr.size();
    int largest = *max_element(arr.begin(),arr.end());
    vector<int>count(largest+1,0);
    for(auto it:arr){
        int digit = getDigit(it,exp);
        count[digit]++;
    }
    for(int i=1;i<=largest;i++){
       count[i]+= count[i-1];
    }
    vector<int>output(n);
    for(int i=n-1;i>=0;i--){
        int digit = getDigit(arr[i],exp);
        output[count[digit]-1]=arr[i];
        count[digit]--;
    }
    for(int i=0;i<n;i++){
        arr[i]=output[i];
    }
}

void radixSort(vector<int>&arr){
    int maxVal = *max_element(arr.begin(),arr.end());
    for(int exp = 1 ;maxVal/exp>0;exp+=10){
        countingSort(arr,exp);
    }
}