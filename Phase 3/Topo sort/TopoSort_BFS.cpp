// don't think just do

#include <bits/stdc++.h>
#define int long long int
#define endl "\n"
using namespace std;

vector<vector<int>> g;
vector<int> indeg;

vector<int> topo;
void kahn() {
	queue<int> q;
	for (int i = 1; i < indeg.size(); i++) {
		if (indeg[i] == 0) q.push(i);
	}

	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		topo.push_back(curr);
		for (auto v : g[curr]) {
			indeg[v]--;
			if (indeg[v] == 0) {
				q.push(v);
			}
		}
	}
}

void solve() {
	// cout << "let's get it done" << endl;
	int n, m;
	cin >> n >> m;
	g.resize(n + 1);
	indeg.resize(n + 1, 0);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		indeg[b]++;
	}

	kahn();

	if (topo.size() != n) cout << "cycle is present " << endl;
	else for (auto it : topo) cout << it << " ";
	cout << endl;

}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

	int t = 1;
	while (t--) solve();
}