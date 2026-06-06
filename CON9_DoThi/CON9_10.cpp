#include <bits/stdc++.h>

using namespace std;

vector<int> adj[1005];
bool visited[1005];
int trace[1005];

void DFS(int u){
    visited[u] = true;

    for(int v : adj[u]){
        if(!visited[v]){
            trace[v] = u; 
            DFS(v);
        }
    }
}

void Solve(){
    int n, m, s, t;
    cin >> n >> m >> s >> t; 

    for(int i = 0 ; i < 1005 ; i++){
        adj[i].clear();
    }
    memset(visited, false, sizeof(visited));
    memset(trace, 0, sizeof(trace));

    for(int i = 1 ; i <= m ; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    DFS(s);

    if(visited[t]){
        vector<int> path;
        int current = t;
        
        while(current != s){
            path.push_back(current);
            current = trace[current];
        }
        path.push_back(s); 
        
        reverse(path.begin(), path.end());
        
        for(int x : path){
            cout << x << " ";
        }
    } else {
        cout << -1; 
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
    return 0;
}