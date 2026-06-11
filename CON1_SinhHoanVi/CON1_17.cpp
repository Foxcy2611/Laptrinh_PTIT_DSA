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
#define ll long long

void Solve() {
    int n;
    cin >> n;

    queue<ll> q;
    q.push(9);

    while(! q.empty()){
        ll top = q.front();
        q.pop();

        if(top % n == 0){
            cout << top << "\n";
            return;
        } else {
            if(top > 1e18) continue;
            q.push(top * 10);
            q.push(top * 10 + 9);
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