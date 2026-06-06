#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int MOD = 1e9 + 7;

/*
G(1) = A (Độ dài = 1)
G(2) = B (Độ dài = 1)
G(3) = G(1) + G(2) = AB (Độ dài = 2)
G(4) = G(2) + G(3) = BAB (Độ dài = 3)
G(5) = G(3) + G(4) = ABBAB (Độ dài = 5)
G(6) = G(4) + G(5) = BAB ABBAB (Do dai = 8)
6 4 => A
*/

ll f[93];

void Init(){
    f[1] = 1;
    f[2] = 1;
    for(int i = 3 ; i <= 92 ; i++){
        f[i] = f[i - 1] + f[i - 2];
    }
}

char findChar(int n, ll i){
    if(n == 1) return 'A';
    if(n == 2) return 'B';

    if(i <= f[n - 2]){
        return findChar(n - 2, i);
    } else {
        return findChar(n - 1, i - f[n - 2]);
    }
}

void Solve(){
    int n;
    ll i;
    cin >> n >> i;

    cout << findChar(n, i) << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Init();

    int t;
    cin >> t;
    while(t--){
        Solve();
    }
}