#include <bits/stdc++.h>

#define ll long long

using namespace std;

int basic_Binary_Search(vector<int>& a, int n, int target){
    int l = 0;
    int r = n - 1;

    while(l <= r){
        int m = l + (r - l) / 2;

        if(a[m] == target) return m;
        else if(a[m] > target) r = m - 1;
        else if(a[m] < target) l = m + 1;
    }

    return -1;
}

void Solve(){
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }

    int idx = basic_Binary_Search(a, n, k);

    if(idx >= 0){
        cout << idx + 1 << endl;
    } else {
        cout << "NO" << endl;
    }
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