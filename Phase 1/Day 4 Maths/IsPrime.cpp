// don't think just do

#include <bits/stdc++.h>
#define lli long long int
#define endl "\n"
using namespace std;

bool isPrime(int x){
	if(x == 1) return false;	
	for(int i = 2; i*i <= x; i++){
		if(x%i == 0) return false;
	}
	return true;
}

void solve(){
	// cout << "let's get it done" << endl;
	int n;
	cin >> n;

	cout << isPrime(n) << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	while(t--) solve();
}