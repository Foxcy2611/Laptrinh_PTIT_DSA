#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int MOD = 1e9 + 7;

void Solve(){
    string s;
    cin >> s;

    int max_len = 0;
    stack<int> st;
    st.push(-1);

    for(int i = 0 ; i < s.length() ; i++){
        if(s[i] == '('){
            st.push(i);
        } else {
            st.pop();

            if(st.empty()){
                st.push(i);
            } else {
                max_len = max(max_len, i - st.top());
            }
        }
    }

    cout << max_len << "\n";
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