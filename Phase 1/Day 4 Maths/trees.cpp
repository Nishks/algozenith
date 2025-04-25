// don't think just do

#include <bits/stdc++.h>
#define lli long long int
#define endl "\n"
using namespace std;

vector<int> adj[200005];
vector<int> sub(200006);

void dfs(int node, int parent) {
	int count = 0;
	for (auto child : adj[node]) {
		if (child != parent) {
			dfs(child, node);
			count += (1 + sub[child]);
		}
	}

	sub[node] = count;
}

void solve() {
	// cout << "let's get it done" << endl;
	int n;
	cin >> n;

	for (int i = 2; i <= n; i++) {
		int x;
		cin >> x;
		adj[i].push_back(x);
		adj[x].push_back(i);
	}

	dfs(1, 0);

	for (int i = 1; i <= n; i++) cout << sub[i] << " ";
	cout << endl;

}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t = 1;
	while (t--) solve();
}