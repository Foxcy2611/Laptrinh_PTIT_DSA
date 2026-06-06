#include <bits/stdc++.h>

using namespace std;

void Tkiem(void){
    int n, k;
    cin >> n >> k;
    vector<int> v(n);

    for(int i = 0 ; i < n ; i++){
        cin >> v[i];
    }

    int i;
    long long j, ans = 0;
    sort(v.begin(), v.end());
    for(i = 0 ; i < n ; i++){
        auto it = lower_bound(v.begin() + i + 1, v.end(), v[i] + k);
        j = it - (v.begin() + i + 1);
        ans += j;
    }
    cout << ans << endl;
}

int main(){
    int t; 
    cin >> t;
    while(t--){
        Tkiem();
    }
}