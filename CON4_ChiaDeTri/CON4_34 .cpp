#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int MOD = 1e9 + 7;

/*
Với i là chỉ số
x^2 . x^3 = x^5

*/

void Solve(){
    int m, n;
    cin >> m >> n;
    
    vector<int> p(m);
    for (int i = 0; i < m; i++) {
        cin >> p[i];
    }
    
    vector<int> q(n);
    for (int i = 0; i < n; i++) {
        cin >> q[i];
    }
    
    vector<int> r(m + n - 1, 0);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            r[i + j] += p[i] * q[j];
        }
    }
    
    for (int i = 0; i < m + n - 1; i++) {
        cout << r[i] << " ";
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