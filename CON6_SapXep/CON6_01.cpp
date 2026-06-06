#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
///////////////// 0/10
void Solve(){
    int n;
    cin >> n;
    
    vector<long long> a(n);
    for(long long &x : a){
        cin >> x;
    }

    sort(a.begin(), a.end());
    int l = 0, r = n - 1;
    for(int i = 0 ; i < n ; i++){
        if(i > 0) cout << " ";
        if(i % 2 == 0){
            cout << a[r--];
        } else {
            cout << a[l++];
        }
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if(cin >> t){
        while(t--){
            Solve();
        }
    }
    return 0;
}