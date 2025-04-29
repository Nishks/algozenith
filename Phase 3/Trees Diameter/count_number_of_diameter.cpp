// Write your code here

// you can set your Template at profile settings [https://maang.in/profile/edit-profile]
      
// don't think just do

#include <bits/stdc++.h>
#define lli long long int
#define endl "\n"
using namespace std;

using pi = pair<int,int>;
vector<vector<int>> g;
vector<int> dep(200010);
vector<int> par(200010);

void dfs(int node, int parent, int depth){
    dep[node] = depth;
    par[node] = parent;
    for(auto child : g[node]){
        if(child != parent)
            dfs(child, node, depth+1);
    }
}

lli count_leaf_nodes(int node, int parent ,lli dist, lli diameter){
    lli leafNodes = 0;
    if(dist == diameter) leafNodes++;
    for(auto child : g[node]){
        if(child != parent)
            leafNodes += count_leaf_nodes(child, node, dist+1, diameter);
    }
    return leafNodes;
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

    // edge case
    if(n==1){
        cout<<1;
        return;
    }

    dfs(1,0,0);
    int maxi = 1;
    for(int i = 2; i < 200010; i++){
        if(dep[i] > dep[maxi]) maxi = i;
    }

    dfs(maxi,0,0);
    for(int i = 1; i < 200010; i++){
        if(dep[i] > dep[maxi]) maxi = i;
    }

    if(dep[maxi]&1){
        int center1 = maxi;
        int center2 = 0;
        int centerDistance = dep[maxi]/2;
        while(centerDistance--){
            center1 = par[center1];
        }
        center2 = par[center1];
        centerDistance = dep[maxi]/2;
        
        lli first = count_leaf_nodes(center1, center2, 0, centerDistance);
        lli second = count_leaf_nodes(center2, center1, 0, centerDistance);
        cout << first * second << endl;
        return;
    }  // if diameter is odd , it means there are more than 1 center so return -1;

    // if diameter is even length
    int centerDistance = dep[maxi]/2;
    int center = maxi;
    while(centerDistance--){
        center = par[center];
    }

    centerDistance = dep[maxi]/2;
    lli ans = 0, sum = 0;
    vector<int> list;
    for(auto child : g[center]){
        int count = count_leaf_nodes(child, center, 1, centerDistance);
        sum += count;
        list.push_back(count);
    }

    for(auto it : list){
        ans += 1LL * it * (sum-it);
        sum-=it;
    }
    cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	int t = 1;
	while(t--) solve();
}