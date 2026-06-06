#include <iostream>

using namespace std;

/*
Bước 1 (N=1): [1]
Bước 2 (N=2): [1, 2, 1]
Bước 3 (N=3): [1, 2, 1, 3, 1, 2, 1]
Bước 4 (N=4): [1, 2, 1, 3, 1, 2, 1, 4, 1, 2, 1, 3, 1, 2, 1]

=> Vị trí chính giữa = 2^(n-1)
*/

// Hàm đệ quy tìm số thứ K trong dãy bước N
long long findKth(int n, long long k) {
    // Tọa độ chính giữa của dãy bước N là 2^(N-1)
    // Dùng toán tử dịch bit (1LL << (n-1)) để tính 2^(N-1) siêu nhanh
    long long mid = 1LL << (n - 1); 
    
    if (k == mid) {
        return n; // Nằm trúng điểm giữa
    }
    
    if (k < mid) {
        // Nằm ở nửa trái -> Tìm tiếp trong dãy n-1
        return findKth(n - 1, k);
    } else {
        // Nằm ở nửa phải -> Gióng tọa độ k về bên nửa trái và tìm trong dãy n-1
        return findKth(n - 1, k - mid);
    }
}

void Solve() {
    int n;
    long long k;
    cin >> n >> k;
    
    cout << findKth(n, k) << "\n";
}

int main() {
    // Tối ưu I/O cho C++
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