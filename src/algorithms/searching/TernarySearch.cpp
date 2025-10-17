// Ternary Search is a divide-and-conquer algorithm similar to Binary Search, but 
// instead of dividing the search interval in half, it divides it into three parts. It's used for searching in sorted arrays.

#include "../include/algorithms/searching/TernarySearch.h"

int ternarySearch(const vector<int>& arr, int left, int right, int target) { 
    if(left>right) return -1;
    int mid1 = left + (right-left)/3;
    int mid2 = right - (right-left)/3;

    if(arr[mid1]==target) return mid1;
    if(arr[mid2]==target) return mid2;
    
    if(arr[mid1]>target) return ternarySearch(arr,left,mid1-1,target);
    else if(arr[mid2]<target) return ternarySearch(arr,mid2+1,right,target);
    else return ternarySearch(arr,mid1-1,mid2+1,target);
}