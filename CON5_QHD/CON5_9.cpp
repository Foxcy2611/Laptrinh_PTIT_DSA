#include <bits/stdc++.h>

using namespace std;

/*
    dp[i][j] la số có i chữ số, tổng bằng j

    vì phần đầu ko đc có số 0, chia làm 2 phần
    + p1: phần thân là các số từ 0 -> 9
    + p2: phần đầu là chữ số từ 1 -> 9, ghép với thân

    dp[0][0] = 1, tất cả  = 0
    - Truy hồi: Giả sử số dp kết thúc là số d (0 -> 9)
    + Số sẽ có phần đầu gồm i - 1 chữ số
    + Tổng tất cả sẽ là j - d
    => Để tạo ra 1 cấu hình cho dp[i][j], thì cần tìm cấu hình cho dp[i - 1][j - d];
    Vì d là từ 0 -> 9, duyệt đủ 9 bước
*/

#define MOD 1000000007

void Solve(){
    int n, k;
    cin >> n >> k;

    if(k < 1 || k > 9 * n){
        cout << 0 << endl;
        return;
    }

    vector<vector<long long>> dp(n, vector<long long>(k + 1, 0));

    dp[0][0] = 1;

    for(int i = 1 ; i < n ; i++){ // Độ dài đuôi (Khong tính phần đầu p2)
        for(int j = 0 ; j <= k ; j++){
            for(int d = 0 ; d <= 9 ; d++){
                if(j >= d){
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - d]) % MOD;
                }
            }
        }
    }

    long long ans = 0;
    
    for (int first_digit = 1; first_digit <= 9; ++first_digit) {
        if (k >= first_digit) {
            ans = (ans + dp[n - 1][k - first_digit]) % MOD;
        }
    }

    cout << ans << "\n";
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