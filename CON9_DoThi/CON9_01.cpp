#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;
// chịu

void Solve(){
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adj(1005);
    for(int i = 1 ; i <= m ; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i = 1 ; i <= n ; i++){
        sort(adj[i].begin(), adj[i].end());
    }

    for(int i = 1 ; i <= n ; i++){
        cout << i << ":";
        for(int x : adj[i]){
            cout << " " << x;
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