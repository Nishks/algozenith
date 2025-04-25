#include<bits/stdc++.h>
using namespace std;

#define lli long long int
#define endl "\n"
#define ii pair<int,int>

void primefactors(int x) {
	vector<ii> ans;

	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			int count = 0;
			while (x % i == 0) {
				count++;
				x /= i;
			}
			ans.push_back({i, count});
		}
	}

	// This is the prime factor which is greater than sqrt(x)
	if (x > 1) {
		ans.push_back({x, 1});
	}


	for (auto it : ans) cout << "prime " << it.first << " power " << it.second << endl;
}

void solve() {
	int x;
	cin >> x;

	primefactors(x);
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}