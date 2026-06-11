#include <bits/stdc++.h>

using namespace std;

int m, n;
int a[105][105];
int cnt;

void Try(int i, int j){
    if(i >= m || j >= n){
        return;
    }
    if(i == m - 1 && j == n - 1){
        cnt++;
    }

    Try(i + 1, j);
    Try(i, j + 1);
}

void Solve(){
    cin >> m >> n;

    cnt = 0;

    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> a[i][j];
        }
    }

    Try(0, 0);

    cout << cnt << "\n";
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