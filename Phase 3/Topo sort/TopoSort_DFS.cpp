// don't think just do

#include <bits/stdc++.h>
#define int long long int
#define endl "\n"
using namespace std;

vector<vector<int>> g;

vector<int> vis;
vector<int> topo;

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
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
	}

	vis.resize(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) dfs(i);
	}

	// to get topological ordering or the DAG

	reverse(topo.begin(), topo.end());
	for (auto it : topo) cout << it << " ";
	cout << endl;

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