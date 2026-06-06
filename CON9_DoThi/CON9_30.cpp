#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

/*
- Chu trình là điểm đầu trùng điểm cuối

- Nếu là đồ thị vô hướng
=> Dùng mảng màu kiểm tra và tt DFS
+ Nếu color[v] = 0: Chưa kiểm tra, đi tiếp (Gọi đệ quy)
+ Nếu color[v] = 1: Đỉnh này là 1 tổ tiên của u, phát hiện chu trình
+ Nếu color[v] = 2: Đỉnh này thuộc nhánh khác (TP liên thông khác) đã được thăm

- Nếu là đồ thị có hướng
=> Có 1 chu trình khi tại mọi đỉnh
    Số lượng cạnh vào = Số lượng cạnh ra
*/
void Solve(){
    int n, m;
    cin >> n >> m;
    
    vector<int> in_degree(n + 1, 0);
    vector<int> out_degree(n + 1, 0);

    for(int i = 1 ; i <= m ; i++){
        int x, y;
        cin >> x >> y;
        out_degree[x]++;
        in_degree[y]++;
    }

    bool is_Euler = true;
    for(int i = 1 ; i <= n ; i++){
        if(in_degree[i] != out_degree[i]){
            is_Euler = false;
            break;
        }
    }

    if(is_Euler){
        cout << "1\n";
    } else {
        cout << "0\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        Solve();
    }
    
    return 0;
}