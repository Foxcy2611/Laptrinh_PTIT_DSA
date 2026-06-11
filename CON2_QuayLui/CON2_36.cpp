#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int num[5];
bool found;

void Try(int i, int current_val) {
    if (found) return;
    
    // Nếu đã đặt xong 4 toán tử (đến số cuối cùng)
    if (i == 5) {
        if (current_val == 23) found = true;
        return;
    }

    // Thử 3 phép toán: cộng, trừ, nhân
    Try(i + 1, current_val + num[i]);
    Try(i + 1, current_val - num[i]);
    Try(i + 1, current_val * num[i]);
}

void solve() {
    for (int i = 0; i < 5; i++) cin >> num[i];
    
    // Sắp xếp để next_permutation duyệt từ nhỏ đến lớn
    sort(num, num + 5);
    
    found = false;
    do {
        // Bắt đầu với số đầu tiên, rồi gọi đệ quy thử các toán tử cho 4 số còn lại
        Try(1, num[0]);
        if (found) break;
    } while (next_permutation(num, num + 5));

    if (found) cout << "YES" << "\n";
    else cout << "NO" << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}