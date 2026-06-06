#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int MOD = 1e9 + 7;
/////////////// 5/10
void Solve(){
    int n, m;
    cin >> n >> m;

    set<int> hop, X, Y;
    for(int i = 1 ; i <= n ; i++){
        int x;
        cin >> x;
        hop.insert(x);
        X.insert(x);
    }
    for(int i = 1 ; i <= m ; i++){
        int x;
        cin >> x;
        hop.insert(x);
        Y.insert(x);
    }
    for(auto it : hop){
        cout << it << " ";
    }
    cout << "\n";
    for(auto it : X){
        if(Y.count(it) != 0){
            cout << it << " ";
        }
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