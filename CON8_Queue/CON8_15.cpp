#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int MOD = 1e9 + 7;

int a[1005][1005];
int dist[1005][1005];
int n, m;

void XuLy(){
    memset(dist, -1, sizeof(dist));
    queue<pair<int, int>> q;
    q.push({0, 0});
    dist[0][0] = 0;

    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        if(i == n - 1 && j == m - 1){
            cout << dist[i][j] << "\n";
            return;
        }

        int idx = a[i][j];
        if(idx == 0) continue;

        if(i + idx < n && dist[i + idx][j] == -1){
            dist[i + idx][j] = dist[i][j] + 1;            
            q.push({i + idx, j});
        }

        if(j + idx < m && dist[i][j + idx] == -1){
            dist[i][j + idx] = dist[i][j] + 1;            
            q.push({i, j + idx});
        }
    }
    cout << "-1\n";
}

void Solve(){
    cin >> n >> m;
    
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> a[i][j];
        }
    }

    XuLy();
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