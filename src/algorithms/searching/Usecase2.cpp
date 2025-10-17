//  Finding the Peak Element 

#include <iostream> 
#include <vector> 
using namespace std;

int findPeakElement(vector<int>& arr) {
    int n = arr.size();
    int left = 0 , right = n - 1;
    while(left<right){
        int mid = left + (right - left)/2;
        if((mid == 0 || arr[mid]>=arr[mid-1]) && (mid == n -1 || arr[mid]>=arr[mid+1])) return mid;
        else if (mid > 0 && arr[mid]<arr[mid-1]) right = mid -1;
        else left = mid + 1;
    }
    return -1;
}