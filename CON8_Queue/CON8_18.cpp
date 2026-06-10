#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int MOD = 1e9 + 7;

const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

/*
ta sẽ tạo queue pair, push tất cả i, j = 2 vào, đếm số ptu = 1 (int cnt)

tại mỗi lần chạy là 1 ngày, sử dụng thuật toán loang tạo mảng i, j từ trc, pop 1 thằng trong queue ra, dùng loang xung quanh nếu == 1 thì up lên 2, push i, j vào, cnt--

cho đến khi loang xung quanh toàn 2 hoặc 0 mà cnt != 0 thì là -1 
*/

void Solve(){
    int R, C;
    cin >> R >> C;

    vector<vector<int>> grid(R, vector<int>(C));
    queue<pair<int, int>> q;
    int cnt = 0;

    for(int i = 0 ; i < R ; i++){
        for(int j = 0 ; j < C ; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 2){
                q.push({i, j});
            } else if(grid[i][j] == 1) {
                cnt++;
            }
        }
    }

    if(cnt == 0){
        cout << 0 << "\n";
        return;
    }

    int days = 0;
    while(! q.empty() && cnt > 0){
        int curr_qu = q.size();
        for(int i = 0 ; i < curr_qu ; ++i){
            pair<int, int> curr = q.front();
            q.pop();

            int x = curr.first;
            int y = curr.second;

            for(int k = 0 ; k < 4 ; k++){
                int nx = x + dx[k];
                int ny = y + dy[k];

                if(nx >= 0 && ny >= 0 && ny < C && nx < R && grid[nx][ny] == 1){
                    grid[nx][ny] = 2;
                    q.push({nx, ny});
                    cnt--;
                }
            }
        }
        days++;
    }

    if(cnt == 0){
        cout << days << "\n";
    } else {
        cout <<"-1\n";
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