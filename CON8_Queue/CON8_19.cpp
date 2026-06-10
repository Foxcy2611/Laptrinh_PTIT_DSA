#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

/*
Xem lai
*/

struct Point {
    int z, y, x;
    int dist;
};

int dz[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};
int dx[] = {0, 0, 0, 0, 1, -1};

void solve() {
    int A, B, C;
    cin >> A >> B >> C;

    vector<string> grid[A];
    Point start, end;

    // Đọc ma trận 3D
    for (int i = 0; i < A; ++i) {
        for (int j = 0; j < B; ++j) {
            string row;
            cin >> row;
            grid[i].push_back(row);
            
            // Tìm điểm xuất phát S và đích E
            for (int k = 0; k < C; ++k) {
                if (row[k] == 'S') start = {i, j, k, 0};
                if (row[k] == 'E') end = {i, j, k, 0};
            }
        }
    }

    // Thiết lập BFS
    queue<Point> q;
    q.push(start);
    
    // Mảng 3D đánh dấu những đỉnh đã thăm để tránh quay vòng
    vector<vector<vector<bool>>> visited(A, vector<vector<bool>>(B, vector<bool>(C, false)));
    visited[start.z][start.y][start.x] = true;

    while (!q.empty()) {
        Point p = q.front();
        q.pop();

        // Nếu chạm đích
        if (p.z == end.z && p.y == end.y && p.x == end.x) {
            cout << p.dist << "\n";
            return;
        }

        // Thử di chuyển theo 6 hướng
        for (int i = 0; i < 6; ++i) {
            int nz = p.z + dz[i];
            int ny = p.y + dy[i];
            int nx = p.x + dx[i];

            // Kiểm tra điều kiện: trong biên, chưa được thăm, và không phải vật cản
            if (nz >= 0 && nz < A && ny >= 0 && ny < B && nx >= 0 && nx < C) {
                if (!visited[nz][ny][nx] && grid[nz][ny][nx] != '#') {
                    visited[nz][ny][nx] = true;
                    q.push({nz, ny, nx, p.dist + 1});
                }
            }
        }
    }
    
    // Phần chữ bị khuất ở ảnh khả năng cao yêu cầu in -1 nếu không thể đến đích
    cout << "-1\n"; 
}

int main() {
    // Tối ưu I/O trong C++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}