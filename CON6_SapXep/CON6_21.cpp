#include <bits/stdc++.h>

using namespace std;

map<int, int> mp;

bool cmp(int a, int b){
    if(mp[a] != mp[b]){
        return mp[a] > mp[b];
    }
    return a < b;
}

void solve(void){
    int n;
    cin >> n;
    vector<int> a(n);
    mp.clear();
    
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
        mp[a[i]]++;
    }

    sort(a.begin(), a.end(), cmp);

    for(int x : a){
        cout << x << " ";
    }
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}