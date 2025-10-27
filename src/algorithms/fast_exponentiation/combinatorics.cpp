#include <iostream>
#include<vector>
#include "algorithms/fast_exponentiation/exponentiation_by_squaring.h"
using namespace std;

const int MOD = 1e9 + 7;
const int N = 1000000; // Adjust size as needed
long long fact[N + 1];

void precompute_factorials() {
    fact[0] = 1;
    for (int i = 1; i <= N; ++i) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
}

long long nCr(int n,int r){
    if(r > n) return 0;
    return fact[n] * exp_by_squaring(fact[r], MOD-2) % MOD * exp_by_squaring(fact[n - r], MOD-2) % MOD;
}

// Pascal’s Triangle
// nCr = (n−1)C(r−1) + (n−1)Cr
// Useful for small n (like ≤1000).