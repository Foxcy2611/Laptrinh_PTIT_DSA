#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int MOD = 1e9 + 7;

void Solve(){
    int n;
    cin >> n;
 
    queue<pair<int, int>> q;
    unordered_set<int> visited;

    q.push({n, 0});
    visited.insert(n);

    while(! q.empty()){
        int val = q.front().first;
        int step = q.front().second;
        q.pop();

        if(val == 1){
            cout << step << "\n";
            return;
        }

        if(val - 1 > 0 && ! visited.count(val - 1)){
            visited.insert(val - 1);
            q.push({val - 1, step + 1});
        }

        for(int i = 2 ; i * i <= val ; i++){
            if(val % i == 0){
                int next_val = val / i;

                if(! visited.count(next_val)){
                    visited.insert(next_val);
                    q.push({next_val, step + 1});
                }
            }
        }
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