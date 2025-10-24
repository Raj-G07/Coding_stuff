// Sparse Table
// The Sparse Table is a data structure used for answering range queries efficiently, especially
// idempotent operations (like min, max, gcd, or sum for static data). It preprocesses the data in
// O(nlogn) time and allows queries to be answered in O(1) time.

// Sparse Table for Range Minimum Query (RMQ)

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class SparseTable
{
private:
    vector<vector<int>> table;
    vector<int> logValues;

public:
    SparseTable(vector<int> &arr)
    {
        int n = arr.size();
        int maxLog = log2(n) + 1;
        table.resize(n, vector<int>(maxLog));
        logValues.resize(n + 1);
        logValues[1] = 0;
        for (int i = 2; i <= n; i++)
        {
            logValues[i] = logValues[i / 2] + 1;
        }
        for (int i = 0; i < n; ++i)
        {
            table[i][0] = arr[i];
        }
        for (int j = 1; (1 << j) <= n; j++)
        {
            for (int i = 0; i + (1 << j) - 1 <= n; i++)
            {
                table[i][j] = min(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    // Query for the minimum in the range [L, R]
    int query(int L, int R)
    {
        int logRange = logValues[R - L + 1];
        return min(table[L][logRange], table[R - (1 << logRange) + 1][logRange]);
    }
};