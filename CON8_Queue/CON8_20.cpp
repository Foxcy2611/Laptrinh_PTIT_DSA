#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

// --- CÁC PHÉP XOAY THUẬN (CHIỀU KIM ĐỒNG HỒ) CHO BFS XUÔI ---
string left_cw(string s) {
    string res = s;
    res[0] = s[3]; res[1] = s[0]; res[5] = s[1];
    res[8] = s[5]; res[7] = s[8]; res[3] = s[7];
    return res;
}

string right_cw(string s) {
    string res = s;
    res[1] = s[4]; res[2] = s[1]; res[6] = s[2];
    res[9] = s[6]; res[8] = s[9]; res[4] = s[8];
    return res;
}

// --- CÁC PHÉP XOAY NGƯỢC (NGƯỢC CHIỀU KIM ĐỒNG HỒ) CHO BFS NGƯỢC ---
string left_ccw(string s) {
    string res = s;
    res[3] = s[0]; res[0] = s[1]; res[1] = s[5];
    res[5] = s[8]; res[8] = s[7]; res[7] = s[3];
    return res;
}

string right_ccw(string s) {
    string res = s;
    res[4] = s[1]; res[1] = s[2]; res[2] = s[6];
    res[6] = s[9]; res[9] = s[8]; res[8] = s[4];
    return res;
}

void solve() {
    string start = "";
    for (int i = 0; i < 10; ++i) {
        char c;
        cin >> c;
        start += c;
    }
    
    string target = "1238004765"; // Trạng thái ban đầu chuẩn
    
    if (start == target) {
        cout << 0 << "\n";
        return;
    }
    
    // Bản đồ lưu khoảng cách từ trạng thái bắt đầu
    unordered_map<string, int> distF;
    queue<string> qF;
    
    qF.push(start);
    distF[start] = 0;
    
    // BFS Xuôi: Duyệt tối đa 14 bước
    while (!qF.empty()) {
        string u = qF.front();
        qF.pop();
        
        if (distF[u] >= 14) continue;
        
        string v1 = left_cw(u);
        if (distF.find(v1) == distF.end()) {
            distF[v1] = distF[u] + 1;
            qF.push(v1);
        }
        
        string v2 = right_cw(u);
        if (distF.find(v2) == distF.end()) {
            distF[v2] = distF[u] + 1;
            qF.push(v2);
        }
    }
    
    // Bản đồ lưu khoảng cách từ trạng thái đích (quay ngược về)
    unordered_map<string, int> distB;
    queue<string> qB;
    
    qB.push(target);
    distB[target] = 0;
    
    int ans = 1e9;
    if (distF.find(target) != distF.end()) {
        ans = distF[target];
    }
    
    while (!qB.empty()) {
        string u = qB.front();
        qB.pop();
        
        // Nếu số bước đi ngược vượt quá giới hạn thiết lập, dừng lại
        if (distB[u] >= 16) break;
        
        string v1 = left_ccw(u);
        if (distB.find(v1) == distB.end()) {
            distB[v1] = distB[u] + 1;
            if (distF.find(v1) != distF.end()) {
                ans = min(ans, distB[v1] + distF[v1]);
            }
            qB.push(v1);
        }
        
        string v2 = right_ccw(u);
        if (distB.find(v2) == distB.end()) {
            distB[v2] = distB[u] + 1;
            if (distF.find(v2) != distF.end()) {
                ans = min(ans, distB[v2] + distF[v2]);
            }
            qB.push(v2);
        }
    }
    
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
    solve();
    }
    return 0;
}