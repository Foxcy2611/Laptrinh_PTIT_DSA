#include <iostream>
#include <queue>
#include <string>
#include <vector>

/*
    - Tìm số nhỏ nhất chứa 0 và 9 sao cho chia hết cho n

    - Lập hàng đợi gồm char và int
    - Nhét "9" vào hàng đợi
    - Lôi đầu hàng đợi ra
    + Xem nó chia hết không
    -> Không thì ta thêm lần lượt các nhánh là "0" và "9" (9 -> 90, 09)
    -> Lưu phần dư của phép chia vào .second

    Tính chất đồng dư
    (số mới) % n = ((số cũ % n) * 10 + c) % n
    c = 0 || 9
*/

using namespace std;

void Solve() {
    int n;
    cin >> n;

    queue<pair<string, int>> q;
    
    vector<bool> visited(n, false);

    q.push({"9", 9 % n});
    visited[9 % n] = true;

    while (!q.empty()) {
        string s = q.front().first;
        int mod = q.front().second;
        q.pop();

        if (mod == 0) {
            cout << s << "\n";
            return;
        }

        int next_mod_0 = (mod * 10) % n;
        if (!visited[next_mod_0]) {
            visited[next_mod_0] = true;
            q.push({s + "0", next_mod_0});
        }

        int next_mod_9 = (mod * 10 + 9) % n;
        if (!visited[next_mod_9]) {
            visited[next_mod_9] = true;
            q.push({s + "9", next_mod_9});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            Solve();
        }
    }
    return 0;
}