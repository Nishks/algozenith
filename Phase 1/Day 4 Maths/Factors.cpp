#include<bits/stdc++.h>
using namespace std;

#define lli long long int
#define endl "\n";

void Factors(int x) {
	vector<int> ans;

	for (int i = 1; i * i <= x; i++) {
		if (x % i == 0) {
			ans.push_back(i);
			if (i * i != x) ans.push_back(x / i);
		}
	}

	for (auto it : ans) cout << it << " ";
	cout << endl;

}

void solve() {
	int n;
	cin >> n;

	Factors(n);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}