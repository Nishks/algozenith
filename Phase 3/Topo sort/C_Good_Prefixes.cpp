#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

void solve(){
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    long long sum = 0;
    int count = 0;
    int maxi = INT_MIN;
    for(auto &it : v){
        maxi = max(maxi, it);
        sum += it;
        if(sum - maxi == maxi) count++;
    }

    cout << count << endl;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        solve();
    }
}