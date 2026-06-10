#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int MOD = 1e9 + 7;

/*
- Sử dụng queue, lý thuyết module và mảng đánh dấu số dư
=> Tìm số nhỏ nhất chỉ chứa 0 và 1 chia hết cho N
*/

void Solve(){
    int n;
    cin >> n;
    // Chuoi BDN hien tai ; so du
    queue<pair<string, int>> q;
    // Mang danh dau so du
    vector<bool> visited(n, false);
    
    visited[1 % n] = true;
    q.push({"1", 1 % n});

    while(! q.empty()){
        string s = q.front().first;
        int mod = q.front().second;
        q.pop();

        if(mod == 0){
            cout << s << "\n";
            return;
        }

        int mod0 = (mod * 10) % n;
        if(! visited[mod0]){
            visited[mod0] = true;
            q.push({s + "0", mod0});
        }

        int mod1 = (mod * 10 + 1) % n;
        if(! visited[mod1]){
            visited[mod1] = true;
            q.push({s + "1", mod1});
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