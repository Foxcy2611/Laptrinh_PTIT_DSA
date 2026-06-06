#include <bits/stdc++.h>

#define ll long long

using namespace std;

void Solve(){
    int n;
    cin >> n;

    vector<long long> v1(n);
    vector<long long> v2(n);

    for(ll &c : v1){
        cin >> c;
    }

    for(ll &x : v2){
        cin >> x;
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end(), greater<long long>());

    ll res = 0;

    for(int i = 0 ; i < n ; i++){
        res += v1[i] * v2[i];
    }

    cout << res << endl;
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