#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1000000007;

long long binPow(long long N, long long K) {
    long long res = 1; 
    N = N % MOD;      
    
    while (K > 0) {
        if (K % 2 == 1) {
            res = (res * N) % MOD;
        }
        N = (N * N) % MOD;
        K /= 2;
    }
    
    return res;
}

void Solve() {
    long long N, K;
    cin >> N >> K;
    cout << binPow(N, K) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (cin >> T) {
        while (T--) {
            Solve();
        }
    }
    return 0;
}