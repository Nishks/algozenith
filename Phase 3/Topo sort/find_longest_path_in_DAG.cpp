// don't think just do

#include <bits/stdc++.h>
#define int long long int
#define endl "\n"
using namespace std;

vector<vector<int>> g;
vector<int> dp(100100);

// find longest path in DAG

int recursion(int node) { // dp[i] returns the longest path starting from node
	if (dp[node] != -1) return dp[node];
	int ans = 1; // current node will always be the answer
	for (auto v : g[node]) {
		ans = max(ans, 1 + recursion(v));
	}
	return dp[node] = ans;
}

void solve() {
	// cout << "let's get it done" << endl;
	int n, m;
	cin >> n >> m;
	g.resize(n + 1);
	memset(dp, -1, sizeof(dp));

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, recursion(i));
	}
	cout << ans << endl;
}

int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

	int t = 1;
	while (t--) solve();
}