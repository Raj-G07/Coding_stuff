// The Segmented Sieve Algorithm is an optimization of the Sieve of Eratosthenes that is used to find prime numbers in a specific range [L,R], where R can be very large. It reduces memory usage by only considering numbers within the range instead of generating primes up to R. 

#include "./structure.cpp"
#include <cmath>
void segmentedSieve(int l,int r){
    vector<int> base_primes = sieveOfEratosthenes(sqrt(r));
    int size = r - l + 1;
    vector<int> is_prime(size,1);
    for(auto prime:base_primes){
        int start = max(prime * prime, (l + prime - 1) / prime * prime);
        for (int j = start; j <= r; j += prime) {
            is_prime[j - l] = 0;
        }
    }
    for (int i = 0; i < size; i++) {
        if (is_prime[i]) {
            cout << i + l << " ";
        }
    }
}


