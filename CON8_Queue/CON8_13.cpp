#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int MOD = 1e9 + 7;


vector<int> res;

void Pre_Setup(){
    res.push_back(0);

    queue<string> q;
    for(char i = '1' ; i <= '5' ; i++){
        q.push(string(1, i));
    }

    while(! q.empty()){
        string s = q.front();
        q.pop();

        int val = stoi(s);
        if(val < 100000) res.push_back(val);

        if(s.length() < 5){
            for(char c = '0' ; c <= '5' ; c++){
                if(s.find(c) == string::npos){ // ko tim thay
                    q.push(s + c);
                }
            }
        }
    }
    sort(res.begin(), res.end());
}

void Solve(){
    int l, r;
    cin >> l >> r;

    auto upper = upper_bound(res.begin(), res.end(), r);
    auto lower = lower_bound(res.begin(), res.end(), l);

    cout << upper - lower << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Pre_Setup();

    int t;
    cin >> t;
    while(t--){
        Solve();
    }
}