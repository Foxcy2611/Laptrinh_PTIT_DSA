#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int MOD = 1e9 + 7;

void Solve(){
    int n;
    cin >> n;

    bool dd[10] = {false};

    for(int i = 0 ; i < n ; i++){
        ll x;
        cin >> x;

        if(x == 0){
            dd[0] = true;
        } else {
            while(x > 0){
                int digit = x % 10;
                dd[digit] = true;
                x /= 10;
            }
        }
    }

    for(int i = 0 ; i < 10 ; i++){
        if(dd[i]) cout << i << " ";
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