#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int MOD = 1e9 + 7;

int n, x;
vector<int> a;
vector<vector<int>> res;
vector<int> curr;

void Try(int i, int sum){
    if(sum == x){
        res.push_back(curr);
        return;
    }
    for(int j = i ; j < n ; j++){
        if(a[j] + sum <= x){
            curr.push_back(a[j]);
            
            Try(j, sum + a[j]);

            curr.pop_back();
        } else {
            break;
        }
    }
}

void Solve(){
    cin >> n >> x;
    a.resize(n);
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }

    res.clear();
    curr.clear();

    sort(a.begin(), a.end());

    a.erase(unique(a.begin(), a.end()), a.end());
    n = a.size();

    Try(0, 0);

    if(res.empty()){
        cout << "-1\n";
    } else {
        for(int i = 0 ; i < res.size() ; i++){
            cout << "[";
            for(int j = 0 ; j < res[i].size() ; j++){
                cout << res[i][j];
                if(j < res[i].size() - 1) cout << " ";
            }
            cout << "]";
        }
        cout << "\n";
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