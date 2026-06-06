#include <bits/stdc++.h>

using namespace std;

/*
    Biểu diễn P/Q = 1/X + ...
    Ta sẽ tìm ra 1 thằng 1/X lớn nhất sao cho 
        1/X <= P/Q
    <=> X >= Q/P và được làm tròn lớn
    Vdu X >= 7/5 = 1.4 => X = 2 (X = q/p + 1)
    Sau khi tính được x, tính phần dư còn lại bằng cách trừ
    P/Q - 1/X, tiếp tục quá trình
    P/Q - 1/X = P.X - Q / Q.X
*/

#define ll long long
const int MOD = 1e9 + 7;

void Solve(){
    ll p, q;
    cin >> p >> q;

    while(true){
        // Neu mẫu chia hết cho tử => end (1/3, 2/4)
        if(q % p == 0){
            cout << "1/" << q / p << endl;
            break;
        }

        ll x = q / p + 1;
        cout << "1/" << x << " + ";
        
        p = p * x - q;
        q = q * x;
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