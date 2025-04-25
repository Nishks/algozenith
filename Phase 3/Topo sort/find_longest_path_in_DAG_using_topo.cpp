// don't think just do

#include <bits/stdc++.h>
#define int long long int
#define endl "\n"
using namespace std;

vector<vector<int>> g;
vector<int> vis;
vector<int> topo;
vector<int> dp(100100);

void dfs(int node) {
	vis[node] = 1;
	for (auto v : g[node]) {
		if (!vis[v]) dfs(v);
	}
	topo.push_back(node);
}

void solve() {
	// cout << "let's get it done" << endl;
	int n, m;
	cin >> n >> m;
	g.resize(n + 1);
	vis.resize(n + 1, 0);
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
	}

	// since you are doing it iteratively
	// you have to know the answer of smaller
	// problems so that you can calculate the
	// answer of bigger problem that depends.
	// on smaller one.
	// Do no reverse topo sort. and it have.
	// dependency in reverse order.

	int total = 0;
	for (int i = 0; i < topo.size(); i++) {
		int num = topo[i];
		int ans = 1;
		for (auto v : g[num]) {
			ans = max(ans, 1 + dp[v]);
		}
		dp[node] = ans;
		total = max(total, dp[node]);
	}

	cout << total << endl;

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