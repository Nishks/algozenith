#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;

// Function to compute (base^exp) % mod using modular exponentiation
long long mod_exp(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp = exp / 2;
    }
    return result;
}

// Function to compute modular inverse of a under mod
long long mod_inverse(long long a, long long mod) {
    return mod_exp(a, mod - 2, mod);
}

void solve() {
    string strN;
    cin >> strN;
    
    long long N = stoll(strN);
    int m = strN.size();

    long long power_m = mod_exp(10, m, MOD);
    long long numerator = (mod_exp(power_m, N, MOD) - 1 + MOD) % MOD;
    long long denominator = (power_m - 1 + MOD) % MOD;
    long long denominator_inv = mod_inverse(denominator, MOD);

    long long sum = (numerator * denominator_inv) % MOD;
    long long VN_mod = (N * sum) % MOD;
    
    cout << VN_mod << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
