const int MOD = 1e9 + 7;

int mod_add(int a, int b) {
    return ( (a % MOD) + (b % MOD) ) % MOD;
}

int mod_sub(int a, int b) {
    return ( (a % MOD) - (b % MOD) + MOD ) % MOD;
}

int mod_mul(int a, int b) {
    return ((1LL * (a % MOD) * (b % MOD))) % MOD;
}
