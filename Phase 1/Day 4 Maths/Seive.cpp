#include<bits/stdc++.h>
using namespace std;

#define lli long long int
#define endl "\n";

vector<int> primes(100100, 1);

void seive(int n) {
	primes[0] = 0;
	primes[1] = 0;

	for (int i = 2; i * i <= n; i++) { // (N)
		if (primes[i]) {
			for (int j = i * i; j <= n; j += i) {   // O(N/i)
				primes[j] = 0;
			}
		}
	}

	// N/2 + N/3 + N/5 ... N/N
	// N * (1/2 + 1/3 + 1/5 ... + 1/N)
	// N * sum of primes i to N --> 1/p --> it is log(log(N))
	// N * log(log(N))
}

void solve() {
	int n;
	cin >> n;

	seive(n);

	// print all the prime
	for (int i = 0; i <= n; i++) if (primes[i]) cout << i << endl;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}