#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int MOD = 1e9 + 7;

void Solve(){
    int n, k;
    cin >> n >> k;
    
    map<int, int> mp;
    int dem = 0;

    for(int i = 0 ; i < n ; i++){
        int x;
        cin >> x;
        
        dem += mp[k - x];

        mp[x]++;
    }
    cout << dem << "\n";
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