#include <bits/stdc++.h>

using namespace std;

// 1 cạnh đi tối đa 1 lần
// => Nhưng 1 đỉnh có thể đi qua nhiều lần
// => DFS + Backtrack
// Sử dụng mảng, mỗi lần đi qua 1 cặp cạnh, loại bỏ nó (i,j = 0)

int n, m;
int a[25][25];
int max_len;

void DFS(int u, int len){
    max_len = max(max_len, len);
    for(int v = 0 ; v < n ; v++){
        if(a[u][v] == 1){
            a[u][v] = 0;
            a[v][u] = 0;

            DFS(v, len + 1);

            a[u][v] = 1;
            a[v][u] = 1;            
        }
    }
}

void Solve(){
    cin >> n >> m;

    memset(a, 0, sizeof(a));
    max_len = 0;

    for(int i = 0 ; i < m ; i++){
        int x, y;
        cin >> x >> y;
        a[x][y] = 1;
        a[y][x] = 1;
    }

    for(int i = 0 ; i < n ; i++){
        DFS(i, 0);
    }

    cout << max_len << "\n";
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