#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int MOD = 1e9 + 7;

/*
- Ý tưởng: Duy trì 1 pair vs 
+ first là s biến đổi
+ second là số lần biến đổi
- Tại mỗi lần lôi ra, biến đổi theo 2 cách
+ -1
+ x2
+ second++
=> Cho đến khi t == frist thì lôi ra first
- Duy trì thêm 1 visited đảm bảo first biến đổi đã được sinh ra rồi

- Bẫy
+ Đảm bảo khi s * 2 < Limit(t) = 10000 và s - 1 > 0
+ Nếu s > t => Để s == t thì chỉ cần s--
=> Cần s-t bước
*/

void Solve(){
    int s, t;
    cin >> s >> t;

    if(s >= t){
        cout << s - t << "\n";
        return;
    }

    queue<pair<int, int>> q;
    vector<bool> visited(10010, false);

    q.push({s, 0});
    visited[s] = true;

    while(! q.empty()){
        int val = q.front().first;
        int step = q.front().second;
        q.pop();

        if(val == t){
            cout << step << "\n";
            return;
        }

        if(val - 1 > 0 && ! visited[val - 1]){
            visited[val - 1] = true;
            q.push({val - 1, step + 1});
        }
        if(val * 2 <= 10005 && ! visited[val * 2] ){
            visited[val * 2] = true;
            q.push({val * 2, step + 1});
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        Solve();
    }
}