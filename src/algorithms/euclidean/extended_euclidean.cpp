// The Extended Euclidean Algorithm not only finds the GCD of two numbers but 
// also computes coefficients x and y such that: 
// ax+by=GCD(a,b) 
// Modular Inverse (Full Concept)

/*We already know that for prime modulus 
m:𝑎−1≡𝑎𝑚−2(mod𝑚)

But what if m is not prime?
Then we use the Extended Euclidean Algorithm.

🧠 Equation:𝑎 × 𝑥 + 𝑚 × 𝑦 =  gcd⁡(𝑎,𝑚)
If gcd(a, m) = 1,
then x is the modular inverse of a mod m.
*/
#include<iostream>
using namespace std;

// Function to implement Extended Euclidean Algorithm
int extendedGCD(int a, int b, int &x, int &y) {
    // Base Case
    if (a == 0) {
        x = 0;
        y = 1;  
        return b;
    }
    int gcd = extendedGCD(b % a, a, y, x);
    y -= (b / a) * x;
    return gcd;
}