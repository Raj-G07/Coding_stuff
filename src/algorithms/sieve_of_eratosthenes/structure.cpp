// The Sieve of Eratosthenes is an efficient algorithm for finding all prime numbers up to a given number N. It works by iteratively marking the multiples of each prime number starting from 2.

#include <iostream>
#include <vector>

using namespace std;

vector<int> sieveOfEratosthenes(int n)
{
    vector<int> primes(n + 1, 1); // Initialize a boolean array to track prime status
    primes[0] = primes[1] = 0;    // 0 and
    for (int i = 2; i * i <= n; i++)
    {
        if (primes[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                primes[j] = 0; // Mark multiples of i as non-prime
            }
        }
    }
    vector<int> base_primes;
    for (int i = 2; i <= n; i++)
    {
        if (primes[i])
            base_primes.push_back(i);
    }
    return base_primes;
}