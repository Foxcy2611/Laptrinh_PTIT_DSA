#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int MOD = 1e9 + 7;

void Solve(){
    int n;
    cin >> n;
    
    vector<int> v(n);
    for(int &x : v) cin >> x;

    for(int i = 0 ; i < n ; i++){
        bool is_swap = false;
        for(int j = 0 ; j < n - 1 ; j++){
            if(v[j] > v[j + 1]){
                swap(v[j], v[j + 1]);
                is_swap = true;
            }
        }
        if(is_swap == false){
            break;
        }

        cout << "Buoc " << i + 1 << ": ";
        for(int x : v) cout << x << " ";
        cout << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while(t--){
            Solve();
        }
    }
    return 0;
}