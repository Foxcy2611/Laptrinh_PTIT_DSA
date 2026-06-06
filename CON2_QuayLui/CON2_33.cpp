#include <iostream>

using namespace std;

int n;
int ans = 0;

// Khai báo các mảng đánh dấu (kích thước n tối đa là 10, nên chéo tối đa là ~20)
bool cot[20], cheo1[40], cheo2[40];

void Try(int i) {
    // Base case: Nếu đã lọt qua được hàng n (tức là đang ở hàng n + 1)
    // Nghĩa là đã đặt thành công n quân hậu hợp lệ
    if (i > n) {
        ans++;
        return;
    }

    // Thử đặt quân hậu ở hàng i vào các cột j từ 1 đến n
    for (int j = 1; j <= n; j++) {
        // Chỉ duyệt nếu cột và 2 đường chéo đi qua ô (i, j) đều đang trống
        if (!cot[j] && !cheo1[i - j + n] && !cheo2[i + j]) {
            
            // 1. ĐẶT HẬU: Đánh dấu chiếm đóng cột và 2 đường chéo
            cot[j] = true;
            cheo1[i - j + n] = true;
            cheo2[i + j] = true;

            // 2. ĐỆ QUY: Đi xuống hàng tiếp theo để đặt quân hậu tiếp theo
            Try(i + 1);

            // 3. QUAY LUI (BACKTRACK): Nhấc quân hậu ra, trả lại trạng thái trống
            // để chuẩn bị thử nhét quân hậu vào cột j + 1
            cot[j] = false;
            cheo1[i - j + n] = false;
            cheo2[i + j] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    ans = 0;

    Try(1); 
        
    cout << ans << "\n";
    
    return 0;
}