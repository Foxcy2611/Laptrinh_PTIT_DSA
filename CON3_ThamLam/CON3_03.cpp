#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long
const int MOD = 1e9 + 7;

void Solve(){
    int n;
    cin >> n;

    vector<int> vt(n);

    for(int &x : vt){
        cin >> x;    
    }

    sort(vt.begin(), vt.end());

    long long max_sum = 0;
    for(int i = 0 ; i < n ; i++){
        long long sum = (vt[i] * i) % MOD;
        max_sum = (max_sum + sum) % MOD;
    }

    cout << max_sum << endl;
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