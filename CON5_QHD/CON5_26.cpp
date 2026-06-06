#include <bits/stdc++.h>

#define ll long long

using namespace std;

/*
    dp[j] = true voi j la tong khoi luong co the cho
    dp[j] = false ko the

    voi moi con bo khoi luong w, thi khoi luong con lai la j - w
    kiem tra dp[j - w] = true thi cong them con bo nay
    Duyet j tu C -> w
    
*/

void Solve(){
    int c, n;
    cin >> c >> n;

    vector<int> w(n);
    for(int i = 0 ; i < n ; i++){
        cin >> w[i];
    }

    vector<bool> dp(c + 1, false);
    dp[0] = true;

    for(int i = 0 ; i < n ; i++){
        for(int j = c ; j >= w[i] ; j--){
            if(dp[j - w[i]] == true){
                dp[j] = true;
            }
        }
    }

    for(int j = c ; j >= 0 ; j--){
        if(dp[j] == true){
            cout << j << endl;
            return;
        }
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