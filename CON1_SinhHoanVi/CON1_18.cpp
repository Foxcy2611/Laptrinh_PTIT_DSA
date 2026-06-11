#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Sắp xếp mảng tiền tăng dần
// Khởi tạo biến vô cực
// Tại mỗi bc đệ quy, nếu số tờ đã dùng + số tờ cần thiết thêm >= min
// => Bỏ và dừng ngay
#define ll long long

int n;
long long S;
vector<long long> t;
int min_notes; // Kỷ lục số tờ tiền ít nhất

// i: Vị trí tờ tiền đang xét
// curr_sum: Tổng tiền đã nhặt
// cnt_note: Số tờ tiền đã dùng
void Try(int i, ll curr_sum, int cnt_note){
    if(curr_sum > S || cnt_note >= min_notes){
        return;
    }

    if(curr_sum == S){
        min_notes = min(min_notes, cnt_note);
        return;
    }
    // Neu da xet het to tien ma ko du
    if(i >= n) return;

    if(cnt_note + (S - curr_sum) / t[i] >= min_notes){
        return;
    }

    Try(i + 1, curr_sum + t[i], cnt_note + 1);

    Try(i + 1, curr_sum, cnt_note);
}

void Solve(){
    cin >> n >> S;
    t.resize(n);

    for(int i = 0 ; i < n ; i++){
        cin >> t[i];
    }

    sort(t.begin(), t.end());
    min_notes = 1e9;

    Try(0, 0, 0);

    if(min_notes == 1e9) cout << -1 << "\n";
    else cout << min_notes << "\n";
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
    Solve();
    }
    
}