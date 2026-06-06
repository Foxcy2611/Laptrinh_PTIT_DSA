#include <bits/stdc++.h>

/*
    - Với 1 sâu ký tự s, có thể sắp xếp lại sao cho các ký tự giống nhau không thể liền kề

    - Bản chất, việc nhóm có đông ký tự xuất hiện nhất để tách nó ra (d)
    + Xếp ở vị trí như 0 2 4 6
    + Thì nếu hàng ghế có L chỗ, thì cần s = [int L+1 / 2] chỗ cho chúng
    - Nếu việc chia trên mà vẫn còn chỗ (d <= s), thì việc còn lại là sắp xếp các ký tự còn lại là đủ
*/

using namespace std;

#define ll long long
const int MOD = 1e9 + 7;

void Solve(){
    string s;
    cin >> s;

    map<char, int> mp;
    for(char c : s){
        mp[c]++;
    }

    int max_length = 0;
    int L = s.length();
    for(auto it : mp){
        if(it.second > max_length){
            max_length = it.second;
        }
    }

    if(max_length <= (L + 1) / 2){
        cout << "1\n";
    } else {
        cout << "-1\n";
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