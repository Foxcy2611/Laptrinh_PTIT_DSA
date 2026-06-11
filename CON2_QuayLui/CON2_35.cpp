#include <iostream>

using namespace std;

int n, k, s;
int ans;

// 1. So bat dau xet
// 2. So ptu da chon
// 3. Tong hien tai
void Try(int idx, int cnt, int sum){
    if(cnt == k){
        if(sum == s){
            ans++;
        }
        return;
    }
    
    if(sum > s || idx > n) return;

    for(int i = idx ; i <= n ; i++){
        Try(i + 1, cnt + 1, sum + i);
    }
}

int main(){


    while (cin >> n >> k >> s && (n != 0 || k != 0 || s != 0)) {
        ans = 0;
        Try(1, 0, 0);
        cout << ans << "\n";
    }
    return 0;
}