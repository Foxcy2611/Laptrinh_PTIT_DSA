#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int MOD = 1e9 + 7;



void Solve(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> dsc(n + 1);

    for(int i = 1 ; i <= m ; i++){
        int x, y;
        cin >> x >> y;
        dsc[x].push_back(y);
    }

    for(int i = 1 ; i <= n ; i++){
        sort(dsc[i].begin(), dsc[i].end());

        cout << i << ": ";

        for(int x : dsc[i]){
            cout << x << " ";
        }
        cout << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        Solve();
    }
}