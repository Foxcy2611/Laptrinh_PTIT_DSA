#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int MOD = 1e9 + 7;

/*
N = 123
R = 321
=> N^R % 1e9+7
*/

ll sd(ll n){
    ll r = 0;

    while(n > 0){
        r = r * 10 + n % 10;
        n /= 10;
    }

    return r;
}

ll binpow(ll n, ll r){
    ll res = 1;
    n %= MOD;

    while (r > 0){
        if(r % 2 == 1){
            res = (res * n) % MOD;
        }
        n = (n * n) % MOD;
        r /= 2;
    }
    return res;
}

void Solve(){
    ll n;
    cin >> n;

    ll r = sd(n);

    cout << binpow(n, r) << "\n";
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