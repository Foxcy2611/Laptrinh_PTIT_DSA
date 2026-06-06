#include <bits/stdc++.h>

using namespace std;

int C[1005][1005];
#define MOD 1000000007

void nCk(){
    for(int i = 0 ; i <= 1000 ; i++){
        for(int j = 0 ; j <= i ; j++){
            if(j == 0 || i == j){
                C[i][j] = 1;
            } else {
                C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
                C[i][j] %= MOD;
            }
        }
    }
}

void Solve(){
    int n, k;
    cin >> n >> k;
    
    cout << C[n][k] << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    nCk();

    int t;
    cin >> t;
    while(t--){
        Solve();
    }
}