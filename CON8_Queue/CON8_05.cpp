#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int MOD = 1e9 + 7;

/*
- Đẻ nhánh, push "1" vào queue
- Lần lượt lôi top ra, gán nó cho 0 và 1
*/

vector<string> res;

void Binary(){
    queue<string> q;
    q.push("1");

    for(int i = 0 ; i < 10000 ; i++){
        string top = q.front();
        q.pop();
        res.push_back(top);
        q.push(top + "0");
        q.push(top + "1");
    }
}

void Solve(){
    int n;
    cin >> n;
    for(int i = 00 ; i < n ; i++){
        cout << res[i] << " ";
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Binary();

    int t;
    cin >> t;
    while(t--){
        Solve();
    }
}