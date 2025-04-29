// don't think just do

#include <bits/stdc++.h>
#define int long long int
#define endl "\n"
using namespace std;

vector<vector<pair<int,int>>> adj;

struct UnionFind {
	int n, set_size, *parent, *rank;
	UnionFind(){}
	UnionFind(int a){n = set_size = a;parent = new int[n+1];rank = new int[n+1];
		for(int i = 1; i <= n; i++){parent[i] = i,rank[i] = 1;}
	}
	int find(int x){
		if(x != parent[x])
			return parent[x] = find(parent[x]);
		return x;
	}
	void merge(int x, int y){int xroot = find(x), yroot = find(y);
		if(xroot != yroot){
			if(xroot < yroot){
				parent[xroot] = yroot;rank[yroot] += rank[xroot];}
			else {
				parent[yroot] = xroot;rank[xroot] += rank[yroot];}
			set_size--;
		}
	}   
	void reset(){
		n=set_size; for(int i = 1; i <= n; i++) parent[i] = i, rank[i] = 1;
	}
	int size(){return set_size;}
	void print(){for(int i = 1; i <= n; i++) cout << i << " -> " << parent[i] << endl;}
};

void solve() {
	// cout << "let's get it done" << endl;
	int n, m;
	cin >> n >> m;
	adj.resize(n+1, vector<pair<int,int>> ());
	UnionFind uf(n);
	vector<pair<int,pair<int,int>>> edge_list;
	for(int i = 0; i < m; i++){
		int a,b,c;
		cin >> a >> b >> c;
		edge_list.push_back({c, {a,b}});
	}
	sort(edge_list.begin(), edge_list.end());
	int mst_cost = 0;
	int count_of_edge_added = 0;

	for(auto v : edge_list){
		int x = v.second.first;
		int y = v.second.second;

		if(uf.find(x) != uf.find(y)){
			count_of_edge_added++; // This added edge count will tell you the MST is possible or not
			mst_cost += v.first;
			uf.merge(x,y);
			// this will give you the MST
			adj[x].push_back({y, v.first});
			adj[y].push_back({x, v.first});
		}

	}

	if(count_of_edge_added != n-1){
		cout << "NO MST FOUND" << endl;
		return;
	}

	cout << mst_cost << endl;
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
	// cin >> t;
	while (t--) solve();
}
    