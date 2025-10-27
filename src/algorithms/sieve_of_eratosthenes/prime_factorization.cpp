#include<iostream>
#include<vector>

using namespace std;

vector<pair<int,int>> prime_factorization(int n) {
    vector<pair<int,int>> factors;
    for (int i = 2; i * i <= n; ++i) {
        int count = 0;
        while (n % i == 0) {
            n /= i;
            count++;
        }
        if (count > 0) {
            factors.emplace_back(i, count);
        }
    }
    if (n > 1) {
        factors.emplace_back(n, 1);
    }
    return factors;
}
