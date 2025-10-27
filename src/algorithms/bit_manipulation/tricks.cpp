// Counting subsets of a set using bit manipulation
#include <iostream>
#include <vector>  

using namespace std;

// Common tricks
// x & (x-1) → removes the lowest set bit.
// Popcount
// Count 1s in binary:
// __builtin_popcount(x); // in C++

int ceil_div(int a, int b) {
    return (a + b - 1) / b;
}

int countSubsets(int n) {
    return 1 << n; // 2^n subsets
}