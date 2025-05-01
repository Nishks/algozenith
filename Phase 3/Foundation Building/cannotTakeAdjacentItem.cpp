// don't think just do

#include <bits/stdc++.h>
#define int long long int
#define endl "\n"
using namespace std;

int n;
int w[3003];
int v[3003];
int W,k,M;

int dp[101][1001][101];

int rec(int i, int x, int item_left){
	// pruning 
	// basecase
	if(i == n) {
        int sum_of_take = W-x; // weight of totalItems - remaining item.
        if((sum_of_take)%M == 0) return 0; // Valid solution
    }
    else return -1e9; // Invalid solution

	// cache check
	if(dp[i][x][item_left] != -1) return dp[i][x][item_left];

    // New Transition
    int ans = rec(i+1,x, item_left);
    if(w[i] <= x and item_left > 0) ans = max(ans, rec(i+2, x-w[i], item_left-1) + v[i]);

	// save and return
	return dp[i][x][item_left] = ans;	
}

void solve() {
	// cout << "let's get it done" << endl;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> w[i];
	for(int i = 0; i < n; i++) cin >> v[i];
	cin >> W,k,M;

	memset(dp, -1 , sizeof(dp));

	cout << rec(0, W, k) << endl;
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
    