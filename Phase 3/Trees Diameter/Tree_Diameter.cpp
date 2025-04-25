// Write your code here

// you can set your Template at profile settings [https://maang.in/profile/edit-profile]
      
// don't think just do

#include <bits/stdc++.h>
#define lli long long int
#define endl "\n"
using namespace std;

using pi = pair<int,int>;

vector<vector<int>> g;
int dep[200010];
int par[200010];

void dfs(int node, int parent, int depth){
    dep[node] = depth;
    par[node] = parent;

    for(auto v : g[node]){
        if(par[node] != v){
            dfs(v, node, depth + 1);
        }
    }
} 

void solve(){
    g.clear();
    g.resize(200010);

    int n;
    cin >> n;

    for(int i = 1; i < n; i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1,0,0);
    int maxi = 1;
    for(int i = 2; i < 200010; i++){
        if(dep[i] > dep[maxi]){
            maxi = i;
        }
    }

    dfs(maxi, 0, 0);
    for(int i = 1; i < 200010; i++){
        if(dep[i] > dep[maxi]){
            maxi = i;
        }
    }

    cout << dep[maxi] << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    while(t--){
        solve();
    }
}