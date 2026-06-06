#include <bits/stdc++.h>
using namespace std;

vector<int> adj[205];
bool visited[205];
vector<int> ans;

void BFS(int u){
    queue<int> q;
    q.push(u);
    visited[u]=true;

    while(!q.empty()){
        int v=q.front();
        q.pop();

        ans.push_back(v);

        for(int x: adj[v]){
            if(!visited[x]){
                visited[x]=true;
                q.push(x);
            }
        }
    }
}

void Solve(){
    int n,m,u;
    cin>>n>>m>>u;

    for(int i=1;i<=n;i++){
        adj[i].clear();
        visited[i]=false;
    }

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    ans.clear();

    BFS(u);

    for(int i=0;i<ans.size();i++){
        if(i) cout<<" ";
        cout<<ans[i];
    }
    cout<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin>>T;

    while(T--){
        Solve();
    }
}