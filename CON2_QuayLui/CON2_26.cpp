#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int MOD = 1e9 + 7;

string max_str;

void Solve(string s, int k, int pos){
    if(s > max_str){
        max_str = s;
    }

    if(pos == s.length() || k == 0){
        return;
    }

    char max_char = s[pos];
    for(int i = pos + 1 ; i < s.length() ; i++){
        if(s[i] > max_char){
            max_char = s[i];
        }
    }

    if(max_char > s[pos]){
        for(int i = pos + 1 ; i < s.length() ; i++){
            if(max_char == s[i]){
                swap(s[i], s[pos]);
                Solve(s, k - 1, pos + 1);
                swap(s[i], s[pos]);
            }
        }
    } else {
        Solve(s, k, pos + 1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int k;
        string s;
        cin >> k >> s;
        
        max_str = s;

        Solve(s, k, 0);

        cout << max_str << endl;
    }
}