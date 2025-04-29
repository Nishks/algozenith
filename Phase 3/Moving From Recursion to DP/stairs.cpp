// don't think just do

#include <bits/stdc++.h>
#define int long long int
#define endl "\n"
using namespace std;

int n;
int rec(int level){ // retrun --> number of way to N if we are st stair level
	// level -> stair i am at.

	// pruning
	if(level > n) return 0; // redundant step as check is already in place before taking
	// step

	// base case
	if(level == n) return 1;

	int ans = 0;
	// loop over choice
	for(int step = 1; step = 3; step++){
		if(level + step <= n){ // check --> is a valid choice
			int ways = rec(level + step); // move
			ans += ways;
		}
	}

	return ans;
}

void solve() {
	// cout << "let's get it done" << endl;
	cin >> n;
	rec(1);
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
    