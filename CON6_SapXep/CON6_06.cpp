#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int MOD = 1e9 + 7;

void Solve(){
    int n;
    cin >> n;

    int d[3] = {0, 0, 0};

    for(int i = 0 ; i < n ; i++){
        int x;
        cin >> x;
        d[x]++;
    }
    for(int i = 0 ; i < 3 ; i++){
        while(d[i] > 0){
            cout << i << " ";
            d[i]--;
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