#include <bits/stdc++.h>

using namespace std;

bool visited[1005];
vector<int> adj[1005];
int trace[1005];

void BFS(int u){
    queue<int> q;
    q.push(u);
    visited[u] = true;

    while(! q.empty()){
        int top = q.front();
        q.pop();
        for(int v : adj[top]){
            if(! visited[v]){
                visited[v] = true;
                trace[v] = top;
                q.push(v);
            }
        }
    }
}

void Solve(){
    int n, m, s, t;
    cin >> n >> m >> s >> t;

    for(int i = 0 ; i < 1005 ; i++){
        if(! adj[i].empty())
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

    BFS(s);

    if(visited[t]){
        vector<int> path;
        int curr = t;

        while(curr != s){
            path.push_back(curr);
            curr = trace[curr];
        }

        path.push_back(s);

        reverse(path.begin(), path.end());
        
        for(int x : path){
            cout << x << " ";
        }
        cout << "\n";
    } else {
        cout << "-1\n";
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