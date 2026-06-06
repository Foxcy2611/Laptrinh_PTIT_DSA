#include <iostream>
#include <vector>

using namespace std;

void Solve() {
    int n, x;
    cin >> n >> x;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int left = 0, right = n - 1;
    int ans = -1; // Biến lưu kết quả, mặc định -1 nếu không tìm thấy
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        // Nếu tìm thấy X
        if (a[mid] == x) {
            ans = mid + 1; // +1 vì vị trí đếm từ 1 (không phải index từ 0)
            break;
        }
        
        // Kiểm tra xem nửa TRÁI có đang được sắp xếp chuẩn không
        if (a[left] <= a[mid]) {
            // Xem X có nằm trong khoảng nửa trái này không
            if (a[left] <= x && x < a[mid]) {
                right = mid - 1; // Tìm sang trái
            } else {
                left = mid + 1;  // Tìm sang phải
            }
        } 
        // Nếu nửa TRÁI bị gãy, thì chắc chắn nửa PHẢI đang được sắp xếp chuẩn
        else {
            // Xem X có nằm trong khoảng nửa phải này không
            if (a[mid] < x && x <= a[right]) {
                left = mid + 1;  // Tìm sang phải
            } else {
                right = mid - 1; // Tìm sang trái
            }
        }
    }
    
    cout << ans << "\n";
}

int main() {
    // Tối ưu hóa I/O cực kỳ quan trọng vì N có thể lên tới 10^7
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