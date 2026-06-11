#include <iostream>
#include <vector>

using namespace std;

// CON1_16 - CHỌN SỐ TỪ MA TRẬN VUÔNG CẤP N

int n, k;
int c[15][15];
bool used_col[15];      // Mảng đánh dấu cột đã được sử dụng
int current_choice[15]; // Mảng lưu cấu hình (cột được chọn cho từng hàng)
vector<vector<int>> results; // Lưu trữ các kết quả đúng

void Try(int i, int curr_sum){
    if(i > n){
        if(curr_sum == k){
            vector<int> res;
            for(int j = 1 ; j <= n ; j++){
                res.push_back(current_choice[j]);
            }
            results.push_back(res);
        }
        return;
    }

    for(int j = 1 ; j <= n ; j++){
        if(!used_col[j]){
            used_col[j] = true;
            current_choice[i] = j;
            Try(i + 1, curr_sum + c[i][j]);
            used_col[j] = false;
        }
    }
}

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> c[i][j];
        }
    }

    for (int i = 1; i <= n; i++) used_col[i] = false;
    results.clear();

    Try(1, 0);

    cout << results.size() << "\n";
    for (auto& res : results) {
        for (int x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}