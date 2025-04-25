#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

void solve(){
    int x;
    cin >> x;
    
    if(x == 3){
        cout << 3 << endl;
        return;
    }
    else{
        cout << 2 << endl;
    }
}

int main(){
    int t;
    cin >> t;

    while(t--){
        solve();
    }
}