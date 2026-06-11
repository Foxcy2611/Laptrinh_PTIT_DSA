#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    int test_num;
    string s;
    // Đọc số thứ tự test và chuỗi số
    cin >> test_num >> s;

    cout << test_num << " ";
    
    // Hàm next_permutation tự động hoán vị chuỗi s thành cấu hình lớn hơn tiếp theo.
    // Nếu có cấu hình tiếp theo, hàm trả về true.
    // Nếu s đã là cấu hình lớn nhất (giảm dần), hàm trả về false.
    if (next_permutation(s.begin(), s.end())) {
        cout << s << "\n";
    } else {
        cout << "BIGGEST\n";
    }
}

int main() {
    // Tối ưu I/O giúp code chạy nhanh hơn
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}