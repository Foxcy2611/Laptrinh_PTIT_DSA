#include <bits/stdc++.h>

/*
    - Tìm số nhỏ nhất có D chữ số và tổng các chữ số là S

    - Quy tắc: Giả sử abcd
    + Đặt hàng a là 1
    + Khi này S còn lại là S - 1
    + Duyệt từ phải qua trái, đặt luôn là 9 (d = 9)
    + Khi này tổng còn lại là SS = S - 1 - 9
    -> Nếu SS > 9, tiếp tục đặt c, b là 9
    -> Nếu SS <= 9, thì lấy phần dư còn lại đặt

    + Tất nhiên, nếu 1 chữ số max = 9, nên nếu S > 9 * D => Không khả thi

    2
    9 2
    20 3

    18
    299
*/

using namespace std;

#define ll long long
const int MOD = 1e9 + 7;

void Solve(){
    int s, d;
    cin >> s >> d;
    
    if(d * 9 < s){
        cout << "-1\n";
        return;
    } else if(s == 0){
        if(d == 1) cout << "0\n";
        else if (d > 1){
            cout << "-1\n";
            return;
        }
    }

    vector<int> a(d);
    s--;

    for(int i = d - 1 ; i >= 1 ; i--){
        if(s > 9){
            a[i] = 9;
            s -= 9;
        } else {
            a[i] = s;
            s = 0;
        }
    }

    a[0] = s + 1;

    for(int x : a){
        cout << x;
    }
    cout << "\n";
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