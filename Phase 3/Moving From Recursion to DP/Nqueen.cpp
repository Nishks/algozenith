// don't think just do

#include <bits/stdc++.h>
#define int long long int
#define endl "\n"
using namespace std;

int n;
int queen[20]; // queen[i] --> where is my queen in row i, col = queen[i]

bool check(int row, int col){
	for(int i = 0; i < row; i++){
		int prevRow = i;
		int prevCol = queen[i];

		if(prevCol == col || abs(col-prevCol) == abs(row-prevRow))
			return 0;
	}

	return 1;
}

int rec(int level){ // rec --> number of ways to populate [level .. n-1] rows for a valid
	// configuration
	// level --> row in which we are placing the queen

	// pruning


	// base case
	if(level == n) return 1;

	// compute
	int ans = 0;
	// loop over all choices , all columns for row - level
	for(int col = 0; col < n; col++){
		if(check(level, col)){
			queen[level] = col; // place the queen at row - level and col
			ans += rec(level+1); // explore the options
			queen[level]--; // revert the placed queen
		}
	}


	// return
	return ans;
}

void solve() {
	cin >> n;
	memset(queen, -1, sizeof(queen));
	cout << rec(0) << endl;
}

int32_t main() {
	ios_base::sync_with_stdio(0); 
	cin.tie(0); 
	cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t = 1;
	// cin >> t;
	while (t--) solve();
}
    