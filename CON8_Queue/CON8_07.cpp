#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int MOD = 1e9 + 7;

/*
- Đẻ nhánh, push "1" vào queue
- Lần lượt lôi top ra, gán nó cho 0 và 1
*/

vector<int> res;

void Binary(){
    queue<int> q;
    q.push(1);

    for(int i = 0 ; i < 10000 ; i++){
        int top = q.front();
        q.pop();
        res.push_back(top);
        q.push(top * 10);
        q.push(top * 10 + 1);
    }
}

void Solve(){
    int n;
    cin >> n;
    int sum = 0;
    int i = 0;

    while(res[i] <= n){
        sum++;
        i++;
    }
    
    cout << sum << "\n";
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