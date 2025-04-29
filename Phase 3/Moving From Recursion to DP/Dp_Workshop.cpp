// don't think just do

#include <bits/stdc++.h>
#define int long long int
#define endl "\n"
using namespace std;

int n;
int t[1001];
int s[1001];
int x,k;

int taken[1001];

book check(int level){
	int timeTaken = 0;
	int itemTaken = 0;
	for(int i = 0; i < level; i++){
		if(taken[i]){
			timeTaken += t[i];
			itemTaken += 1;
		}
	}

	// now try taking this level item
	timeTaken += t[level];
	itemTaken += 1;

	if(itemTaken <= x and itemTaken <= k) return true
	return false;
}

int rec(int level){ // max skill I can make from [level to n-1]
	// level --> current item in [0 to n-1]

	// pruning

	// base case
	if(level == n) return 0;

	// compute
	// loop over choice
	// choice 1 : don't take
	int ans = rec(level+1);

	// choice 2 : take
	if(check(level)){
		// place the change
		taken[level] = 1;
		// move
		ans = max(ans, s[level] + rec(level+1)); // max skill [level+1 .. n-1]
		// revert the change
		taken[level] = 0;
	}


	// return
	return ans;
}


void solve() {
	// cout << "let's get it done" << endl;
	int n;
	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> t[i] >> s[i];
	}
	cin >> x >> k;

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

	int t;
	cin >> t;
	while (t--) solve();
}
    