#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

void solve(){
    int n,m;
    cin >> n >> m;
    vector<vector<char>> matrix(n, vector<char>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            cin >> matrix[i][j];
    }

    vector<int> rows;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(matrix[i][j] == '#'){
                rows.push_back(i);
                break;
            }
        }
    }

    if(rows.size() == 1){
        for(int col = 0; col < m; col++){
            if(matrix[rows[0]][col] == '#'){
                cout << ++rows[0] << " " << ++col << endl;
                return;
            }
        }
    }

    int main_row = rows[rows.size() / 2];
    vector<pair<int,int>> ans;
    for(int col = 0; col < m; col++){
        if(matrix[main_row][col] == '#') ans.push_back({main_row,col});
    }

    pair<int,int> result = ans[ans.size()/2];
    cout << result.first + 1 << " " << result.second + 1 << endl;


}

int main(){
    int t;
    cin >> t;

    while(t--){
        solve();
    }
}