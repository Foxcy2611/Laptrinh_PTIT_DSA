#include <bits/stdc++.h>

using namespace std;

int n, k;
int a[25];
vector<int> curr;
vector<vector<int>> result;

void Try(int idx, int sum){
    if(sum == k){
        result.push_back(curr);
        return;
    }

    if(idx == n || sum > k){
        return;
    }

    for(int i = idx ; i < n ; i++){
        curr.push_back(a[i]);
        Try(i + 1, sum + a[i]);
        curr.pop_back();
    }
}

void Solve(){
    cin >> n >> k;
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }

    sort(a, a + n);
    result.clear();
    curr.clear();

    Try(0, 0);
    if(result.empty()){
        cout << "-1\n";
    } else {
        for(int i = 0 ; i < result.size() ; i++){
            cout << "[";
            for(int j = 0 ; j < result[i].size() ; j++){
                cout << result[i][j];
                (j == result[i].size() - 1) ? cout << "" : cout << " "; 
            }
            cout << "] ";
        }
        cout << "\n";
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--){
        Solve();
    }
}