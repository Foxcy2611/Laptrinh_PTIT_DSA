#include <bits/stdc++.h>

using namespace std;

/*
    dp[i][j] là chiều dài cạnh của hình vuông
    lớn nhất (toàn số 1) có góc 
    dưới cùng bên phải nằm đúng tại ô (i, j)

    Goi i, j la o duoi cung ben phai
    neu a[i][j] = 0 => ko co hinh vuong nao
    neu a[i][j] = 1 => kiem tra cac o tren no (ô trên, ô trái, ô chéo trái trên)
    => Độ dài sẽ bị giới hạn bởi 3 ô đó
    dp[i]$dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
*/

void Solve(){
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> dp(n, vector<int>(m, 0));

    int max_rec = 0;

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> a[i][j];
            if(a[i][j] == 1){
                if(i == 0 || j == 0){
                    dp[i][j] = 1;
                
                } else {
                    dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                }
            }
            max_rec = max(max_rec, dp[i][j]);
        }
    }

    cout << max_rec << endl;
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