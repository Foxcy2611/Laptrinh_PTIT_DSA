#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int MOD = 1e9 + 7;

void Solve(){
    int n;
    cin >> n;
    
    set<int> se;
    for(int i = 1 ; i <= n ; i++){
        int x;
        cin >> x;
        se.insert(x);
    }

    int minn = *se.begin();
    int maxx = *se.rbegin();

    int miss = (maxx - minn + 1) - se.size();
    cout << miss << "\n";
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