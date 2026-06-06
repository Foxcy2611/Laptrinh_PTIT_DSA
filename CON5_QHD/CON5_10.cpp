#include <bits/stdc++.h>

using namespace std;

/*
    Goi dp[i][j] la khoang cach tu 1,1 den i, j
    Muon den vi tri i, j ; can nhin lai 3 vi tri trc do
*/

#define MOD 1000000000

void Solve(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n + 1, vector<int>(m + 1));

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            cin >> a[i][j];
        }
    }

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, MOD));

    dp[1][1] = a[1][1];

    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= m ; ++j){
            if(i == 1 && j == 1) continue;

            dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + a[i][j];
        }
    }

    cout << dp[n][m] << endl;
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