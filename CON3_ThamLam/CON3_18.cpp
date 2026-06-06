#include <bits/stdc++.h>

/*
    - Tham lam
    - Chỉ 2 số 4, 7 (Số may mắn)
    => CHọn số nhỏ nhất có tổng các chữ số = n

    - Số lượng chữ số phải ít 
    => Số lượng số 7 phải nhiều
    - Các chữ số bên trái phải bé 
    - Ta có: 4x + 7y = n
    + x sẽ phải nhỏ nhất, chạy từ 1, 2, 3
    => y
*/

using namespace std;

#define ll long long
const int MOD = 1e9 + 7;

void Solve(){
    int n;
    cin >> n;

    for(int x = 0 ; x * 4 <= n ; x++){
        if((n - 4 * x) % 7 == 0){
            int y = (n - 4 * x) / 7;

            cout << string(x, '4') << string(y, '7') << "\n";
            return;
        }
    }

    cout << "-1\n";
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