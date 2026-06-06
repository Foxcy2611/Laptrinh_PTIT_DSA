#include <bits/stdc++.h>

using namespace std;

bool visited[1005];
vector<int> adj[1005];
int tplt[1005];

void DFS(int u, int stt){
    visited[u] = true;
    tplt[u] = stt;

    for(int v : adj[u]){
        if(! visited[v]){
            DFS(v, stt);
        }
    }
}

void Solve(){
    int n, m;
    cin >> n >> m;

    for(int i = 0 ; i < 1005 ; i++){
        if(! adj[i].empty())
            adj[i].clear();
    }
    memset(visited, false, sizeof(visited));
    memset(tplt, 0, sizeof(tplt));

    for(int i = 1 ; i <= m ; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int stt = 1;
    for(int i = 1 ; i <= n ; i++){
        if(!visited[i]){
            DFS(i, stt);
            stt++;
        }
    }
    int r;
    cin >> r;
    while(r--){
        int s, t;
        cin >> s >> t;

        if(tplt[s] == tplt[t]){
            cout << "YES\n";
        } else {
            cout << "NO\n";
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