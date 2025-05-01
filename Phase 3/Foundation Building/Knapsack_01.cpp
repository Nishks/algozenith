// don't think just do

#include <bits/stdc++.h>
#define int long long int
#define endl "\n"
using namespace std;

int n;
int w[3003];
int v[3003];
int W;

int dp[3003][3003];

int rec(int i, int x){
	// pruning 
	// basecase
	if(i == n) return 0;

	// cache check
	if(dp[i][x] != -1) return dp[i][x];
	// transition
	int ans = rec(i+1, x);
	if(w[i] <= x) ans = max(ans, rec(i+1, x-w[i]) + v[i]);

	// save and return
	return dp[i][x] = ans;	
}

// print solution
vector<int> solution;
void generateSolution(int i, int x){
	if(i == n) return;

	int dontTake = rec(i+1 , x);
	if(w[i] <= x){
		// can possibly take
		int take = rec(i+1, x-w[i]) + v[i];
		// don't Take is of higher value than take, simply generateSolution for i+1,x state.
		if(dontTake > take) generateSolution(i+1, x);
		else{ // take is higher than don't take pick this index i for solution and
			// move to next state to generateSolution
			solution.push_back(i);
			generateSolution(i+1, x-w[i]);
		}
	}
	else {
		// can't take
		generateSolution(i+1, x);
	}
}

void solve() {
	// cout << "let's get it done" << endl;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> w[i];
	for(int i = 0; i < n; i++) cin >> v[i];
	cin >> W;

	memset(dp, -1 , sizeof(dp));

	cout << rec(0, W) << endl;
	generateSolution(0,W);
	cout << solution.size() << endl;
	for(auto it : solution) cout << it << " ";
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
	// cin >> t;
	while (t--) solve();
}
    