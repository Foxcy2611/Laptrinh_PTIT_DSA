#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int c[20][20];          // Ma trận chi phí
int visited[20];        // Đánh dấu đã đi
int ans = 1e9;          // Lưu chi phí tối ưu nhất
int min_edge = 1e9;     // Tìm cạnh nhỏ nhất để cắt tỉa
int current_cost = 0;

void Try(int current_city, int count) {
    // Nếu đã đi hết các thành phố, quay về thành phố 1
    if (count == n) {
        ans = min(ans, current_cost + c[current_city][1]);
        return;
    }

    // Thử đi đến các thành phố khác
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            // Cắt tỉa: Nếu chi phí hiện tại + chi phí nhỏ nhất có thể > ans thì dừng
            if (current_cost + c[current_city][i] + (n - count) * min_edge < ans) {
                visited[i] = 1;
                current_cost += c[current_city][i];
                
                Try(i, count + 1);
                
                // Quay lui
                visited[i] = 0;
                current_cost -= c[current_city][i];
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> c[i][j];
            if (i != j) min_edge = min(min_edge, c[i][j]);
        }
    }

    visited[1] = 1; // Xuất phát từ thành phố 1
    Try(1, 1);

    cout << ans << endl;
    return 0;
}