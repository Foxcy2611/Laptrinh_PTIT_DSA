#include <bits/stdc++.h>

using namespace std;

void Solve(){
    int n;
    cin >> n;

    vector<vector<int>> results(n);

    for(int i = 1 ; i <= n ; i++){
        int x;
        cin >> x;
        results[0].push_back(x);
    }
    
    for(int i = 1 ; i < n ; i++){
        for(int j = 1 ; j < results[i - 1].size() ; j++){
            results[i].push_back(results[i - 1][j] + results[i - 1][j - 1]);
        }
    }

    for(int i = n - 1 ; i >= 0 ; i--){
        cout << "[";
        for(int j = 0 ; j < results[i].size() ; j++){
            cout << results[i][j];
            if(j < results[i].size() - 1){
                cout << " ";
            }
        }
        cout << "] ";
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