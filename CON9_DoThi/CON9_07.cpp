#include <bits/stdc++.h>

// 2/10 ??????????????

using namespace std;

vector<int> adj[1005];
bool visited[1005];

void DFS(int u){
    visited[u] = true;
    cout << u << " ";

    for(int v : adj[u]){
        if(! visited[v]){
            DFS(v);
        }
    }
}

void Solve(){
    int n, m, u;
    cin >> n >> m >> u;

    for(int i = 0 ; i < 1005 ; i++){
        adj[i].clear();
    }
    memset(visited, false, sizeof(visited));

    for(int i = 1 ; i <= m ; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }

    DFS(u);

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